#ifndef LIN_CP_H
#define LIN_CP_H

#include "derivative.h"
#include "hardware.h"
#include "pilot.h"
#include "lin.h"
#include "lin_cfg.h"
#include "types.h"

#define LIN_DETECT_TIMEOUT 2000

typedef enum {StartNull, RunNull, StartVer, RunVer, StartInit, RunInit, StartOp, RunOp, 
      StartErr, RunErr, StartSleep, RunSleep} SCHEDULE_PICKER;

typedef enum {continueOnLIN, startLIN, stopLIN} SCHEDULE_PICKER_EVENTS;

enum {FiftyHz = 1, SixtyHz, FiftyOrSixtyHz};
      
void InitializeLINCP(void);
void DetermineLINCPState(uint8_t ch, SCHEDULE_PICKER_EVENTS SchedulePickerMessage);

void PrintLinCPStatus(uint8_t ch);

#define EMPTY
#define LV(t,rw,it,v,a) t##_##rw##_##it##_##v(a)
#define LF(tc,it,v) l_flg_##tc##_##it##_##v##_flag()
#define LS(it,sch,a) l_sch_set(it,it##_##sch,a)
#define LW(it,t,v,a) if (it) {LV(t,wr,LI1,v,a);} else {LV(t,wr,LI0,v,a);}
#define LR(it,t,v) ( (it) ? LV(t,rd,LI1,v,EMPTY): LV(t,rd,LI0,v,EMPTY) )
#define LFT(it,v) ( (it) ? LF(tst,LI1,v): LF(tst,LI0,v) )
#define LFC(it,v) if (it) {LF(clr,LI1,v);} else {LF(clr,LI0,v);}
#define LSS(it,sch,a) if (it) {LS(LI1,sch,a);} else {LS(LI0,sch,a);}


#define  RTI_TICKS_PER_LINCP_LOOP  20             //  How often the LIN-CP state machine is serviced

//9.3 -- Table 16
#define  T_SESTART     RTI_TICKS_PER_SECOND/2     //  9.4.1.3                       SE max time to start LIN Schedule
#define  T_EVSTART     1*RTI_TICKS_PER_SECOND     //  9.4.1.4                       EV max time to start responding
#define  T_PWM         1*RTI_TICKS_PER_SECOND     //  9.5.4.1                       SE max time to establish LIN-CP
#define  T_EVCLOSE     3*RTI_TICKS_PER_SECOND     //  9.7.2.3                       EV max time to close S2
#define  T_SECLOSE     3*RTI_TICKS_PER_SECOND     //  9.7.2.4                       SE max time to close the Contactor
#define  T_SEADAPT     10*RTI_TICKS_PER_SECOND    //  9.7.3.2                       SE max time to adapt SeAvailableCurrents to external limit (for example, energy management system)
#define  T_EVADAPT     5*RTI_TICKS_PER_SECOND     //  9.7.3.5                       EV max time to adapt load current to SeAvailableCurrents
#define  T_SEOPEN      3*RTI_TICKS_PER_SECOND     //  9.7.4.2   10.7.2.2            SE max time to open the Contactor
#define  T_RAMPDOWN    6*RTI_TICKS_PER_SECOND     //  9.7.5.1   10.2.2.1            SE min time to wait before interrupting supply
#define  T_EVOPEN      3*RTI_TICKS_PER_SECOND     //  9.7.5.2   9.8.2.1   10.7.1.1  EV max time to open S2
#define  T_UNLOCK      3*RTI_TICKS_PER_SECOND     //  9.8.1.1   9.8.2.3             EV max time to unlock Inlet
#define  T_VER         5*RTI_TICKS_PER_SECOND     //  10.3.1.1  10.3.2.1            SE and EV timeout before Version selection fails
#define  T_INIT        5*RTI_TICKS_PER_SECOND     //  10.4.1.1  10.4.2.1            SE and EV timeout before initialization fails
#define  T_NOLIN       2*RTI_TICKS_PER_SECOND     //  10.7.1.1  10.7.1.2            EV min time to wait before opening S2, no LIN Headers
                                                  //  10.7.2.1  10.7.2.2            SE min time to wait before opening the Contactor, no LIN Responses
#define  T_SE_12       RTI_TICKS_PER_SECOND/10    //  10.8.4.1                      SE max time to open the Contactor, SE detects CP Level 12

#define  L_SESTART     T_SESTART /RTI_TICKS_PER_LINCP_LOOP
#define  L_EVSTART     T_EVSTART /RTI_TICKS_PER_LINCP_LOOP
#define  L_PWM         T_PWM     /RTI_TICKS_PER_LINCP_LOOP
#define  L_EVCLOSE     T_EVCLOSE /RTI_TICKS_PER_LINCP_LOOP
#define  L_SECLOSE     T_SECLOSE /RTI_TICKS_PER_LINCP_LOOP
#define  L_SEADAPT     T_SEADAPT /RTI_TICKS_PER_LINCP_LOOP
#define  L_EVADAPT     T_EVADAPT /RTI_TICKS_PER_LINCP_LOOP
#define  L_SEOPEN      T_SEOPEN  /RTI_TICKS_PER_LINCP_LOOP
#define  L_RAMPDOWN    T_RAMPDOWN/RTI_TICKS_PER_LINCP_LOOP
#define  L_EVOPEN      T_EVOPEN  /RTI_TICKS_PER_LINCP_LOOP
#define  L_UNLOCK      T_UNLOCK  /RTI_TICKS_PER_LINCP_LOOP
#define  L_VER         T_VER     /RTI_TICKS_PER_LINCP_LOOP
#define  L_INIT        T_INIT    /RTI_TICKS_PER_LINCP_LOOP
#define  L_NOLIN       T_NOLIN   /RTI_TICKS_PER_LINCP_LOOP
#define  L_SE_12       T_SE_12   /RTI_TICKS_PER_LINCP_LOOP

#endif
