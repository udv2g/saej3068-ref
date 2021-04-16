#include <hidef.h>      /* common defines and macros */
#include "derivative.h" /* derivative-specific definitions */
#include "scheduler.h"
#include "sci.h"
#include "globals.h"
#include "hardware.h"

#define DELAY_TABLE_SIZE 25

typedef struct _DelayItem {
  sfp func;
  void *argptr;
  uint32_t time_remaining;
  uint8_t flags;
} DelayItem;

static DelayItem delay_table[DELAY_TABLE_SIZE] = {{NULL, NULL, 0, 0}}; //extra pair of brackets to make modern gcc happy

static uint16_t main_loop_count;

typedef enum {
  // Flag to cancel a timer
  TIMER_FLAG_CANCELED = 0x20,
  // Flag to indicate that we are working on an entry in the delay table
  TIMER_FLAG_LOCKED = 0x40,
  // Flag to mark an entry in the delay table as allocated
  TIMER_FLAG_ALLOCATED = 0x80,
} timer_flag_t;

/* The number of milliseconds elapsed since the last time the delay
 * table was processed. */
static uint32_t _delay_counter_millis_elapsed = 0;

/* A flag that is set to one whenever the delay counter overflows
 * FIXME: We can probably use an assembly instruction to speed this up
 */
static uint8_t _delay_counter_overflowed_p = 0;

/* /\* A lock to acquire before changing _delay_counter_millis_elapsed *\/ */
/* static uint8_t _delay_counter_lock = 0; */

/**
 * Function to lock a delay table entry before it is processed
 */
static uint8_t _lock_entry(uint8_t *flagsptr) {
  uint8_t locked_p = 0;
#ifdef S12X
  asm {
    ldx   flagsptr;
    btas  0, x, TIMER_FLAG_LOCKED;
    bne   skipa;
    movb  #1, locked_p;
  skipa:
  }
#else
  uint8_t interruptsDisabled;

  interruptsDisabled = check_interrupts_disabled();
  if (!interruptsDisabled) DisableInterrupts;

  if (!(*flagsptr & TIMER_FLAG_LOCKED)) {
    *flagsptr |= TIMER_FLAG_LOCKED;
    locked_p = 1;
  }

  if (!interruptsDisabled) EnableInterrupts;
#endif
  return locked_p;
}

/**
 * Function to unlock a delay table entry after it is processed
 */
static void _unlock_entry(uint8_t *flagsptr) {
  *flagsptr &= (~TIMER_FLAG_LOCKED) & 0xFF;
}

/**
 * Function to allocate an entry in the delay table
 */
static uint8_t _allocate_entry(uint8_t *flagsptr) {
  uint8_t allocated_p = 0;
#ifdef S12X
  asm {
    ldx   flagsptr; //load the address of the flag into x
    btas  0,x, TIMER_FLAG_ALLOCATED; //test and set address at x (offset 0)
    bne   skipb; //bne branches if spot is being used (using Z flag)
    movb  #1, allocated_p; //I got one!  don't get cocky
  skipb:
  }
#else
  uint8_t interruptsDisabled;

  interruptsDisabled = check_interrupts_disabled();
  if (!interruptsDisabled) DisableInterrupts;

  if (!(*flagsptr & TIMER_FLAG_ALLOCATED)) {
    *flagsptr |= TIMER_FLAG_ALLOCATED;
    allocated_p = 1;
  }

  if (!interruptsDisabled) EnableInterrupts;
#endif
  return allocated_p;
}

/**
 * Function to cancel an entry in the delay table
 */
static void _cancel_entry(uint8_t *flagsptr) {
  asm {
    ldx   flagsptr;
    bset   0, x, TIMER_FLAG_CANCELED; //single cycle - cancel this entry
                                    // if this is currently executing it will not run again
                                    // even if it tries to reschedule itself
  }
}

// uint32_t invalid_fn = 0;

/**
 * Function to add a function to the delay table
 */
static void _add_to_delay_table(uint32_t time, sfp funcptr, void *argptr) {
  uint8_t i;
  uint8_t allocated_p = 0;
  uint8_t locked_p    = 0;
  uint8_t *flagsptr;

  //search for the next available spot
  for (i = 0; i < DELAY_TABLE_SIZE; i++) {
    // Check if the entry is in use
    if ((delay_table[i].flags & TIMER_FLAG_ALLOCATED) == 0) {
      //we use this to precalculate the address of the pointer in c land
      //its messy to do the line below in assembly
      flagsptr = &(delay_table[i].flags);
      locked_p = _lock_entry(flagsptr);
      if (locked_p) {
        allocated_p = _allocate_entry(flagsptr);
        if (allocated_p) {
          delay_table[i].func           = funcptr;
          delay_table[i].argptr         = argptr;
          delay_table[i].time_remaining = time;
          _unlock_entry(flagsptr);
          return;
        } else {
          _unlock_entry(flagsptr);
        }
      }
    }
  }
  // invalid_fn = ((int32_t)funcptr);

  // else oh noes! list is full!
  //FIXME: return a value indicating failure, this is kind of important function
  PrintConsoleString("Schedule Overflow\r\n", 0);
  return; //we failed
}

// remove item from table
// not a public function
// used during init and by disbatcher only
void clear_delay_item(DelayItem *d) {
  d->func           = NULL;
  d->argptr         = NULL;
  d->time_remaining = 0;
  d->flags          = 0; //set busy and used to 0
                         //do this last
}

// clear out all items from table
// call this before int are enabled
// not a public function
void init_delay_table(void) {
  uint8_t i = 0;
  for (i = 0; i < DELAY_TABLE_SIZE; i++) {
    clear_delay_item(&delay_table[i]);
  }
}

/**
 * Add scheduled item to the table if it wasn't previously scheduled!
 * If the item was previously scheduled, this entry simply waits
 * for the timer to run its course
 */
void schedule_if_unscheduled(uint32_t time, sfp funcptr, void *argptr) {
  uint8_t i = 0;

  // First check if this function has already been scheduled.
  // If yes, simply return!
  // Note: We don't care if this function is currently being executed,
  //       we just want it to have been run at some point in time.
  for (i = 0; i < DELAY_TABLE_SIZE; i++) {
    // If the current entry is allocated and not canceled!
    if ((delay_table[i].flags & TIMER_FLAG_ALLOCATED) &&
        ((delay_table[i].flags & TIMER_FLAG_CANCELED) == 0)) {
      if (delay_table[i].func == funcptr) {
        return;
      }
    }
  }

  // Ok, now we need to schedule this function.
  _add_to_delay_table(time, funcptr, argptr);
}

/*
// add scheduled item to table; time is in milliseconds
void schedule_and_reset(uint32_t time, sfp funcptr, void* argptr){
  //uint8_t i = 0;

  //FIXME kinda hacky but I don't want to schedule the same thing twice
  //this basically makes the cancelled bit high and cleans it up
  //next time we go through the list
  unschedule(funcptr);
  _add_to_delay_table (time, funcptr, argptr);
}
*/

// add scheduled item to table; time is in milliseconds
void schedule_and_reset(uint32_t time, sfp funcptr, void *argptr) {
  uint8_t locked_p;
  uint8_t *flagsptr;
  uint8_t i    = 0;
  DelayItem *d = NULL;
  for (i = 0; i < DELAY_TABLE_SIZE; i++) {
    // If the current entry is allocated and not canceled!
    if ((delay_table[i].flags & TIMER_FLAG_ALLOCATED) &&
        ((delay_table[i].flags & TIMER_FLAG_CANCELED) == 0)) {
      if (delay_table[i].func == funcptr) {
        d = &(delay_table[i]);
        //PrintConsoleString("#",0);
      }
    }
  }
  if (d == NULL) {
    _add_to_delay_table(time, funcptr, argptr);
  } else {
    flagsptr = &(d->flags);
    locked_p = _lock_entry(flagsptr);
    //PrintConsoleString("$",0);
    if (locked_p) {
      d->time_remaining = time;
      //PrintConsoleString("%",0);
      _unlock_entry(flagsptr);
    } else {
      //the thing is locked?? what do we do
      PrintConsoleString("schedule reset failure\r\n", 0);
    }
  }
}

// search table for instances of function ptr and remove all scheduled items
void unschedule(sfp funcptr) {
  uint8_t i;
  uint8_t *flagsptr;

  //we don't need a lock because its the only func that sets this bit
  for (i = 0; i < DELAY_TABLE_SIZE; i++) {
    if (delay_table[i].func == funcptr) {
      flagsptr = &(delay_table[i].flags);
      _cancel_entry(flagsptr);
    }
  }
}

void update_delay_count(void) { //does this actually do what it is supposed to?  FIXME
  uint32_t millis_till_overflow = 0xFFFFFFFFL - _delay_counter_millis_elapsed;

  if (millis_till_overflow > RTI_MILLISECONDS) {
    _delay_counter_millis_elapsed += RTI_MILLISECONDS;
  } else {
    _delay_counter_millis_elapsed = RTI_MILLISECONDS - millis_till_overflow;
    _delay_counter_overflowed_p   = 1;
  }
}

/* void update_delay_count(void) { */
/*     uint8_t locked_p; */
/*     for (;;) { // Loop until we acquire the lock */
/*         locked_p = _lock_entry(&_delay_counter_lock); */
/*         if (locked_p) { */
/*             _delay_counter_millis_elapsed += RTI_MILLISECONDS; */
/*             _unlock_entry(&_delay_counter_lock);  */
/*             return; */
/*         } */
/*     } */
/* } */

uint32_t get_elapsed_time(void) {
  static uint32_t last_read_delay_counter = 0;
  uint32_t millis_elapsed;

  uint8_t interruptsDisabled;

  interruptsDisabled = check_interrupts_disabled();
  if (!interruptsDisabled) DisableInterrupts;

  if (_delay_counter_overflowed_p) {
    millis_elapsed = (0xFFFFFFFFL - last_read_delay_counter) +
                     _delay_counter_millis_elapsed;
    _delay_counter_overflowed_p = 0;
  } else {
    millis_elapsed = _delay_counter_millis_elapsed - //This math must be protected against _delay_counter_millis_elapsed being updated in the middle.
                     last_read_delay_counter;        //Otherwise it may return a large value and trigger most or all of the delay table.
  }                                                  //This wreaks hovoc with timeouts.
  last_read_delay_counter = _delay_counter_millis_elapsed;

  if (!interruptsDisabled) EnableInterrupts;

  return millis_elapsed;
}

uint32_t GetCurrentRTITime(void) {
  return _delay_counter_millis_elapsed;
}

/* uint32_t get_and_reset_elapsed_time(void) { */
/*     for (;;) { */
/*         locked_p = _lock_entry(&_delay_counter_lock); */
/*         if (locked_p) { */
/*             millis_elapsed = _delay_counter_millis_elapsed; */
/*             _delay_counter_millis_elapsed = 0; */
/*             _unlock_entry(&_delay_counter_lock);  */
/*             return millis_elapsed; */
/*         } */
/*     } */
/* } */

static void _decrement_time_remaining(DelayItem *d, uint32_t millis_elapsed) {
  if (d->flags & TIMER_FLAG_CANCELED) {
    d->time_remaining = 0;
  }

  if (d->time_remaining != 0) { //time left?
    // Decrement time remaining
    if (d->time_remaining <= millis_elapsed) {
      d->time_remaining = 0;
    } else {
      d->time_remaining -= millis_elapsed;
    }
  }
}

static void _process_delay_entry(DelayItem *d) {
  uint8_t locked_p;
  uint32_t resch_time;
  uint8_t *flagsptr;

  if (d->time_remaining == 0) {
    flagsptr = &(d->flags);
    locked_p = _lock_entry(flagsptr);
    if (locked_p &&
        // make sure the function pointer is not null
        (d->func != NULL) &&
        // test it again to make sure the time is actually
        // expired after getting the lock
        (d->time_remaining == 0)) {

      if ((d->flags & TIMER_FLAG_CANCELED) == 0) {
        // Call the function below:
        resch_time = d->func(d->argptr);

        if (resch_time != 0) {
          d->time_remaining = resch_time;
          _unlock_entry(flagsptr);
        } else {
          clear_delay_item(d); //not reschduled
        }
      } else {
        clear_delay_item(d); //already terminiated
      }
    }
  }
}

void process_delay_table(void) {
  uint8_t i;

  // First get the count
  uint32_t millis_elapsed = get_elapsed_time();
  ++main_loop_count;

  if (millis_elapsed > 0) {
    for (i = 0; i < DELAY_TABLE_SIZE; i++) {
      if (delay_table[i].flags & TIMER_FLAG_ALLOCATED) {
        // First decrement the time remaining
        _decrement_time_remaining(&delay_table[i], millis_elapsed);

        // Next check and execute this item if the time is exceeded
        _process_delay_entry(&delay_table[i]);
      }
    }
  }
}

/* // call each time tick */
/* void update_delay_table(void){ */
/*     uint8_t i; */

/*     //decrement the times for the whole list -- */
/*     //do this separately to make sure everything does get decremented */
/*     //this is the only function changes a non-zero entry */
/*     for(i = 0; i<DELAY_TABLE_SIZE; i++){ */
/*         if (delay_table[i].flags & TIMER_FLAG_ALLOCATED) { */
/*             //test if canceled and clear it quicker */
/*             if (delay_table[i].flags & TIMER_FLAG_CANCELED)  { */
/*                 delay_table[i].time_remaining = 0;  */
/*             } */

/*             if (delay_table[i].time_remaining != 0){  //time left? */
/*                 if (delay_table[i].time_remaining <= RTI_MILLISECONDS) */
/*                     delay_table[i].time_remaining = 0; */
/*                 else */
/*                     delay_table[i].time_remaining -= RTI_MILLISECONDS; */
/*             } */
/*         } */
/*     } */

/*     return; //we are done working for now  */
/* } */

/* void process_delay_table(void){ */
/*     uint8_t i; */
/*     uint8_t locked_p; */
/*     uint32_t resch_time; */
/*     uint8_t*  flagsptr;  */

/*     //run functions if time remaining = 0 */
/*     for(i = 0;i<DELAY_TABLE_SIZE;i++) { */
/*         if((delay_table[i].flags & TIMER_FLAG_ALLOCATED) &&  */
/*            (delay_table[i].time_remaining == 0)) { */

/*             flagsptr = &(delay_table[i].flags); */
/*             locked_p = _lock_entry(flagsptr); */
/*             if (locked_p &&  */
/*                 // make sure the function pointer is not null */
/*                 (delay_table[i].func != NULL) &&  */
/*                 // test it again to make sure the time is actually  */
/*                 // expired after getting the lock  */
/*                 (delay_table[i].time_remaining == 0)) { */

/*                 if ((delay_table[i].flags & TIMER_FLAG_CANCELED) == 0) {   */
/*                     // Call the function below: */
/*                     resch_time = delay_table[i].func(delay_table[i].argptr);  */

/*                     if (resch_time != 0) { */
/*                         delay_table[i].time_remaining = resch_time; */
/*                         _unlock_entry(flagsptr); */
/*                     }  */
/*                     else{ */
/*                         clear_delay_item(&delay_table[i]);  //not reschduled   */
/*                         // This will unlock the entry as well */
/*                     } */
/*                 } */
/*                 else{ */
/*                     clear_delay_item(&delay_table[i]);    //already terminiated  */
/*                     // This will unlock the entry as well */
/*                 } */
/*             } */
/*         } */
/*     } */

/*     return; //we are done working for now     */
/* } */