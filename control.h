#ifndef __CONTROL_H
#define __CONTROL_H

#include <stdint.h>

#define MAX_SETPOINT 1100   // 1100 deg C is the rating of the thermocouple - the lowest rated component in the kiln. Unfortunately heat treating stainless alloys demands we take it almost to this limit.
#define MIN_SETPOINT 30

extern int16_t setpoint;
#endif
