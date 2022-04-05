#ifndef _HARDWARE_H
#define _HARDWARE_H

#include "types.h"
#include "config.h"

#define A 0
#define B 1

/*******************************************************
 * Configuration
 ********************************************************/

void init_hardware(void);
void init_timers(void);
void configure_oscillator(void); 
void init_io(void);
void init_pwm(void);
void InitRTI(void);

/*******************************************************
 * Constants
 ********************************************************/
 
#define EDGE_BACKOFF_TIME_US 6            //Delay to allow Pilot lines to settle before sampling 

 
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ *
 * The types of PROX states
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
// DOMAIN : prox_type_t
#define PROX_J1772           1
#define PROX_IEC61851        2
// END prox_type_t

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ * 
 * The defined set of Lock Types
 * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
// DOMAIN : lock_type_t
#define NONE                 1
#define FOUR_WIRE            2
// END lock_type_t

/*******************************************************
 * Delay Functions
 ********************************************************/

void DelayMs(uint16_t ms);
void DelayUs(uint16_t us);

/*******************************************************
 * Interrupt Helper Functions
 ********************************************************/
 
uint8_t check_interrupts_disabled(void);

/*******************************************************
 * Analog to Digital Converter (ADC/ATD)
 ********************************************************/
#define ATDPILOTACH     0
#define ATDPROXACH      2
#define ATDPILOTBCH     1
#define ATDPROXBCH      3
//#define ATD12PLUSCH     0
//#define ATD12MINUSCH    0
//#define ATD12BATTCH     0

#define PILOTA_WAKEUP_INTERRUPT_ENABLE PIEP_PIEP2
#define PILOTA_WAKEUP_INTERRUPT_FLAG PIFP_PIFP2
#define PILOTA_WAKEUP_INTERRUPT_POLARITY PPSP_PPSP2

#define PILOTB_WAKEUP_INTERRUPT_ENABLE PIEP_PIEP3
#define PILOTB_WAKEUP_INTERRUPT_FLAG PIFP_PIFP3
#define PILOTB_WAKEUP_INTERRUPT_POLARITY PPSP_PPSP3

void InitADC(void);

uint8_t PilotAReadADC(void);
uint8_t PilotBReadADC(void);

uint8_t ProxAReadADC(void);
uint8_t ProxBReadADC(void);

/*******************************************************
 * Port I/O Macros
 ********************************************************/

//block 1 (top left)
#define UC_PILOT_B_STATE_C    PTT_PTT5
#define UC_PILOT_B_STATE_B    PTT_PTT4
#define UC_PILOT_A_STATE_C    PTT_PTT3
#define UC_PILOT_A_STATE_B    PTT_PTT2

#ifndef PRE_RELEASE_HARDWARE
#define CONTACTOR_B_ERROR     PTT_PTT5
#define CONTACTOR_B_CLOSE     PTT_PTT4
#define CONTACTOR_A_ERROR     PTT_PTT3
#define CONTACTOR_A_CLOSE     PTT_PTT2
#endif

#define CAN_SLEEP             PTT_PTT1

//block 3
#define OVER_TEMP_CUTOUT      PTP_PTP7
#define PWM_A                 PTP_PTP5
#define PWM_B                 PTP_PTP4
#define PILOT_DET_B           PTP_PTP3
#define PILOT_DET_A           PTP_PTP2

//block 4
#ifndef S12X
#define LIN_A_ENABLE          PTJ_PTJ0
#define LIN_B_ENABLE          PTJ_PTJ1
#define VMU_WAKEUP            PTJ_PTJ2
#define SLEEP_SHDN            PTJ_PTJ3
#define UC_SENSE_SIGNAL_A_LOCK    PTJ_PTJ4
#define UC_SENSE_SIGNAL_A_UNLOCK  PTJ_PTJ5
#define UC_SENSE_SIGNAL_B_LOCK    PTJ_PTJ6
#define UC_SENSE_SIGNAL_B_UNLOCK  PTJ_PTJ7
#else
#define LIN_A_ENABLE          PORTA_PA0
#define LIN_B_ENABLE          PORTA_PA1
#define VMU_WAKEUP            PORTA_PA2
#define SLEEP_SHDN            PORTA_PA3
#define UC_SENSE_SIGNAL_A_LOCK    PORTA_PA4
#define UC_SENSE_SIGNAL_A_UNLOCK  PORTA_PA5
#define UC_SENSE_SIGNAL_B_LOCK    PORTA_PA6
#define UC_SENSE_SIGNAL_B_UNLOCK  PORTA_PA7
#endif

#ifdef PRE_RELEASE_HARDWARE
#define CONTACTOR_B_CLOSE     PTJ_PTJ4
#define CONTACTOR_B_ERROR     PTJ_PTJ5
#define CONTACTOR_A_ERROR     PTJ_PTJ6
#define CONTACTOR_A_CLOSE     PTJ_PTJ7
#endif

//block 7

#ifndef S12X
#define RELAY_CONTROL_B_PLUS  PT0AD_PT0AD7
#define RELAY_CONTROL_B_MINUS PT0AD_PT0AD6
#define RELAY_CONTROL_A_PLUS  PT0AD_PT0AD5
#define RELAY_CONTROL_A_MINUS PT0AD_PT0AD4
#define PWM_ENABLE_B          PT0AD_PT0AD2
#define PWM_ENABLE_A          PT0AD_PT0AD1
#else
#define RELAY_CONTROL_B_PLUS  PORTB_PB7
#define RELAY_CONTROL_B_MINUS PORTB_PB6
#define RELAY_CONTROL_A_PLUS  PORTB_PB5
#define RELAY_CONTROL_A_MINUS PORTB_PB4
#define CAN4_SLEEP            PORTB_PB3
#define PWM_ENABLE_B          PORTB_PB2
#define PWM_ENABLE_A          PORTB_PB1
#define CAN1_SLEEP            PORTB_PB0
#endif

#define SET_PWM_PIN(x,y) if(x) { PWM_B = (y); } else { PWM_A = (y); }

/*******************************************************
 * PWM
 ********************************************************/

#define EnablePWMA() PWME_PWME5 = 1
#define DisablePWMA() PWME_PWME5 = 0
#define EnablePWMB() PWME_PWME4 = 1
#define DisablePWMB() PWME_PWME4 = 0
#define SetPilotADutyCycleRaw(d) PWMDTY5 = d
#define SetPilotBDutyCycleRaw(d) PWMDTY4 = d

#define EnablePWM(x) if(x) { EnablePWMB(); } else { EnablePWMA(); }
#define DisablePWM(x) if(x) { DisablePWMB(); } else { DisablePWMA(); }
#define SetPilotDutyCycleRaw(x,y) if(x) { SetPilotBDutyCycleRaw(y); } else { SetPilotADutyCycleRaw(y); }

/*******************************************************
 * Controller Area Network Interrupt (CAN)
 ********************************************************/
 
#ifdef S12X
#define CAN0_BASE_ADDRESS &CAN0CTL0
#define CAN1_BASE_ADDRESS &CAN1CTL0
#define CAN4_BASE_ADDRESS &CAN4CTL0

#else
#define CAN0_BASE_ADDRESS &CANCTL0
#endif

/*******************************************************
 * (EV) States
 ********************************************************/

#ifdef PRE_RELEASE_HARDWARE

#define SetAStateA() UC_PILOT_A_STATE_B = 0; UC_PILOT_A_STATE_C = 0   
#define SetAStateB() UC_PILOT_A_STATE_B = 0; UC_PILOT_A_STATE_C = 1
#define SetAStateC() UC_PILOT_A_STATE_B = 1; UC_PILOT_A_STATE_C = 0

#define SetBStateA() UC_PILOT_B_STATE_B = 0; UC_PILOT_B_STATE_C = 0   
#define SetBStateB() UC_PILOT_B_STATE_B = 0; UC_PILOT_B_STATE_C = 1
#define SetBStateC() UC_PILOT_B_STATE_B = 1; UC_PILOT_B_STATE_C = 0

#else 

#define SetAStateA() UC_PILOT_A_STATE_B = 0; UC_PILOT_A_STATE_C = 0   
#define SetAStateB() UC_PILOT_A_STATE_B = 1; UC_PILOT_A_STATE_C = 0
#define SetAStateC() UC_PILOT_A_STATE_B = 1; UC_PILOT_A_STATE_C = 1

#define SetBStateA() UC_PILOT_B_STATE_B = 0; UC_PILOT_B_STATE_C = 0   
#define SetBStateB() UC_PILOT_B_STATE_B = 1; UC_PILOT_B_STATE_C = 0
#define SetBStateC() UC_PILOT_B_STATE_B = 1; UC_PILOT_B_STATE_C = 1

#endif  

#define SetStateA(x) if(x) { SetBStateA(); } else { SetAStateA(); }
#define SetStateB(x) if(x) { SetBStateB(); } else { SetAStateB(); }
#define SetStateC(x) if(x) { SetBStateC(); } else { SetAStateC(); }  

#endif