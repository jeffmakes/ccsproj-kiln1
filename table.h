const uint16_t tempconvert[1024] = 
  { 
    0,
    1,
    2,
    4,
    5,
    6,
    7,
    9,
    10,
    11,
    12,
    13,
    15,
    16,
    17,
    18,
    19,
    21,
    22,
    23,
    24,
    25,
    27,
    28,
    29,
    30,
    31,
    33,
    34,
    35,
    36,
    37,
    39,
    40,
    41,
    42,
    43,
    44,
    46,
    47,
    48,
    49,
    50,
    52,
    53,
    54,
    55,
    56,
    57,
    59,
    60,
    61,
    62,
    63,
    64,
    66,
    67,
    68,
    69,
    70,
    71,
    73,
    74,
    75,
    76,
    77,
    78,
    80,
    81,
    82,
    83,
    84,
    85,
    87,
    88,
    89,
    90,
    91,
    92,
    94,
    95,
    96,
    97,
    98,
    99,
    101,
    102,
    103,
    104,
    105,
    107,
    108,
    109,
    110,
    111,
    112,
    114,
    115,
    116,
    117,
    118,
    120,
    121,
    122,
    123,
    124,
    125,
    127,
    128,
    129,
    130,
    131,
    133,
    134,
    135,
    136,
    137,
    139,
    140,
    141,
    142,
    143,
    145,
    146,
    147,
    148,
    149,
    151,
    152,
    153,
    154,
    155,
    157,
    158,
    159,
    160,
    161,
    163,
    164,
    165,
    166,
    168,
    169,
    170,
    171,
    172,
    174,
    175,
    176,
    177,
    178,
    180,
    181,
    182,
    183,
    185,
    186,
    187,
    188,
    189,
    191,
    192,
    193,
    194,
    195,
    197,
    198,
    199,
    200,
    202,
    203,
    204,
    205,
    206,
    208,
    209,
    210,
    211,
    212,
    214,
    215,
    216,
    217,
    218,
    220,
    221,
    222,
    223,
    224,
    226,
    227,
    228,
    229,
    231,
    232,
    233,
    234,
    235,
    237,
    238,
    239,
    240,
    241,
    243,
    244,
    245,
    246,
    247,
    248,
    250,
    251,
    252,
    253,
    254,
    256,
    257,
    258,
    259,
    260,
    262,
    263,
    264,
    265,
    266,
    268,
    269,
    270,
    271,
    272,
    273,
    275,
    276,
    277,
    278,
    279,
    280,
    282,
    283,
    284,
    285,
    286,
    288,
    289,
    290,
    291,
    292,
    293,
    295,
    296,
    297,
    298,
    299,
    300,
    302,
    303,
    304,
    305,
    306,
    307,
    309,
    310,
    311,
    312,
    313,
    314,
    316,
    317,
    318,
    319,
    320,
    321,
    323,
    324,
    325,
    326,
    327,
    328,
    330,
    331,
    332,
    333,
    334,
    335,
    337,
    338,
    339,
    340,
    341,
    342,
    344,
    345,
    346,
    347,
    348,
    349,
    350,
    352,
    353,
    354,
    355,
    356,
    357,
    359,
    360,
    361,
    362,
    363,
    364,
    365,
    367,
    368,
    369,
    370,
    371,
    372,
    374,
    375,
    376,
    377,
    378,
    379,
    380,
    382,
    383,
    384,
    385,
    386,
    387,
    389,
    390,
    391,
    392,
    393,
    394,
    395,
    397,
    398,
    399,
    400,
    401,
    402,
    404,
    405,
    406,
    407,
    408,
    409,
    410,
    412,
    413,
    414,
    415,
    416,
    417,
    418,
    420,
    421,
    422,
    423,
    424,
    425,
    426,
    428,
    429,
    430,
    431,
    432,
    433,
    434,
    436,
    437,
    438,
    439,
    440,
    441,
    442,
    444,
    445,
    446,
    447,
    448,
    449,
    450,
    452,
    453,
    454,
    455,
    456,
    457,
    458,
    460,
    461,
    462,
    463,
    464,
    465,
    466,
    468,
    469,
    470,
    471,
    472,
    473,
    474,
    476,
    477,
    478,
    479,
    480,
    481,
    482,
    484,
    485,
    486,
    487,
    488,
    489,
    490,
    491,
    493,
    494,
    495,
    496,
    497,
    498,
    499,
    501,
    502,
    503,
    504,
    505,
    506,
    507,
    509,
    510,
    511,
    512,
    513,
    514,
    515,
    517,
    518,
    519,
    520,
    521,
    522,
    523,
    524,
    526,
    527,
    528,
    529,
    530,
    531,
    532,
    534,
    535,
    536,
    537,
    538,
    539,
    540,
    542,
    543,
    544,
    545,
    546,
    547,
    548,
    550,
    551,
    552,
    553,
    554,
    555,
    556,
    557,
    559,
    560,
    561,
    562,
    563,
    564,
    565,
    567,
    568,
    569,
    570,
    571,
    572,
    573,
    575,
    576,
    577,
    578,
    579,
    580,
    581,
    583,
    584,
    585,
    586,
    587,
    588,
    589,
    591,
    592,
    593,
    594,
    595,
    596,
    597,
    599,
    600,
    601,
    602,
    603,
    604,
    605,
    606,
    608,
    609,
    610,
    611,
    612,
    613,
    614,
    616,
    617,
    618,
    619,
    620,
    621,
    622,
    624,
    625,
    626,
    627,
    628,
    629,
    630,
    632,
    633,
    634,
    635,
    636,
    637,
    639,
    640,
    641,
    642,
    643,
    644,
    645,
    647,
    648,
    649,
    650,
    651,
    652,
    653,
    655,
    656,
    657,
    658,
    659,
    660,
    661,
    663,
    664,
    665,
    666,
    667,
    668,
    670,
    671,
    672,
    673,
    674,
    675,
    676,
    678,
    679,
    680,
    681,
    682,
    683,
    685,
    686,
    687,
    688,
    689,
    690,
    691,
    693,
    694,
    695,
    696,
    697,
    698,
    700,
    701,
    702,
    703,
    704,
    705,
    707,
    708,
    709,
    710,
    711,
    712,
    713,
    715,
    716,
    717,
    718,
    719,
    720,
    722,
    723,
    724,
    725,
    726,
    727,
    729,
    730,
    731,
    732,
    733,
    734,
    736,
    737,
    738,
    739,
    740,
    741,
    743,
    744,
    745,
    746,
    747,
    748,
    750,
    751,
    752,
    753,
    754,
    755,
    757,
    758,
    759,
    760,
    761,
    763,
    764,
    765,
    766,
    767,
    768,
    770,
    771,
    772,
    773,
    774,
    775,
    777,
    778,
    779,
    780,
    781,
    783,
    784,
    785,
    786,
    787,
    788,
    790,
    791,
    792,
    793,
    794,
    795,
    797,
    798,
    799,
    800,
    801,
    803,
    804,
    805,
    806,
    807,
    809,
    810,
    811,
    812,
    813,
    814,
    816,
    817,
    818,
    819,
    820,
    822,
    823,
    824,
    825,
    826,
    828,
    829,
    830,
    831,
    832,
    833,
    835,
    836,
    837,
    838,
    839,
    841,
    842,
    843,
    844,
    845,
    847,
    848,
    849,
    850,
    851,
    853,
    854,
    855,
    856,
    857,
    859,
    860,
    861,
    862,
    863,
    865,
    866,
    867,
    868,
    869,
    871,
    872,
    873,
    874,
    875,
    877,
    878,
    879,
    880,
    881,
    883,
    884,
    885,
    886,
    888,
    889,
    890,
    891,
    892,
    894,
    895,
    896,
    897,
    898,
    900,
    901,
    902,
    903,
    904,
    906,
    907,
    908,
    909,
    911,
    912,
    913,
    914,
    915,
    917,
    918,
    919,
    920,
    922,
    923,
    924,
    925,
    926,
    928,
    929,
    930,
    931,
    932,
    934,
    935,
    936,
    937,
    939,
    940,
    941,
    942,
    944,
    945,
    946,
    947,
    948,
    950,
    951,
    952,
    953,
    955,
    956,
    957,
    958,
    959,
    961,
    962,
    963,
    964,
    966,
    967,
    968,
    969,
    971,
    972,
    973,
    974,
    976,
    977,
    978,
    979,
    980,
    982,
    983,
    984,
    985,
    987,
    988,
    989,
    990,
    992,
    993,
    994,
    995,
    997,
    998,
    999,
    1000,
    1002,
    1003,
    1004,
    1005,
    1007,
    1008,
    1009,
    1010,
    1012,
    1013,
    1014,
    1015,
    1017,
    1018,
    1019,
    1020,
    1022,
    1023,
    1024,
    1025,
    1027,
    1028,
    1029,
    1030,
    1032,
    1033,
    1034,
    1035,
    1037,
    1038,
    1039,
    1040,
    1042,
    1043,
    1044,
    1045,
    1047,
    1048,
    1049,
    1050,
    1052,
    1053,
    1054,
    1056,
    1057,
    1058,
    1059,
    1061,
    1062,
    1063,
    1064,
    1066,
    1067,
    1068,
    1069,
    1071,
    1072,
    1073,
    1075,
    1076,
    1077,
    1078,
    1080,
    1081,
    1082,
    1083,
    1085,
    1086,
    1087,
    1089,
    1090,
    1091,
    1092,
    1094,
    1095,
    1096,
    1098,
    1099,
    1100,
    1101,
    1103,
    1104,
    1105,
    1107,
    1108,
    1109,
    1110,
    1112,
    1113,
    1114,
    1116,
    1117,
    1118,
    1119,
    1121,
    1122,
    1123,
    1125,
    1126,
    1127,
    1128,
    1130,
    1131,
    1132,
    1134,
    1135,
    1136,
    1138,
    1139,
    1140,
    1141,
    1143,
    1144,
    1145,
    1147,
    1148,
    1149,
    1151,
    1152,
    1153,
    1154,
    1156,
    1157,
    1158,
    1160,
    1161,
    1162,
    1164,
    1165,
    1166,
    1168,
    1169,
    1170,
    1171,
    1173,
    1174,
    1175,
    1177,
    1178,
    1179,
    1181,
    1182,
    1183,
    1185,
    1186,
    1187,
    1189,
    1190,
    1191,
    1193,
    1194,
    1195,
    1197,
    1198,
    1199,
    1201,
    1202,
    1203,
    1205,
    1206,
    1207,
    1209,
    1210,
    1211,
    1213,
    1214,
    1215,
    1217,
    1218,
    1219,
    1221,
    1222,
  };

