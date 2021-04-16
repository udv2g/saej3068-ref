#ifndef _ADC_CONSTANTS_H
#define _ADC_CONSTANTS_H

// This file is generated by adc_constants.m 


// MIN/MAX Values for the Pilot states
#define STATE_A_MAX                         0xE7     // 13 V
#define STATE_A_NOM                         0xDF     // 12 V
#define STATE_A_MIN                         0xD7     // 11 V

#define STATE_B_MAX                         0xCF     // 10 V
#define STATE_B_NOM                         0xC8     // 9 V
#define STATE_B_MIN                         0xC0     // 8 V

#define STATE_C_MAX                         0xBA     // 7.3 V
#define STATE_C_NOM                         0xB0     // 6 V
#define STATE_C_MIN                         0xA5     // 4.7 V

#define STATE_D_MAX                         0xA0     // 4 V
#define STATE_D_NOM                         0x98     // 3 V
#define STATE_D_MIN                         0x90     // 2 V

#define STATE_E_MAX                         0x8A     // 1.2 V
#define STATE_E_NOM                         0x80     // 0 V
#define STATE_E_MIN                         0x77     // -1.2 V

#define STATE_R_MAX                         0x5E     // -4.3 V
#define STATE_R_NOM                         0x56     // -5.3 V
#define STATE_R_MIN                         0x4E     // -6.3 V

#define STATE_F_MAX                         0x29     // -11 V
#define STATE_F_NOM                         0x21     // -12 V
#define STATE_F_MIN                         0x17     // -13.2 V


// MIN/MAX Values for the Prox states
// Standard prox is not used in J3068, but the code is capable of handling it so we might as well define the values.
#define PROX_STATE_DISCONNECTED_MAX         0xFF     // 5 V
#define PROX_STATE_DISCONNECTED_MIN         0xBD     // 3.70588 V

#define PROX_STATE_CONNECTED_OFF_MAX        0xB0     // 3.45098 V
#define PROX_STATE_CONNECTED_OFF_MIN        0x6D     // 2.13725 V

#define PROX_STATE_CONNECTED_ON_MAX         0x65     // 1.98039 V
#define PROX_STATE_CONNECTED_ON_MIN         0x38     // 1.09804 V


// J3068/61581-Annex-D Prox
#define IEC_PROX_ERROR_HIGH_MIN             0xF2     // 4.7451 V

#define IEC_PROX_DISCONNECTED_MAX           0xF1     // 4.72549 V
#define IEC_PROX_DISCONNECTED_MIN           0xDB     // 4.29412 V

#define IEC_PROX_RESERVED_HIGH_MAX          0xDA     // 4.27451 V
#define IEC_PROX_RESERVED_HIGH_MIN          0xC8     // 3.92157 V

#define IEC_PROX_13A_MAX                    0xC7     // 3.90196 V
#define IEC_PROX_13A_MIN                    0xAF     // 3.43137 V

#define IEC_PROX_20A_MAX                    0xAE     // 3.41176 V
#define IEC_PROX_20A_MIN                    0x98     // 2.98039 V

#define IEC_PROX_RESERVED_BUTTON_DOWN_MAX   0x97     // 2.96078 V
#define IEC_PROX_RESERVED_BUTTON_DOWN_MIN   0x75     // 2.29412 V

#define IEC_PROX_32A_MAX                    0x74     // 2.27451 V
#define IEC_PROX_32A_MIN                    0x59     // 1.7451 V

#define IEC_PROX_RESERVED_BUTTON_UP_MAX     0x58     // 1.72549 V
#define IEC_PROX_RESERVED_BUTTON_UP_MIN     0x44     // 1.33333 V

#define IEC_PROX_63A_MAX                    0x43     // 1.31373 V
#define IEC_PROX_63A_MIN                    0x2F     // 0.921569 V

#define IEC_PROX_RESERVED_LOW_MAX           0x2E     // 0.901961 V
#define IEC_PROX_RESERVED_LOW_MIN           0x0D     // 0.254902 V

#define IEC_PROX_ERROR_LOW_MAX              0x0C     // 0.235294 V


#endif
