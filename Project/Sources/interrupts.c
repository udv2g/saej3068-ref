#include "derivative.h"
#include "lin.h"
#include "types.h"
#include "globals.h"
#include "sci.h"
#include "timers.h"
#include "hardware.h"
#include "scheduler.h"
#include "pilot.h"
#include "lin-cp.h"
#include "j1939.h"

#pragma CODE_SEG __NEAR_SEG NON_BANKED

static uint8_t timeoutcounterA, timeoutcounterB;

/*******************************************************
 * timebase timer interrupt
 ********************************************************/

interrupt VectorNumber_Vtimer6 void TIM_TIMER6_ISR(void) {
  static l_u8 timebase_counter =0;
  if (timebase_counter>=20){
    timebase_flag = TRUE;
    timebase_counter = 0;
  }
  timebase_counter++;
  /* Clear timer flag */
  TFLG1_C6F = 1;              //clear timer 6 interrupt flag (set bit to clear it because reasons pg. 750)
  /* Reset timer counter */
  TC6   = (TC6 + TIMER_6_PERIOD) &0xFFFF;
}

/*******************************************************
 * Analog sample timeout timer interrupt
 ********************************************************/

interrupt VectorNumber_Vtimer1 void TIM_TIMER1_ISR(void) {
  uint8_t sample;

  if (PILOTA_WAKEUP_INTERRUPT_ENABLE == ON){      //no PWM is detected in an appropriate period
    timeoutcounterA++;
    timeoutcounterA %= 5;
    if (timeoutcounterA == 0 || !InLINState(A)) { //make timeout 5 times longer when in LIN to account for larger gaps.
      //DEBUG4 = ! DEBUG4;
      sample = PilotAReadADC();
      Pilot_Voltage_Filter_Add(A, sample);        //positive and negative the same as signal not changing
      Pilot_Voltage_Neg_Filter_Add(A, sample);

#ifdef EV_CONFIG                                  //set period and duty cycle to "invalid"
      Pilot_Period_Filter_Add(A, (Pilot_Voltage[A] == STATE_E)? 0 : 100);
      Pilot_Duty_Cycle_Filter_Add(A, 0 );
#endif

      PILOTA_WAKEUP_INTERRUPT_ENABLE = OFF;
    }
  }

  if (PILOTB_WAKEUP_INTERRUPT_ENABLE == ON){      //no PWM is detected in an appropriate period
    timeoutcounterB++;
    timeoutcounterB %= 5;
    if (timeoutcounterB == 0 || !InLINState(B)) { //make timeout 5 times longer when in LIN to account for larger gaps.
      sample = PilotBReadADC();
      Pilot_Voltage_Filter_Add(B, sample);          //positive and negative the same as signal not changing
      Pilot_Voltage_Neg_Filter_Add(B, sample);

#ifdef EV_CONFIG                                  //set period and duty cycle to "invalid"
      Pilot_Period_Filter_Add(B, (Pilot_Voltage[B] == STATE_E)? 0 : 100);
      Pilot_Duty_Cycle_Filter_Add(B, 0 );
#endif

      PILOTB_WAKEUP_INTERRUPT_ENABLE = OFF;
    }
  }
  TFLG1_C1F = 1;              //clear timer 1 interrupt flag (set bit to clear it because reasons pg. 750)
  /* Reset timer counter */
  timer_1_reset();
}

/*******************************************************
 * Real Time Interrupt (RTI)
 ********************************************************/

interrupt VectorNumber_Vrti void RTI_ISR(void){
  static uint8_t PilotSample = 0, ProxSample = 0, LINState = 0;

#ifdef EV_CONFIG
  DetermineEvState(A,NO_CODE);
#ifndef CH_A_ONLY
  DetermineEvState(B,NO_CODE);
#endif
  //process_plug_state();
#endif

#ifdef SE_CONFIG
  DetermineEvseState(A, NO_CODE);
#ifndef CH_A_ONLY
  DetermineEvseState(B, NO_CODE);
#endif
#endif

/*********<Sample Pilots**********/
  PilotSample++;
  PilotSample %= 4;

  switch(PilotSample){
    case 0:

      PILOTA_WAKEUP_INTERRUPT_ENABLE = ON;
      PILOTB_WAKEUP_INTERRUPT_ENABLE = OFF;

      PILOTA_WAKEUP_INTERRUPT_POLARITY = ON; //rising edge

      PILOTA_WAKEUP_INTERRUPT_FLAG = 1; //clear flag after enabling it
      PILOTB_WAKEUP_INTERRUPT_FLAG = 1; //clear flag just in case
      //DEBUG1 = 1;

      //PrintConsoleString("A",0);
      timer_1_reset();
      break;

    case 2:
#ifndef CH_A_ONLY
      PILOTA_WAKEUP_INTERRUPT_ENABLE = OFF;
      PILOTB_WAKEUP_INTERRUPT_ENABLE = ON;

      PILOTB_WAKEUP_INTERRUPT_POLARITY = ON; //rising edge

      PILOTB_WAKEUP_INTERRUPT_FLAG = 1; //clear flag after enabling it
      PILOTA_WAKEUP_INTERRUPT_FLAG = 1; //clear flag just in case

      //PrintConsoleString("B",0);
      timer_1_reset();
#endif
      break;

    default:
      //do nothing
      break;
  }

/*********Sample Pilots>**********/

/*********<Sample Proxes**********/
  ProxSample++;
  ProxSample %= 2;  //?

  if (!ProxSample) {
    Prox_Voltage_Filter_Add(A, ProxAReadADC());
#ifndef CH_A_ONLY
    Prox_Voltage_Filter_Add(B, ProxBReadADC());
#endif
  }

/*********Sample Proxes>**********/

/*********<LIN Service**********/
#if defined(LIN_CHARGE_ENABLE)
  LINState++;
  LINState %= RTI_TICKS_PER_LINCP_LOOP;  // Service the LIN signals every RTI_TICKS_PER_LINCP_LOOP -- see lin-cp.h

  if (LINState == 0) {
    DetermineLINCPState(A, continueOnLIN);
#ifndef CH_A_ONLY
    DetermineLINCPState(B, continueOnLIN);
#endif
  }

#ifdef SE_CONFIG
  (void)l_sch_tick(LI0);      // tick LIN
#ifndef CH_A_ONLY
  (void)l_sch_tick(LI1);      // tick LIN
#endif
#endif
#endif

/*********LIN Service>**********/

  update_delay_count();       // tick scheduler
  __RTIF = 1;                 // Clear RTIF
}

/*******************************************************
 * Port P Edge Detect
 ********************************************************/

interrupt VectorNumber_Vportp void PORTP_ISR(void){
  static uint8_t secondA = 0;
  static uint8_t secondB = 0;

  static uint16_t rising_edge_timeA = 0, last_rising_edge_timeA = 0;
  static uint16_t cycle_timeA, high_timeA;

  static uint16_t rising_edge_timeB = 0, last_rising_edge_timeB = 0;
  static uint16_t cycle_timeB, high_timeB;

  if (PILOTA_WAKEUP_INTERRUPT_ENABLE && PILOTA_WAKEUP_INTERRUPT_FLAG) {
    if(PILOTA_WAKEUP_INTERRUPT_POLARITY){ //rising edge detected
      PILOTA_WAKEUP_INTERRUPT_POLARITY = 0;
      timer_1_reset(); rising_edge_timeA = TCNT;
      timeoutcounterA = 0;
      if(secondA){
        //RisingAEdgeRoutine();
        cycle_timeA = rising_edge_timeA - last_rising_edge_timeA;                       //calculate PWM period in terms of bus clocks
        DelayUs(EDGE_BACKOFF_TIME_US);                                                  //shift sample from edge to account for capacitance on the line
        //DEBUG2 = 1;
        Pilot_Voltage_Filter_Add(A,PilotAReadADC());
        //DEBUG2 = 0;
#ifdef EV_CONFIG
        Pilot_Period_Filter_Add(A, (cycle_timeA > (MCU_BUS_FREQ/1040)) && (cycle_timeA < (MCU_BUS_FREQ/960)));              //double tolerance from standard to account for error on both sides
        Pilot_Duty_Cycle_Filter_Add(A,  (uint8_t) ((100 * (uint32_t) (high_timeA + (MCU_BUS_FREQ/200000) ))/cycle_timeA));  //add a nominal 0.5% to round correctly (MCU_BUS_FREQ/1000*0.005)
#endif
        secondA = 0;
        PILOTA_WAKEUP_INTERRUPT_ENABLE = OFF; //turn it off - we should be done
      }
      last_rising_edge_timeA = rising_edge_timeA;
    }
    else {
      PILOTA_WAKEUP_INTERRUPT_POLARITY = 1;
      high_timeA = TCNT - last_rising_edge_timeA;                                       //must be before backoff time
      DelayUs(EDGE_BACKOFF_TIME_US);
      //DEBUG3 = 0;
      Pilot_Voltage_Neg_Filter_Add(A, PilotAReadADC());
      //DEBUG3 = 1;
      secondA = 1;
    }
  }

#ifndef CH_A_ONLY
    if (PILOTB_WAKEUP_INTERRUPT_ENABLE && PILOTB_WAKEUP_INTERRUPT_FLAG) {
    if(PILOTB_WAKEUP_INTERRUPT_POLARITY){ //rising edge detected
      PILOTB_WAKEUP_INTERRUPT_POLARITY = 0;
      timer_1_reset(); rising_edge_timeB = TCNT;
      timeoutcounterB = 0;
      if(secondB){
        //RisingBEdgeRoutine();
        cycle_timeB = rising_edge_timeB - last_rising_edge_timeB;                       //calculate PWM period in terms of bus clocks
        DelayUs(EDGE_BACKOFF_TIME_US);                                                  //shift sample from edge to account for capacitance on the line
        //DEBUG2 = 1;
        Pilot_Voltage_Filter_Add(B, PilotBReadADC());
        //DEBUG2 = 0;
#ifdef EV_CONFIG
        Pilot_Period_Filter_Add(B, (cycle_timeB > (MCU_BUS_FREQ/1040)) && (cycle_timeB < (MCU_BUS_FREQ/960)));              //double tolerance from standard to account for error on both sides
        Pilot_Duty_Cycle_Filter_Add(B,  (uint8_t) ((100 * (uint32_t) (high_timeB + (MCU_BUS_FREQ/200000) ))/cycle_timeB));  //add a nominal 0.5% to round correctly (MCU_BUS_FREQ/1000*0.005)
#endif
        secondB = 0;
        PILOTB_WAKEUP_INTERRUPT_ENABLE = OFF; //turn it off - we should be done
      }
      last_rising_edge_timeB = rising_edge_timeB;
    }
    else {
      PILOTB_WAKEUP_INTERRUPT_POLARITY = 1;
      high_timeB = TCNT - last_rising_edge_timeB;                                         //must be before backoff time
      DelayUs(EDGE_BACKOFF_TIME_US);
      //DEBUG3 = 0;
      Pilot_Voltage_Neg_Filter_Add(B, PilotBReadADC());
      //DEBUG3 = 1;
      secondB = 1;
    }
  }
#endif
    PIFP = 0xFF;         // Clear all Port P interrupts
}

/*******************************************************
 * Serial Communication Interrupt
 ********************************************************/

interrupt VectorNumber_Vsci2 void SCI2_ISR(void){
  uint8_t rcv;

  //PTP_PTP4 = !PTP_PTP4;

  if(SCI2SR1_RDRF){
    rcv = SCI2DRL;
    SCI_RXRoutine(rcv);
  }

  if(SCI2SR1_TDRE){
    if (print_buf.inpos == print_buf.outpos){ // buffer empty
      SCI2CR2_TIE = 0;  // disable transmit interrupts
    }
    else{
      SCI2DRL = print_buf.data[print_buf.outpos];
      (void)CBufPop(&print_buf);
    }
  }

  if(SCI2ASR1_RXEDGIF) SCI2ASR1_RXEDGIF=1;
  
  if (SCI2SR1 & (SCI2SR1_OR_MASK | SCI2SR1_NF_MASK | SCI2SR1_FE_MASK))
    rcv = SCI2DRL;   //acknowledge noise, framing, and overflow errors   
}

/*******************************************************
 * Controller Area Network Interrupt (CAN)
 ********************************************************/

interrupt VectorNumber_Vcan0rx void CAN0RX_ISR(void){
  //PrintConsoleString("CAN Rx\r\n", 0);
  CAN0_RXRoutine();
  CAN0RFLG |= 1; // clear RXF flag
}

interrupt VectorNumber_Vcan0wkup void CAN0WKUP_ISR(void){
  CAN0RFLG_WUPIF = 1;
}

#pragma CODE_SEG DEFAULT /* Return to default code segment */