#include "canbus.h"
#include "derivative.h"
#include "j1939-signals.h"

/*******************************************************
 * Filename     : canbus.c
 ********************************************************/

bool CanBufPush(can_circular_buffer *buf, int bufsize, char in){
    uint8_t x = buf->inpos;
    if (++x >= bufsize) x = 0;
    if (x == buf->outpos) return FALSE;  // buffer full
    buf->data[buf->inpos] = in;
    buf->inpos = x;
    buf->diff++;
    return TRUE;
}


/*BOOL CanBufPop(can_circular_buffer *buf, int bufsize){
    uint8_t x = buf->outpos;
    if (x == buf->inpos) return FALSE;  // buffer empty
    if (++x >= bufsize) x = 0;
    buf->outpos = x;
    buf->diff--;
    return TRUE;
}*/


void InitCAN (uint8_t mode, uint8_t speed) {

  //this gives us a pointer to work with the extended identifiers as a 32-bit register
  volatile uint32_t* const extented_id_ptrn_1 = ((volatile uint32_t *) &CANIDAR0);
  volatile uint32_t* const extented_mask_ptrn_1 = ((volatile uint32_t *) &CANIDMR0);
  volatile uint32_t* const extented_id_ptrn_2 = ((volatile uint32_t *) &CANIDAR4);
  volatile uint32_t* const extented_mask_ptrn_2 = ((volatile uint32_t *) &CANIDMR4);

  uint32_t id_ptrn_1 = J1939_ID_HSC1 | (J1939_CHANNEL_A_INLET_ID << 8) | J1939_ECU_ID;                                                       //HSC1
  //uint32_t id_ptrn_1 = 0x18808249;
  uint32_t mask_ptrn_1 = 0;
#ifdef CH_A_ONLY
  uint32_t id_ptrn_2 = (J1939_ID_HSS1 & J1939_ID_EVSE1AC3PL) | (J1939_ECU_ID & J1939_CHANNEL_A_INVERTER_ID);                                 //HSS1 and EVSE1AC3PL
  uint32_t mask_ptrn_2 = (J1939_ID_HSS1 ^ J1939_ID_EVSE1AC3PL);
#else
  uint32_t id_ptrn_2 = (J1939_ID_HSS1 & J1939_ID_EVSE1AC3PL) | (J1939_ECU_ID & J1939_CHANNEL_A_INVERTER_ID & J1939_CHANNEL_B_INVERTER_ID);   //HSS1 and EVSE1AC3PL for each channel
  uint32_t mask_ptrn_2 = (J1939_ID_HSS1 ^ J1939_ID_EVSE1AC3PL) | ((J1939_ECU_ID ^ J1939_CHANNEL_A_INVERTER_ID) |
                                                                  (J1939_ECU_ID ^ J1939_CHANNEL_B_INVERTER_ID));
#endif

  CANCTL1 = CANCTL1_CANE_MASK; // turn on the CAN1 to get started

  /*The following regisers are locked unless you are in init mode except for CANE bit in CTL1
  * MSCAN control 1 register (CANCTL1)
  * MSCAN bus timing registers 0 and 1 (CANBTR0, CANBTR1)
  * MSCAN identifier acceptance control register (CANIDAC)
  * MSCAN identifier acceptance registers (CANIDAR0 - CANIDAR7) MSCAN identifier mask registers (CANIDMR0-CANIDMR7)
  */

  // Initialize CAN
  CANCTL0 |= CANCTL0_INITRQ_MASK | CANCTL0_WUPE_MASK; // set INITRQ, this will also set INITAK *AND* wakeup on can (we think)

  while (!(CANCTL1 & CANCTL1_INITAK_MASK)); // wait for init mode to occur
  //ENTERED INIT MODE

  // Bus-Off Recovery, Oscilator Clock, are default zero
  if(mode == NORMAL_MODE)
      CANCTL1 = CANCTL1_CANE_MASK | CANCTL1_WUPM_MASK ; // Set CANE just in case this is the first time after reset
  else if (mode == LISTEN_ONLY_MODE) CANCTL1 = CANCTL1_CANE_MASK | CANCTL1_WUPM_MASK | CANCTL1_LISTEN_MASK;   // Listen only mode for EV and CANE

  // Set Wake-Up Interrupt Enable to OFF because we don't want to
  // generate a wakeup interrupt until we are sleeping
  CANRIER_WUPIE = 0;

  // Bus Timing

  CANBTR1=0x98; // for a CAN Baud of 1Mbaud at 12Mhz crystal
  // (sync=1)+(prop2=2)+(prop1=9)
  // prop2 / (sync+prop1+prop2) = 2/12
  // ~= 83% in last during last sample

  //CANBTR1=0xB6; // for a CAN Baud of 1Mbaud at 12Mhz crystal
  // 3 samp (sync=1)+(prop2=4)+(prop1=7)
  // prop2 / (sync+prop1+prop2) = 4/12
  // ~= 75% in last during last sample

  if(speed == CAN125KBAUD)
    CANBTR0=0x87; // then divide by 8 means 125Kbaud
  else if(speed == CAN250KBAUD)
    CANBTR0=0x83; // then divide by 4 means 250Kbaud
  else if (speed == CAN500KBAUD)
    CANBTR0=0x81; // then divide by 2 means 500Kbaud
  else if (speed == CAN1MBAUD)
    CANBTR0=0x80; // then divide by 1
  else if (speed == CAN20KBAUD)
      CANBTR0 = 0xB1;


  CANIDAC=0x00; // 2x 32-bit filters

#define SET_ACCEPTANCE(x) \
    /*set the first acceptance filter*/                                                                     \
    /*mask off all the upper bits > ID17 first shifting over one to make room for RTR flag set to zero */   \
    *extented_id_ptrn_##x = (id_ptrn_##x << 1) & 0x7FFFF;                                                   \
    /*shift over 3 so ID28 is in the MSB of 32-bit register*/                                               \
    /*keep ID18 and higher mask the rest off (with and)*/                                                   \
    /*set SRR and IDE to 1 (with inner or)*/                                                                \
    /*or equals in with lower bits of identifier*/                                                          \
    *extented_id_ptrn_##x |= (((id_ptrn_##x << 0x3) & 0xFFE00000) | 0x180000);                              \
                                                                                                            \
    /*set the first filter mask. 0s are checked and 1s are ignored*/                                        \
    /*same as above except without setting SRR and IDE because we want to check them.*/                     \
    *extented_mask_ptrn_##x = (mask_ptrn_##x << 1) & 0x7FFFF;                                               \
    *extented_mask_ptrn_##x |= ((mask_ptrn_##x << 0x3) & 0xFFE00000);

  SET_ACCEPTANCE(1);
  SET_ACCEPTANCE(2);


  CANCTL0 &= ~(uint8_t)CANCTL0_INITRQ_MASK; // clear INITRQ
  while (CANCTL1 & CANCTL1_INITAK_MASK);
  //LEAVING INIT MODE
  CANCTL0 |= CANCTL0_WUPE_MASK;
  CANRIER |= CANRIER_RXFIE_MASK; // enable receive interrupt
}

