#include "canbus.h"
#include "derivative.h"
#include "j1939-signals.h"

/*******************************************************
 * Filename     : canbus.c
 ********************************************************/

void InitCAN_ExtendedIDs (uint8_t * const base_address, uint8_t mode, uint8_t speed, uint32_t id_ptrn_1, uint32_t mask_ptrn_1, uint32_t id_ptrn_2, uint32_t mask_ptrn_2) {

  //this gives us a pointer to work with the extended identifiers as a 32-bit register
  volatile uint32_t* const extented_id_ptrn_1 = ((volatile uint32_t *) (base_address + 0x0010));
  volatile uint32_t* const extented_mask_ptrn_1 = ((volatile uint32_t *) (base_address + 0x0014));
  volatile uint32_t* const extented_id_ptrn_2 = ((volatile uint32_t *) (base_address + 0x0018));
  volatile uint32_t* const extented_mask_ptrn_2 = ((volatile uint32_t *) (base_address + 0x001C));
  
  volatile uint8_t * const _canctl0 = (base_address + 0x0000);
  volatile uint8_t * const _canctl1 = (base_address + 0x0001);
  volatile uint8_t * const _canbtr0 = (base_address + 0x0002);
  volatile uint8_t * const _canbtr1 = (base_address + 0x0003);  
  volatile uint8_t * const _canrier = (base_address + 0x0005);
  volatile uint8_t * const _canidac = (base_address + 0x000B);

  *_canctl1 = CANCTL1_CANE_MASK; // turn on the CAN1 to get started

  /*The following regisers are locked unless you are in init mode except for CANE bit in CTL1
  * MSCAN control 1 register (CANCTL1)
  * MSCAN bus timing registers 0 and 1 (CANBTR0, CANBTR1)
  * MSCAN identifier acceptance control register (CANIDAC)
  * MSCAN identifier acceptance registers (CANIDAR0 - CANIDAR7) MSCAN identifier mask registers (CANIDMR0-CANIDMR7)
  */

  // Initialize CAN
  *_canctl0 |= CANCTL0_INITRQ_MASK | CANCTL0_WUPE_MASK; // set INITRQ, this will also set INITAK *AND* wakeup on can (we think)

  while (!(*_canctl1 & CANCTL1_INITAK_MASK)); // wait for init mode to occur
  //ENTERED INIT MODE

  // Bus-Off Recovery, Oscilator Clock, are default zero
  if(mode == NORMAL_MODE)
    *_canctl1 = CANCTL1_CANE_MASK | CANCTL1_WUPM_MASK ; // Set CANE just in case this is the first time after reset
  else if (mode == LISTEN_ONLY_MODE) 
    *_canctl1 = CANCTL1_CANE_MASK | CANCTL1_WUPM_MASK | CANCTL1_LISTEN_MASK;   // Listen only mode for EV and CANE

  // Set Wake-Up Interrupt Enable to OFF because we don't want to
  // generate a wakeup interrupt until we are sleeping
  *_canrier &= (~(uint8_t)CANRIER_WUPIE_MASK);

  // Bus Timing

  *_canbtr1=0x98; // for a CAN Baud of 1Mbaud at 12Mhz crystal
  // (sync=1)+(prop2=2)+(prop1=9)
  // prop2 / (sync+prop1+prop2) = 2/12
  // ~= 83% in last during last sample

  //CANBTR1=0xB6; // for a CAN Baud of 1Mbaud at 12Mhz crystal
  // 3 samp (sync=1)+(prop2=4)+(prop1=7)
  // prop2 / (sync+prop1+prop2) = 4/12
  // ~= 75% in last during last sample

  if(speed == CAN125KBAUD)
    *_canbtr0=0x87; // then divide by 8 means 125Kbaud
  else if(speed == CAN250KBAUD)
    *_canbtr0=0x83; // then divide by 4 means 250Kbaud
  else if (speed == CAN500KBAUD)
    *_canbtr0=0x81; // then divide by 2 means 500Kbaud
  else if (speed == CAN1MBAUD)
    *_canbtr0=0x80; // then divide by 1
  else if (speed == CAN20KBAUD)
    *_canbtr0=0xB1;


  *_canidac=0x00; // 2x 32-bit filters

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


  *_canctl0 &= ~(uint8_t)CANCTL0_INITRQ_MASK; // clear INITRQ
  while (*_canctl1 & CANCTL1_INITAK_MASK);
  //LEAVING INIT MODE
  *_canctl0 |= CANCTL0_WUPE_MASK;
  *_canrier |= CANRIER_RXFIE_MASK; // enable receive interrupt
}

void InitCAN_StandardIDs (uint8_t * const base_address, uint8_t mode, uint8_t speed, uint16_t id_ptrn_1, uint16_t mask_ptrn_1, uint16_t id_ptrn_2, uint16_t mask_ptrn_2, uint16_t id_ptrn_3, uint16_t mask_ptrn_3, uint16_t id_ptrn_4, uint16_t mask_ptrn_4) {
  
  //this gives us a pointer to work with the extended identifiers as a 16-bit register
  volatile uint16_t* const extented_id_ptrn_1 = ((volatile uint16_t *) (base_address + 0x0010));
  volatile uint16_t* const extented_mask_ptrn_1 = ((volatile uint16_t *) (base_address + 0x0014));
  volatile uint16_t* const extented_id_ptrn_2 = ((volatile uint16_t *) (base_address + 0x0018));
  volatile uint16_t* const extented_mask_ptrn_2 = ((volatile uint16_t *) (base_address + 0x001C));
  volatile uint16_t* const extented_id_ptrn_3 = ((volatile uint16_t *) (base_address + 0x0012));
  volatile uint16_t* const extented_mask_ptrn_3 = ((volatile uint16_t *) (base_address + 0x0016));
  volatile uint16_t* const extented_id_ptrn_4 = ((volatile uint16_t *) (base_address + 0x001A));
  volatile uint16_t* const extented_mask_ptrn_4 = ((volatile uint16_t *) (base_address + 0x001E));

  volatile uint8_t * const _canctl0 = (base_address + 0x0000);
  volatile uint8_t * const _canctl1 = (base_address + 0x0001);
  volatile uint8_t * const _canbtr0 = (base_address + 0x0002);
  volatile uint8_t * const _canbtr1 = (base_address + 0x0003);  
  volatile uint8_t * const _canrier = (base_address + 0x0005);
  volatile uint8_t * const _canidac = (base_address + 0x000B);
  

  *_canctl1 = CANCTL1_CANE_MASK; // turn on the CAN1 to get started

  /*The following regisers are locked unless you are in init mode except for CANE bit in CTL1
  * MSCAN control 1 register (CANCTL1)
  * MSCAN bus timing registers 0 and 1 (CANBTR0, CANBTR1)
  * MSCAN identifier acceptance control register (CANIDAC)
  * MSCAN identifier acceptance registers (CANIDAR0 - CANIDAR7) MSCAN identifier mask registers (CANIDMR0-CANIDMR7)
  */

  // Initialize CAN
  *_canctl0 |= CANCTL0_INITRQ_MASK | CANCTL0_WUPE_MASK; // set INITRQ, this will also set INITAK *AND* wakeup on can (we think)

  while (!(*_canctl1 & CANCTL1_INITAK_MASK)); // wait for init mode to occur
  //ENTERED INIT MODE

  // Bus-Off Recovery, Oscilator Clock, are default zero
  if(mode == NORMAL_MODE)
    *_canctl1 = CANCTL1_CANE_MASK | CANCTL1_WUPM_MASK ; // Set CANE just in case this is the first time after reset
  else if (mode == LISTEN_ONLY_MODE) 
    *_canctl1 = CANCTL1_CANE_MASK | CANCTL1_WUPM_MASK | CANCTL1_LISTEN_MASK;   // Listen only mode for EV and CANE

  // Set Wake-Up Interrupt Enable to OFF because we don't want to
  // generate a wakeup interrupt until we are sleeping
  *_canrier &= (~(uint8_t)CANRIER_WUPIE_MASK);

  // Bus Timing

  *_canbtr1=0x98; // for a CAN Baud of 1Mbaud at 12Mhz crystal
  // (sync=1)+(prop2=2)+(prop1=9)
  // prop2 / (sync+prop1+prop2) = 2/12
  // ~= 83% in last during last sample

  //CANBTR1=0xB6; // for a CAN Baud of 1Mbaud at 12Mhz crystal
  // 3 samp (sync=1)+(prop2=4)+(prop1=7)
  // prop2 / (sync+prop1+prop2) = 4/12
  // ~= 75% in last during last sample

  if(speed == CAN125KBAUD)
    *_canbtr0=0x87; // then divide by 8 means 125Kbaud
  else if(speed == CAN250KBAUD)
    *_canbtr0=0x83; // then divide by 4 means 250Kbaud
  else if (speed == CAN500KBAUD)
    *_canbtr0=0x81; // then divide by 2 means 500Kbaud
  else if (speed == CAN1MBAUD)
    *_canbtr0=0x80; // then divide by 1
  else if (speed == CAN20KBAUD)
    *_canbtr0 = 0xB1;
      
  *_canidac=0x10; // 4 - 16-bit filters

  // Standard Identifier Acceptance Registers
  // ID filter -- set or clear bits you want to match
  // only the bits that are 0'ed in the mask are checks
  *extented_id_ptrn_1 = (id_ptrn_1 << 1) & 0xFFF7;       //Set IDE = 0 for standard identifiers
  *extented_id_ptrn_2 = (id_ptrn_2 << 1) & 0xFFF7;
  *extented_id_ptrn_3 = (id_ptrn_3 << 1) & 0xFFF7;
  *extented_id_ptrn_4 = (id_ptrn_4 << 1) & 0xFFF7;

  // Identifier Mask Registers
  *extented_mask_ptrn_1 = (mask_ptrn_1 << 1) & 0xFFF7;   //Check IDE = 0 for standard identifiers
  *extented_mask_ptrn_2 = (mask_ptrn_2 << 1) & 0xFFF7;
  *extented_mask_ptrn_3 = (mask_ptrn_3 << 1) & 0xFFF7;
  *extented_mask_ptrn_4 = (mask_ptrn_4 << 1) & 0xFFF7;

  *_canctl0 &= ~(uint8_t)CANCTL0_INITRQ_MASK; // clear INITRQ
  while (*_canctl1 & CANCTL1_INITAK_MASK);
  //LEAVING INIT MODE
  *_canctl0 |= CANCTL0_WUPE_MASK;
  *_canrier |= CANRIER_RXFIE_MASK; // enable receive interrupt
}

int8_t send_command_CAN(uint8_t * const base_address, uint8_t identifiers, uint32_t id, uint8_t *data, uint8_t msg_size) {
  //In documentation, "X" in register offsets is 2 for RX and 3 for TX.  This is about as clear as mud.
  int i;
  uint8_t tb;
  uint8_t *dest = base_address + 0x0034;    //CANTXDSR0
  
  volatile uint8_t * const _cantflg   = (base_address + 0x0006);
  volatile uint8_t * const _cantarq   = (base_address + 0x0008);
  volatile uint8_t * const _cantbsel  = (base_address + 0x000A);
  
  volatile uint8_t * const _cantxidr0 = (base_address + 0x0030);
  volatile uint8_t * const _cantxidr1 = (base_address + 0x0031);
  volatile uint8_t * const _cantxidr2 = (base_address + 0x0032);
  volatile uint8_t * const _cantxidr3 = (base_address + 0x0033);
  
  volatile uint8_t * const _cantxdlr  = (base_address + 0x003C);

  //PrintConsoleString("sending CAN\r\n",0);

  if (!*_cantflg) {
    *_cantarq = 0x7;
    //this packet will be lost but but next time it should be clear
    return -1; //you could return fail here
  }

  *_cantbsel = *_cantflg;  // make an empty transmit buffer accessible
  tb         = *_cantbsel; //see which one you got

  // Write the identifier
  if(identifiers == STANDARD_IDENTIFIERS) {
    *_cantxidr0 = ((id >> 3) & 0xFF);
    *_cantxidr1 = ((id & 0x07) << 5);
  } else  {   //EXTENDED_IDENTIFERS  
    *_cantxidr0 = ((id >> 21) & 0xFF);
    *_cantxidr1 = ((id >> 13) & 0xE0) | 0x18 | ((id >> 15) & 0x07);
    *_cantxidr2 = ((id >> 7) & 0xFF);
    *_cantxidr3 = ((id << 1) & 0xFE);
  }

  // Write the data
  for (i = 0; i < msg_size; ++i) {
    dest[i] = data[i];
  }

  // Finally write the msg size
  *_cantxdlr = msg_size;

  *_cantflg = tb; // buffer marked by tb ready for transmission
  return tb;
}

uint32_t parse_message_CAN(uint8_t * const base_address, uint8_t identifiers, uint8_t table_size, can_msg_dispatcher_t* table) {
  //In documentation, "X" in register offsets is 2 for RX and 3 for TX.  This is about as clear as mud.
  int i;
  uint32_t id;
  uint8_t msg_length;
  can_msg_dispatcher_t *curr_msg_dispatcher;
  
  volatile uint8_t * const _canrxidr0 = (base_address + 0x0020);
  volatile uint8_t * const _canrxidr1 = (base_address + 0x0021);
  volatile uint8_t * const _canrxidr2 = (base_address + 0x0022);
  volatile uint8_t * const _canrxidr3 = (base_address + 0x0023);
  
           uint8_t * const _canrxdsr0 = (base_address + 0x0024);
  
  volatile uint8_t * const _canrxdlr  = (base_address + 0x002C);

  if(identifiers == STANDARD_IDENTIFIERS) {
    id = *_canrxidr0; // Read the higher order bits 8 bits of the id
    id = (id << 3) | ((*_canrxidr1 >> 5) & 0x07); // Read the lower order 3 bits
  } else  {   //EXTENDED_IDENTIFERS
    id = 0;
    id = *_canrxidr0;
    id = (id << 6) | ((*_canrxidr1 & 0xE0) >> 2) | (*_canrxidr1 & 0x07);
    id = (id << 8) | (*_canrxidr2 & 0xFF);
    id = (id << 7) | ((*_canrxidr3 >> 1) & 0x7F);
  }

  msg_length = *_canrxdlr;

  // Ok, let's try to parse this message
  for (i = 0; i < table_size; ++i) {
    curr_msg_dispatcher = table +i;   //~~pointer math~~
    if (curr_msg_dispatcher->id == id) {
      if (curr_msg_dispatcher->process_message_p) {
        (void)curr_msg_dispatcher->parser(curr_msg_dispatcher->obj, _canrxdsr0, 0, msg_length);
        (void)curr_msg_dispatcher->handler(curr_msg_dispatcher->obj);
      }
      break;
    }
  }

  return 0;
}

