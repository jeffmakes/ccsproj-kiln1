#include "device.h"
#include "lcd.h"
#include "encoder.h"
#include "adc10.h"
#include "triac.h"
#include "thermocouple.h"
#include "control.h"
#include "scheduler.h"
#include <signal.h>

#define MAX_OUTPUT_POWER 7500
#define MIN_OUTPUT_POWER 500

int16_t setpoint = MIN_SETPOINT;

/* Initialises everything. */
void init(void);
void draw_display();
void update_display();
int i = 0;

// HACKY WARNING - the busy wait loop delay() in lcd.c has a manually tweaked value to produce adequate length delays for the HD44780's signals
// Initially when porting the code from GCC to CCS, this value was too short and the LCD was garbled. Note also the optimisation level will impact it.
// Pretty nasty all round - I should be using a proper timing method.

int main( void )
{
  volatile uint32_t time;
  int16_t perror = 0;
  int16_t ierror = 0;
  int16_t kp = 50;
  int16_t ki = 5;
  int32_t outputpower = 500;
  uint16_t itimer = 0;
  uint16_t itimeout = 20;

  WDTCTL = WDTPW | WDTHOLD;       // stop watchdog timer

  init();
  triac_off();
  //  draw_display();  

  while(1)
    {
      //WDTCTL = WDTPW | WDTCNTCL;  // clear watchdog

      for (time=0; time<1000; time++);
      adc10_poll();
      update_display();

      /* proportional error */
      perror = setpoint - (int16_t)thermocouple_temp;

      /* integral error (only compute when output is not saturated, and only infrequently) */
      if ( (itimer++) == itimeout)
	{
	  itimer = 0;
	   if ( (outputpower != MAX_OUTPUT_POWER) && (outputpower != MIN_OUTPUT_POWER) )
	    ierror += perror;
	}
      
      outputpower = (kp * (int32_t)perror) + (ki * (int32_t)ierror);
 
      if (perror < (-20))		/* If temperature is way above setpoint, turn off element. */
	outputpower = MIN_OUTPUT_POWER;
     
      if (outputpower > MAX_OUTPUT_POWER)
	outputpower = MAX_OUTPUT_POWER;
      else if (outputpower < MIN_OUTPUT_POWER)
	outputpower = MIN_OUTPUT_POWER;
	
      triac_set_power(outputpower);
    }
}

void init(void)
{
  /* GPIO: All inputs */
  P1DIR = P2DIR = P3DIR = P4DIR = 0;
  
  /* Use a 8 MHz clock (DCO) */
  DCOCTL = CALDCO_8MHZ;
  BCSCTL1 &= ~0x0f;
  BCSCTL1 |= 
    /*XT2O=0: XT2 is on*/
    /*XTS=0: LFXT1 mode select. 0 -Low frequency mode*/
    DIVA_0 /* ACLK Divider 0: /1 */
    |CALBC1_8MHZ; /* BCSCTL1 Calibration Data for 16MHz */
  
  BCSCTL2 = SELM_0	/* MCLK from DCO */
    /* DIVMx = 0 : No MCLK divider */
    /* SELS = 0: SMCLK from DCO */
    | DIVS_3 /* : Divide SMCLK by 8 */
    /* DCOR = 0 : DCO internal resistor */;
  
  BCSCTL3 = LFXT1S0; /*32768Hz watch crystal */
  
  lcd_init();
  encoder_init();
  adc10_init();
  triac_init();
  scheduler_init();
  //__eint();
  __bis_SR_register(GIE); // Enable all interrupts (Clear GIE in SR)
}


void draw_display()
{
  lcd_cursor_to(0,0);
  lcd_print_string("Setpoint:     C");
  lcd_cursor_to(0,1);
  lcd_print_string("Temp:         C");
  lcd_cursor_to(14,0);
  lcd_send_char(0xdf);
  lcd_cursor_to(14,1);
  lcd_send_char(0xdf);
}

void update_display()
{
  uint16_t minutes = 0;
  
  minutes = ( (ramp_transition_time - seconds)/60 )+1;

  lcd_cursor_to(0,0);		/* Top line... */
  switch (status)
    {
    case MODE_CHOICE_MANUAL:
      lcd_print_string("Choose mode:    ");
      lcd_cursor_to(0,1);
      lcd_print_string(" Manual         ");
      break;
    case MODE_CHOICE_PROFILE:
      lcd_print_string("Choose mode:    ");
      lcd_cursor_to(0,1);
      lcd_print_string(" Profile        ");
      break;
    case PROFILE_WAIT_START:
    case PROFILE_START_COUNTDOWN_SET:      
      lcd_print_string(" Click to start ");
      lcd_cursor_to(0,1);
      lcd_print_string("Delay: ");
      lcd_print_num((profile[0].duration / 60), 3);
      if (profile[0].duration == 60)
	lcd_print_string(" min ");
      else
	lcd_print_string(" mins");
      break;
    case MANUAL_MODE:
      lcd_print_string("Manual mode     ");
      lcd_cursor_to(0,1);		/* Bottom line... */
      lcd_print_string("Set");
      lcd_print_num(setpoint, 4);
      lcd_send_char(0xdf);
      lcd_print_string(" At");
      lcd_print_num(thermocouple_temp, 4);
      lcd_send_char(0xdf);
      break;      
    case PROFILE_START_COUNTDOWN:
      lcd_print_string("  Starting in   ");
      lcd_cursor_to(0,1);
      lcd_print_string("  ");
      lcd_print_num(minutes, 3);
      lcd_print_string(" minute");
      if (minutes != 1)
	lcd_print_string("s");
      lcd_print_string("    ");
      break;      
    case  PROFILE_END:
      lcd_print_string("Profile Complete");
    default:
      lcd_print_num(ramp,1);
      lcd_send_char(':');
      switch(status)
	{
	case RAMP_UP:
	  lcd_print_string("Ramp+ ");
	  break;
	case RAMP_DOWN:
	  lcd_print_string("Ramp- ");
	  break;
	default:
	  lcd_print_string("Hold  ");
	  break;
	}
      lcd_print_num(profile[ramp].end_temp, 3);
      lcd_send_char(0xdf);
      lcd_print_num(minutes, 3);
      lcd_send_char('m');
      lcd_cursor_to(0,1);		/* Bottom line... */
      lcd_print_string("Set");
      lcd_print_num(setpoint, 4);
      lcd_send_char(0xdf);
      lcd_print_string(" At");
      lcd_print_num(thermocouple_temp, 4);
      lcd_send_char(0xdf);
      break;
    }

}
