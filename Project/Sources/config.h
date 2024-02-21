#ifndef _CONFIG_H
#define _CONFIG_H

//#define CH_A_ONLY
//Behavior is undefined if neither LIN nor PWM are enabled
//#define PWM_CHARGE_ENABLE
#define LIN_CHARGE_ENABLE

//#define J1939_REQD_FOR_CHARGE
//#define J1939_XMIT
//#define J1939_SEND_SEINFO

#define INLET_LOCK_TYPE NONE
//#define INLET_LOCK_TYPE FOUR_WIRE

//#define DISABLE_PROX_CHECKING

//#define SINGLE_PHASE
//#define TYPE_I_COUPLER              //As of now, this does the same thing as SINGLE_PHASE + uses Type I prox levels

//#define PRE_RELEASE_HARDWARE
//#define WHITEBOARD_HARDWARE

//#define EV_CONFIG
/****<DO NOT MODIFY******/
#ifndef EV_CONFIG
  #define SE_CONFIG
#endif
/****DO NOT MODIFY>******/

#define UART_BAUD            115200

#define INITIALIZATION_DELAY 1
#define RTI_TICKS_PER_SECOND 926ul  //1000/1.08ms  This still runs long for some reason  FIXME?
#define LOCK_CHECK_DELAY     250
#define SLEEP_CHECK_DELAY     100

//EV
#define CONNECTION_CLEAR_TIME 2*60*RTI_TICKS_PER_SECOND   //Time between connections to assume a new connection is not a restart
#define RAMPDOWN_TIME         2*RTI_TICKS_PER_SECOND      //Time to wait for inverter to stop drawing current before requesting disconnect in non-emergency situation
#define VMU_WAKEUP_TIME       60*RTI_TICKS_PER_SECOND     //Time to wait for ECU to wake up and request charge before deasserting wakeup signal

/*<Protocol Versions*/
//Supported Protocol Versions.  2 is always supported, 0 is controlled by PWM_CHARGE_ENABLE
//Order controls preference for EV, 2 is always last
#define PVER_PWM       0
#define PVER_BASE      2
#define PVER_SLASH_1   3
#define PVER_SLASH_1P  103
#define PVER_SLASH_2   252

#define SUPPORTED_PVERSIONS  PVER_SLASH_1,
//#define SUPPORTED_PVERSIONS   //3068/null only
/*Protocol Versions>*/

//Connection Types
#define CONNTP_EV_CASE_A      0
#define CONNTP_SE_OUTLET      0
#define CONNTP_TYPE_1         1
#define CONNTP_TYPE_2         2
#define CONNTP_CCS_1          3
#define CONNTP_CCS_2          4
#define CONNTP_3400           5
#define CONNTP_GB_T           6
#define CONNTP_ERROR          0xFE
#define CONNTP_NOTSPECIFIED   0xFF

/*<Ratings*/
//Voltages are *10, Currents are *1
#define MAX_RATED_CURRENT 80

//EVSE
#define EVSE_INCREASE_SET_C_WAIT_PERIOD 100
#define EVSE_DECREASE_SET_C_WAIT_PERIOD 10
#define EVSE_MAIN_LOOP     1000

//LIN-CP Specific.  If different settings are to be used for different legs, or for the two channels, modify lin-cp.c and evse_smarts.c
#include "lin-cp.h"                 //Defines Frequency Enums.  Must be after SE/EV_CONFIG definition

//SE Settings
#define SE_FREQUENCY SixtyHz
#define SE_NOMINAL_VOLTAGE_LL 2080
#define SE_NOMINAL_VOLTAGE_LN 1200
#define SE_MAX_CURRENT_L 16
#define SE_MAX_CURRENT_N 16
#define SE_CONNTP CONNTP_TYPE_2

//EV settings
#define EV_FREQUENCIES FiftyOrSixtyHz
#define EV_MAX_VOLTAGE_LL 4800
#define EV_MAX_VOLTAGE_LN 2770
#define EV_MIN_VOLTAGE_LL 2080
#define EV_MIN_VOLTAGE_LN 1200
#define EV_MAX_CURRENT_L 32
#define EV_MAX_CURRENT_N 32
#define EV_MIN_CURRENT_L 0
#define EV_CONNTP CONNTP_TYPE_2

/****<DO NOT MODIFY******/
#if defined(SINGLE_PHASE) || defined(TYPE_I_COUPLER)
  #undef  SE_NOMINAL_VOLTAGE_LL
  #undef  EV_MAX_VOLTAGE_LL
  #undef  EV_MIN_VOLTAGE_LL
  #define SE_NOMINAL_VOLTAGE_LL 0xFFFF
  #define EV_MAX_VOLTAGE_LL 0xFFFF
  #define EV_MIN_VOLTAGE_LL 0xFFFF
#endif
/****DO NOT MODIFY>******/ 
/*Ratings>*/

/*<J1939*/
#define J1939_100MS_MESSAGE_TIMEOUT 250
#define J1939_1S_MESSAGE_TIMEOUT 2500

//J1939 CAN IDs
//NOTE: These MUST be declared unsigned or the bitshift operations can fail 
#define J1939_CHANNEL_A_INLET_ID 0x82u
#define J1939_CHANNEL_B_INLET_ID 0x83u

#define J1939_CHANNEL_A_INVERTER_ID 0x49u
#define J1939_CHANNEL_B_INVERTER_ID 0x50u

#define J1939_ECU_ID 0x49u
/*J1939>*/

/*<Filters*/
#define FILTER_SIZE             12    //How many values to store
#define FILTER_LOW_THRESH       6
#define FILTER_NOM_THRESH       8
#define FILTER_HIGH_THRESH      10
#define FILTER_VERY_HIGH_THRESH 11
/*Filters>*/

/*<Debug Printing*/
//#define DEBUG_J1772_STATES          //Print safety checks when checked by the state machines
/*Debug Printing>*/  

#endif

/*
defines to consider moving here
hardware.h:       STATE_CB_TRANSITION_DELAY
lin-cp.h:         LIN_DETECT_TIMEOUT
lock.h:           DRIVE_TIME
                  RETRY_DELAY
                  UNVERIFIED_UNLOCK_DELAY
pilot.c:          STATE_A_TRANSITION_DELAY
                  POWER_UNAVAILABLE_SLEEP_COUNT
scheduler.c       DELAY_TABLE_SIZE
*/
