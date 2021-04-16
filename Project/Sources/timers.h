#ifndef _TIMERS_H
#define _TIMERS_H

//Analog sample timeout timer
#define TIMER_1_PERIOD  31200 //24 MHz * 1.3 ms = 31200
#define timer_1_reset() TC1 = (TCNT + TIMER_1_PERIOD) & 0xFFFF

//LIN timer
#define TIMER_6_PERIOD 60000 //24 MHz * 2.5 ms = 60000

#endif
