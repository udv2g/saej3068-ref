#ifndef _SCHEDULER_H
#define _SCHEDULER_H

#include "types.h"

#define RTI_MILLISECONDS 1

//the function pointer
typedef uint32_t (*sfp)(void *);

// Function that adds a function to the delay list and resets the delay
// if it was already scheduled
void schedule_and_reset(uint32_t, sfp, void *);
// Function that adds a function to the delay list if it wasn't previously
// scheduled
void schedule_if_unscheduled(uint32_t, sfp, void *);
//function that should be called every interrupt to run functions
//void update_delay_table(void);
//call this before using the items_list
void init_delay_table(void);
void unschedule(sfp);
void process_delay_table(void);
void update_delay_count(void);

uint32_t GetCurrentRTITime(void);

#endif