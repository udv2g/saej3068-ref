#include "lin-cp.h"
#include "globals.h"
#include "ids_handler.h"
#include "j3072_handler.h"
#include "utils.h"

#pragma MESSAGE DISABLE C2705 //possible loss of data

///>Declarations

typedef struct  {
  uint16_t EvPwrCtrlModesSpt;
  uint16_t EvSupGridCode1;
  uint16_t EvVRefL1N;
  uint16_t EvVRefLL;
  uint16_t EvWMaxRtg;
  uint16_t EvVAMaxRtg;
  uint16_t EvIvarMaxRtg;
  uint16_t EvAvarMaxRtg;
  uint16_t EvChaWMaxRtg;
  uint16_t EvChaVAMaxRtg;
} ev_cert_vars_t;

typedef struct  {
  uint8_t EvInverterSMN[33];
  uint8_t EvCertificationDate[8];
  uint8_t EvUpdateTime[8];
} ev_cert_strings_t;

typedef struct  {
  uint16_t SePwrCtrlModesSpt;
  uint16_t SeWMaxEVSE;
  uint16_t SeChaWMaxEVSE;
  uint16_t SeIvarMaxEVSE;
  uint16_t SeAvarMaxEVSE;
  uint8_t SeFreqOver1FreqA;
  uint16_t SeFreqOver1TimeA;
  uint8_t SeFreqOver2FreqA;
  uint16_t SeFreqOver2TimeA;
  uint8_t SeFreqUnder1FreqA;
  uint16_t SeFreqUnder1TimeA;
  uint8_t SeFreqUnder2FreqA;
  uint16_t SeFreqUnder2TimeA;
  uint16_t SeLV3hLV2lLNA;
  uint16_t SeLV3TimeA;
  uint16_t SeLV2hLV1lLNA;
  uint16_t SeLV2TimeA;
  uint16_t SeLV1hLNA;
  uint16_t SeLV1TimeA;
  uint16_t SeHV1lLNA;
  uint16_t SeHV1TimeA;
  uint16_t SeHV1hHV2lLNA;
  uint16_t SeHV2TimeA;
} se_cert_vars_t;

typedef struct  {
  uint8_t SeUpdateTimeEVSE[8];
} se_cert_strings_t;

typedef struct  {
  ev_cert_strings_t  s;
  ev_cert_vars_t     v;
} ev_cert_t;

typedef struct  {
  se_cert_strings_t  s;
  se_cert_vars_t     v;
} se_cert_t;

#ifdef EV_CONFIG
  ev_cert_t cert_xmit_buff_1_A = {{
    {'D','2','4','X','X','X','U','D','B','M','P','U','R','2','x','4','-','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','\0'},
    {'a','b','c','d','e','f','g','\0'},
    {'a','b','c','d','e','f','g','\0'},
  }};
  ev_cert_t cert_xmit_buff_2_A = {{
    {'D','2','4','X','X','X','U','D','B','M','P','U','R','2','x','4','-','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','\0'},
    {'a','b','c','d','e','f','g','\0'},
    {'a','b','c','d','e','f','g','\0'},
  }};
  ev_cert_t cert_xmit_buff_1_B = {{
    {'D','2','4','X','X','X','U','D','B','M','P','U','R','2','x','4','-','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','\0'},
    {'a','b','c','d','e','f','g','\0'},
    {'a','b','c','d','e','f','g','\0'},
  }};
  ev_cert_t cert_xmit_buff_2_B = {{
    {'D','2','4','X','X','X','U','D','B','M','P','U','R','2','x','4','-','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1','\0'},
    {'a','b','c','d','e','f','g','\0'},
    {'a','b','c','d','e','f','g','\0'},
  }};
  se_cert_t cert_rcv_buff_1_A, cert_rcv_buff_2_A, cert_rcv_buff_1_B, cert_rcv_buff_2_B;
  ev_cert_t *act_cert_xmit[2], *inact_cert_xmit[2];
  se_cert_t *act_cert_rcv[2], *inact_cert_rcv[2];
#else
  se_cert_t cert_xmit_buff_1_A = {{
    {'a','b','c','d','1','2','3','\0'},
  }};
  se_cert_t cert_xmit_buff_2_A = {{
    {'a','b','c','d','1','2','3','\0'},
  }};
  se_cert_t cert_xmit_buff_1_B = {{
    {'a','b','c','d','1','2','3','\0'},
  }};
  se_cert_t cert_xmit_buff_2_B = {{
    {'a','b','c','d','1','2','3','\0'},
  }};
  ev_cert_t cert_rcv_buff_1_A, cert_rcv_buff_2_A, cert_rcv_buff_1_B, cert_rcv_buff_2_B;
  se_cert_t *act_cert_xmit[2], *inact_cert_xmit[2];
  ev_cert_t *act_cert_rcv[2], *inact_cert_rcv[2];
#endif

///<Declarations

///>pgs_to_send
#ifdef EV_CONFIG
#define NUM_CERT_PGS2SND 12
uint8_t cert_pages_to_send[NUM_CERT_PGS2SND] = { 0, 1, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, };
#else
#define NUM_CERT_PGS2SND 10
uint8_t cert_pages_to_send[NUM_CERT_PGS2SND] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, };
#endif
///<pgs_to_send

static bool first_data[2] = {FALSE, FALSE};

///>j3072_init()

#ifdef EV_CONFIG
void clear_cert_xmit_buff(ev_cert_t *cert_xmit_buff)  {
  mem_init(&(cert_xmit_buff->v), (uint8_t)sizeof(ev_cert_vars_t), 0xFF);
}
void clear_cert_rcv_buff(se_cert_t *cert_rcv_buff)  {
  mem_init(&(cert_rcv_buff->v), (uint8_t)sizeof(se_cert_vars_t), 0xFF);
  mem_init(&(cert_rcv_buff->s), (uint8_t)sizeof(se_cert_strings_t), 0x00);
}
#else
void clear_cert_xmit_buff(se_cert_t *cert_xmit_buff)  {
  mem_init(&(cert_xmit_buff->v), (uint8_t)sizeof(se_cert_vars_t), 0xFF);
}
void clear_cert_rcv_buff(ev_cert_t *cert_rcv_buff)  {
  mem_init(&(cert_rcv_buff->v), (uint8_t)sizeof(ev_cert_vars_t), 0xFF);
  mem_init(&(cert_rcv_buff->s), (uint8_t)sizeof(ev_cert_strings_t), 0x00);
}
#endif


void j3072_init(uint8_t ch) {
  se_j3072_status[ch] = CERT_INCOMPLETE;
  ev_j3072_status[ch] = CERT_INCOMPLETE;
  first_data[ch]= FALSE;

  act_cert_xmit[ch] = ch ? &cert_xmit_buff_1_B : &cert_xmit_buff_1_A;
  inact_cert_xmit[ch] = ch ? &cert_xmit_buff_2_B : &cert_xmit_buff_2_A;
  act_cert_rcv[ch] = ch ? &cert_rcv_buff_1_B : &cert_rcv_buff_1_A;
  inact_cert_rcv[ch] = ch ? &cert_rcv_buff_2_B : &cert_rcv_buff_2_A;

  clear_cert_xmit_buff(act_cert_xmit[ch]);
  clear_cert_xmit_buff(inact_cert_xmit[ch]);
  clear_cert_rcv_buff(act_cert_rcv[ch]);
  clear_cert_rcv_buff(inact_cert_rcv[ch]);
  cert_xmit(ch, 0); //preload the control page

///<j3072_init()

#ifdef EV_CONFIG

#define LC_J3072_STATUS(ch)        ev_j3072_status[ch]
#define RM_J3072_STATUS(ch)        se_j3072_status[ch]
#define READ_LC_PAGE_NUMBER(ch)    LR(ch, l_u8, EvJ3072Page)
#define READ_RM_PAGE_NUMBER(ch)    LR(ch, l_u8, SeJ3072Page)
#define READ_RM_BYTE_A(ch)         LR(ch, l_u8, SeJ3072ByteA)

#else

#define LC_J3072_STATUS(ch)        se_j3072_status[ch]
#define RM_J3072_STATUS(ch)        ev_j3072_status[ch]
#define READ_LC_PAGE_NUMBER(ch)    LR(ch, l_u8, SeJ3072Page)
#define READ_RM_PAGE_NUMBER(ch)    LR(ch, l_u8, EvJ3072Page)
#define READ_RM_BYTE_A(ch)         LR(ch, l_u8, EvJ3072ByteA)

#endif
}

void on_j3072_frame_receipt(uint8_t ch)  {
  if (READ_RM_PAGE_NUMBER(ch) == 0)  {   //make sure we are always reading the status
    RM_J3072_STATUS(ch) = READ_RM_BYTE_A(ch);
  }

  if (LC_J3072_STATUS(ch) == CERT_INCOMPLETE && cert_parse(ch)) {
    LC_J3072_STATUS(ch) = CERT_COMPLETE;

#ifdef EV_CONFIG

#else

#endif
  }

  if (LC_J3072_STATUS(ch) == CERT_COMPLETE && (RM_J3072_STATUS(ch) == CERT_COMPLETE || RM_J3072_STATUS(ch) == SUNSPEC))  {
    PrintConsoleString("====CERT COMPLETE!!!!===\r\n",0);
    LC_J3072_STATUS(ch) = SUNSPEC;
    first_data[ch] = TRUE;
  }

  if (LC_J3072_STATUS(ch) == SUNSPEC ) {
    if (RM_J3072_STATUS(ch) == SUNSPEC)  {
      //SunSpec not implemented at this time
    }
  }
}

void on_j3072_frame_xmit(uint8_t ch) {
  static uint8_t xmit_pgs_indx[2] = {0, 0};
  void* temp_ptr;

  if (LC_J3072_STATUS(ch) == CERT_INCOMPLETE || LC_J3072_STATUS(ch) == CERT_COMPLETE) {
    if (xmit_pgs_indx[ch] == NUM_CERT_PGS2SND-1)  {
      xmit_pgs_indx[ch] = 0;
      temp_ptr = inact_cert_xmit[ch];            //swap cert xmit buffers
      inact_cert_xmit[ch] = act_cert_xmit[ch];
      act_cert_xmit[ch] = temp_ptr;
      //don't clear cert xmit buffers as info is static
    } else  {
      xmit_pgs_indx[ch]++;
    }
    cert_xmit(ch, cert_pages_to_send[xmit_pgs_indx[ch]]);
  }

  if (LC_J3072_STATUS(ch) == SUNSPEC ) {
    //SunSpec not implemented at this time
#ifdef EV_CONFIG
    LW(ch, l_u8, EvJ3072Page, 0);
    LW(ch, l_u8, EvJ3072ByteA, ev_j3072_status[ch]);   //status
    LW(ch, l_u8, EvJ3072ByteB, 0);                     //number of pages
    LW(ch, l_u8, EvJ3072ByteC, 0xFF);                  //first page
    LW(ch, l_u8, EvJ3072ByteD, 0xFF);                  //last page
    LW(ch, l_u8, EvJ3072ByteE, 0x00);                  //CRC status
    LW(ch, l_u8, EvJ3072ByteF, 0xFF);                  //unused
    LW(ch, l_u8, EvJ3072ByteG, 0xFF);                  //unused
#else
    LW(ch, l_u8, SeJ3072Page, 0);
    LW(ch, l_u8, SeJ3072ByteA, se_j3072_status[ch]);   //status
    LW(ch, l_u8, SeJ3072ByteB, 0);                     //number of pages
    LW(ch, l_u8, SeJ3072ByteC, 0xFF);                  //first page
    LW(ch, l_u8, SeJ3072ByteD, 0xFF);                  //last page
    LW(ch, l_u8, SeJ3072ByteE, 0x00);                  //CRC status
    LW(ch, l_u8, SeJ3072ByteF, 0xFF);                  //unused
    LW(ch, l_u8, SeJ3072ByteG, 0xFF);                  //unused
#endif
  }
}

#ifdef EV_CONFIG

bool cert_parse(uint8_t ch) {
  static uint8_t buffer[7];
  static uint8_t pgs_to_read[2] = {255, 255};
  static uint8_t pgs_read[2] = {0, 0};
  static uint8_t last_pg[2] = {255, 255};

  uint8_t copy_size = 7;
  uint8_t * source_ptr = buffer;
  uint8_t * dest_ptr = NULL;
  bool is_string = TRUE;

  void * temp_ptr;

  buffer[0] = LR(ch, l_u8, SeJ3072ByteA);
  buffer[1] = LR(ch, l_u8, SeJ3072ByteB);
  buffer[2] = LR(ch, l_u8, SeJ3072ByteC);
  buffer[3] = LR(ch, l_u8, SeJ3072ByteD);
  buffer[4] = LR(ch, l_u8, SeJ3072ByteE);
  buffer[5] = LR(ch, l_u8, SeJ3072ByteF);
  buffer[6] = LR(ch, l_u8, SeJ3072ByteG);

  //printf("-->%c%c\n", buffer[0], buffer[1]);
  //printf("page:%d\n", l_u8_rd_LI0_EvJ3072Page());

  pgs_read[ch]++;

  ///>ev_cert_parse
  switch(LR(ch, l_u8, SeJ3072Page)) {
    case 0:
      pgs_to_read[ch] = buffer[1];
      se_j3072_status[ch] = buffer[0];
      last_pg[ch] = buffer[3];
      pgs_read[ch] = 1;
        clear_cert_rcv_buff(act_cert_rcv[ch]);  //clear rcv buffer on control page to remove data from corrupted cycle
      break;
    case 1:
      (act_cert_rcv[ch]->v).SePwrCtrlModesSpt = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("SePwrCtrlModesSpt 0x%02X \n", ((act_cert_rcv[ch]->v).SePwrCtrlModesSpt));
      (act_cert_rcv[ch]->v).SeWMaxEVSE = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("SeWMaxEVSE %d W\n", ((act_cert_rcv[ch]->v).SeWMaxEVSE * 16) - 500000);
      (act_cert_rcv[ch]->v).SeChaWMaxEVSE = ((uint16_t)buffer[5] << 8) | ((uint16_t)buffer[4]);
      //printf("SeChaWMaxEVSE %d W\n", ((act_cert_rcv[ch]->v).SeChaWMaxEVSE * 16) - 500000);
      break;
    case 2:
      (act_cert_rcv[ch]->v).SeIvarMaxEVSE = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("SeIvarMaxEVSE %d VA\n", ((act_cert_rcv[ch]->v).SeIvarMaxEVSE * 16) - 500000);
      (act_cert_rcv[ch]->v).SeAvarMaxEVSE = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("SeAvarMaxEVSE %d VA\n", ((act_cert_rcv[ch]->v).SeAvarMaxEVSE * 16) - 500000);
      break;
    case 3:
      dest_ptr = (uint8_t *) (act_cert_rcv[ch]->s).SeUpdateTimeEVSE;
      break;
    case 4:
      (act_cert_rcv[ch]->v).SeFreqOver1FreqA = ((uint8_t)buffer[0]);
      //printf("SeFreqOver1FreqA %.3lf Hz\n", ((double)(act_cert_rcv[ch]->v).SeFreqOver1FreqA * 0.100000) - -42.500000);
      (act_cert_rcv[ch]->v).SeFreqOver1TimeA = ((uint16_t)buffer[2] << 8) | ((uint16_t)buffer[1]);
      //printf("SeFreqOver1TimeA %.3lf seconds\n", ((double)(act_cert_rcv[ch]->v).SeFreqOver1TimeA * 0.010000));
      (act_cert_rcv[ch]->v).SeFreqOver2FreqA = ((uint8_t)buffer[3]);
      //printf("SeFreqOver2FreqA %.3lf Hz\n", ((double)(act_cert_rcv[ch]->v).SeFreqOver2FreqA * 0.100000) - -42.500000);
      (act_cert_rcv[ch]->v).SeFreqOver2TimeA = ((uint16_t)buffer[5] << 8) | ((uint16_t)buffer[4]);
      //printf("SeFreqOver2TimeA %.3lf seconds\n", ((double)(act_cert_rcv[ch]->v).SeFreqOver2TimeA * 0.010000));
      break;
    case 5:
      (act_cert_rcv[ch]->v).SeFreqUnder1FreqA = ((uint8_t)buffer[0]);
      //printf("SeFreqUnder1FreqA %.3lf Hz\n", ((double)(act_cert_rcv[ch]->v).SeFreqUnder1FreqA * 0.100000) - -42.500000);
      (act_cert_rcv[ch]->v).SeFreqUnder1TimeA = ((uint16_t)buffer[2] << 8) | ((uint16_t)buffer[1]);
      //printf("SeFreqUnder1TimeA %.3lf seconds\n", ((double)(act_cert_rcv[ch]->v).SeFreqUnder1TimeA * 0.010000));
      (act_cert_rcv[ch]->v).SeFreqUnder2FreqA = ((uint8_t)buffer[3]);
      //printf("SeFreqUnder2FreqA %.3lf Hz\n", ((double)(act_cert_rcv[ch]->v).SeFreqUnder2FreqA * 0.100000) - -42.500000);
      (act_cert_rcv[ch]->v).SeFreqUnder2TimeA = ((uint16_t)buffer[5] << 8) | ((uint16_t)buffer[4]);
      //printf("SeFreqUnder2TimeA %.3lf seconds\n", ((double)(act_cert_rcv[ch]->v).SeFreqUnder2TimeA * 0.010000));
      break;
    case 6:
      (act_cert_rcv[ch]->v).SeLV3hLV2lLNA = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("SeLV3hLV2lLNA %.3lf Volts\n", ((double)(act_cert_rcv[ch]->v).SeLV3hLV2lLNA * 0.050000));
      (act_cert_rcv[ch]->v).SeLV3TimeA = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("SeLV3TimeA %.3lf seconds\n", ((double)(act_cert_rcv[ch]->v).SeLV3TimeA * 0.010000));
      (act_cert_rcv[ch]->v).SeLV2hLV1lLNA = ((uint16_t)buffer[5] << 8) | ((uint16_t)buffer[4]);
      //printf("SeLV2hLV1lLNA %.3lf Volts\n", ((double)(act_cert_rcv[ch]->v).SeLV2hLV1lLNA * 0.050000));
      break;
    case 7:
      (act_cert_rcv[ch]->v).SeLV2TimeA = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("SeLV2TimeA %.3lf seconds\n", ((double)(act_cert_rcv[ch]->v).SeLV2TimeA * 0.010000));
      (act_cert_rcv[ch]->v).SeLV1hLNA = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("SeLV1hLNA %.3lf Volts\n", ((double)(act_cert_rcv[ch]->v).SeLV1hLNA * 0.050000));
      (act_cert_rcv[ch]->v).SeLV1TimeA = ((uint16_t)buffer[5] << 8) | ((uint16_t)buffer[4]);
      //printf("SeLV1TimeA %.3lf seconds\n", ((double)(act_cert_rcv[ch]->v).SeLV1TimeA * 0.010000));
      break;
    case 8:
      (act_cert_rcv[ch]->v).SeHV1lLNA = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("SeHV1lLNA %.3lf Volts\n", ((double)(act_cert_rcv[ch]->v).SeHV1lLNA * 0.050000));
      (act_cert_rcv[ch]->v).SeHV1TimeA = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("SeHV1TimeA %.3lf seconds\n", ((double)(act_cert_rcv[ch]->v).SeHV1TimeA * 0.010000));
      break;
    case 9:
      (act_cert_rcv[ch]->v).SeHV1hHV2lLNA = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("SeHV1hHV2lLNA %.3lf Volts\n", ((double)(act_cert_rcv[ch]->v).SeHV1hHV2lLNA * 0.050000));
      (act_cert_rcv[ch]->v).SeHV2TimeA = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("SeHV2TimeA %.3lf seconds\n", ((double)(act_cert_rcv[ch]->v).SeHV2TimeA * 0.010000));
      break;
  }
  ///<ev_cert_parse

  //printf("pointer:%p\n",dest_ptr);

  //fflush(stdout);

  if (dest_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, is_string);
  }

  if ((pgs_read[ch] == pgs_to_read[ch]) && (LR(ch, l_u8, SeJ3072Page) == last_pg[ch]))  {
    temp_ptr = inact_cert_rcv[ch];            //swap cert rcv buffers
    inact_cert_rcv[ch] = act_cert_rcv[ch];
    act_cert_rcv[ch] = temp_ptr;
    clear_cert_rcv_buff(act_cert_rcv[ch]);    //clear new buffer
    return TRUE;
  } else  {
    return FALSE;
  }
}

void cert_xmit(uint8_t ch, uint8_t page){
  static uint8_t buffer[7];
  uint8_t mask = 0;

  uint8_t copy_size = 7;
  uint8_t * dest_ptr = buffer;
  uint8_t * source_ptr = NULL;

  ///>ev_cert_xmit
  switch(page) {
    case 0:
      buffer[0] = ev_j3072_status[ch];
      buffer[1] = 12; //pages to be sent
      buffer[2] =  1; //first (non zero) page
      buffer[3] = 14; //last page
      buffer[4] = 0x00; //CRC neither sent nor read
      mask = 0b0000011;
      break;
    case 1:
      buffer[0] = ((act_cert_xmit[ch]->v).EvPwrCtrlModesSpt) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).EvPwrCtrlModesSpt >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).EvSupGridCode1) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).EvSupGridCode1 >> 8) & 0xFF;
      mask = 0b0000111;
      break;
    case 5:
      buffer[0] = ((act_cert_xmit[ch]->v).EvVRefL1N) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).EvVRefL1N >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).EvVRefLL) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).EvVRefLL >> 8) & 0xFF;
      mask = 0b0000111;
      break;
    case 6:
      buffer[0] = ((act_cert_xmit[ch]->v).EvWMaxRtg) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).EvWMaxRtg >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).EvVAMaxRtg) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).EvVAMaxRtg >> 8) & 0xFF;
      buffer[4] = ((act_cert_xmit[ch]->v).EvIvarMaxRtg) & 0xFF;
      buffer[5] = ((act_cert_xmit[ch]->v).EvIvarMaxRtg >> 8) & 0xFF;
      mask = 0b0000001;
      break;
    case 7:
      buffer[0] = ((act_cert_xmit[ch]->v).EvAvarMaxRtg) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).EvAvarMaxRtg >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).EvChaWMaxRtg) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).EvChaWMaxRtg >> 8) & 0xFF;
      buffer[4] = ((act_cert_xmit[ch]->v).EvChaVAMaxRtg) & 0xFF;
      buffer[5] = ((act_cert_xmit[ch]->v).EvChaVAMaxRtg >> 8) & 0xFF;
      mask = 0b0000001;
      break;
    case 8:
      source_ptr = (uint8_t *) (act_cert_xmit[ch]->s).EvInverterSMN;
      break;
    case 9:
      source_ptr = (uint8_t *) (act_cert_xmit[ch]->s).EvInverterSMN + 7;
      break;
    case 10:
      source_ptr = (uint8_t *) (act_cert_xmit[ch]->s).EvInverterSMN + 14;
      break;
    case 11:
      source_ptr = (uint8_t *) (act_cert_xmit[ch]->s).EvInverterSMN + 21;
      break;
    case 12:
      source_ptr = (uint8_t *) (act_cert_xmit[ch]->s).EvInverterSMN + 28;
      copy_size = 4;
      mask = 0b0000111;
      break;
    case 13:
      source_ptr = (uint8_t *) (act_cert_xmit[ch]->s).EvCertificationDate;
      break;
    case 14:
      source_ptr = (uint8_t *) (act_cert_xmit[ch]->s).EvUpdateTime;
      break;
  }
  ///<ev_cert_xmit


  if (source_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, TRUE);
  }

  invalidate_bytes_page(buffer, mask);

  LW(ch, l_u8, EvJ3072Page, page);
  LW(ch, l_u8, EvJ3072ByteA, buffer[0]);
  LW(ch, l_u8, EvJ3072ByteB, buffer[1]);
  LW(ch, l_u8, EvJ3072ByteC, buffer[2]);
  LW(ch, l_u8, EvJ3072ByteD, buffer[3]);
  LW(ch, l_u8, EvJ3072ByteE, buffer[4]);
  LW(ch, l_u8, EvJ3072ByteF, buffer[5]);
  LW(ch, l_u8, EvJ3072ByteG, buffer[6]);
}


#else
bool cert_parse(uint8_t ch) {
  static uint8_t buffer[7];
  static uint8_t pgs_to_read[2] = {255, 255};
  static uint8_t pgs_read[2] = {0, };
  static uint8_t last_pg[2] = {255, 255};

  uint8_t copy_size = 7;
  uint8_t * source_ptr = buffer;
  uint8_t * dest_ptr = NULL;
  bool is_string = TRUE;

  void* temp_ptr;

  buffer[0] = LR(ch, l_u8, EvJ3072ByteA);
  buffer[1] = LR(ch, l_u8, EvJ3072ByteB);
  buffer[2] = LR(ch, l_u8, EvJ3072ByteC);
  buffer[3] = LR(ch, l_u8, EvJ3072ByteD);
  buffer[4] = LR(ch, l_u8, EvJ3072ByteE);
  buffer[5] = LR(ch, l_u8, EvJ3072ByteF);
  buffer[6] = LR(ch, l_u8, EvJ3072ByteG);

  //printf("-->%c%c\n", buffer[0], buffer[1]);
  //printf("page:%d\n", l_u8_rd_LI0_EvJ3072Page());

  pgs_read[ch]++;

  ///>se_cert_parse
  switch(LR(ch, l_u8, EvJ3072Page)) {
    case 0:
      pgs_to_read[ch] = buffer[1];
      ev_j3072_status[ch] = buffer[0];
      last_pg[ch] = buffer[3];
      pgs_read[ch] = 1;
        clear_cert_rcv_buff(act_cert_rcv[ch]);  //clear rcv buffer on control page to remove data from corrupted cycle
      break;
    case 1:
      (act_cert_rcv[ch]->v).EvPwrCtrlModesSpt = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("EvPwrCtrlModesSpt 0x%02X \n", ((act_cert_rcv[ch]->v).EvPwrCtrlModesSpt));
      (act_cert_rcv[ch]->v).EvSupGridCode1 = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("EvSupGridCode1 0x%02X \n", ((act_cert_rcv[ch]->v).EvSupGridCode1));
      break;
    case 5:
      (act_cert_rcv[ch]->v).EvVRefL1N = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("EvVRefL1N %.3lf Volts\n", ((double)(act_cert_rcv[ch]->v).EvVRefL1N * 0.050000));
      (act_cert_rcv[ch]->v).EvVRefLL = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("EvVRefLL %.3lf Volts\n", ((double)(act_cert_rcv[ch]->v).EvVRefLL * 0.050000));
      break;
    case 6:
      (act_cert_rcv[ch]->v).EvWMaxRtg = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("EvWMaxRtg %d W\n", ((act_cert_rcv[ch]->v).EvWMaxRtg * 16) - 500000);
      (act_cert_rcv[ch]->v).EvVAMaxRtg = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("EvVAMaxRtg %d VA\n", ((act_cert_rcv[ch]->v).EvVAMaxRtg * 16) - 500000);
      (act_cert_rcv[ch]->v).EvIvarMaxRtg = ((uint16_t)buffer[5] << 8) | ((uint16_t)buffer[4]);
      //printf("EvIvarMaxRtg %d VA\n", ((act_cert_rcv[ch]->v).EvIvarMaxRtg * 16) - 500000);
      break;
    case 7:
      (act_cert_rcv[ch]->v).EvAvarMaxRtg = ((uint16_t)buffer[1] << 8) | ((uint16_t)buffer[0]);
      //printf("EvAvarMaxRtg %d VA\n", ((act_cert_rcv[ch]->v).EvAvarMaxRtg * 16) - 500000);
      (act_cert_rcv[ch]->v).EvChaWMaxRtg = ((uint16_t)buffer[3] << 8) | ((uint16_t)buffer[2]);
      //printf("EvChaWMaxRtg %d W\n", ((act_cert_rcv[ch]->v).EvChaWMaxRtg * 16) - 500000);
      (act_cert_rcv[ch]->v).EvChaVAMaxRtg = ((uint16_t)buffer[5] << 8) | ((uint16_t)buffer[4]);
      //printf("EvChaVAMaxRtg %d VA\n", ((act_cert_rcv[ch]->v).EvChaVAMaxRtg * 16) - 500000);
      break;
    case 8:
      dest_ptr = (uint8_t *) (act_cert_rcv[ch]->s).EvInverterSMN;
      break;
    case 9:
      dest_ptr = (uint8_t *) (act_cert_rcv[ch]->s).EvInverterSMN + 7;
      break;
    case 10:
      dest_ptr = (uint8_t *) (act_cert_rcv[ch]->s).EvInverterSMN + 14;
      break;
    case 11:
      dest_ptr = (uint8_t *) (act_cert_rcv[ch]->s).EvInverterSMN + 21;
      break;
    case 12:
      dest_ptr = (uint8_t *) (act_cert_rcv[ch]->s).EvInverterSMN + 28;
      copy_size = 4;
      break;
    case 13:
      dest_ptr = (uint8_t *) (act_cert_rcv[ch]->s).EvCertificationDate;
      break;
    case 14:
      dest_ptr = (uint8_t *) (act_cert_rcv[ch]->s).EvUpdateTime;
      break;
  }
  ///<se_cert_parse

  ////printf("pointer:%p\n",dest_ptr);

  //fflush(stdout);

  if (dest_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, is_string);
  }

  if ((pgs_read[ch] == pgs_to_read[ch]) && (LR(ch, l_u8, EvJ3072Page) == last_pg[ch]))  {
    temp_ptr = inact_cert_rcv[ch];            //swapcert rcv buffers
    inact_cert_rcv[ch] = act_cert_rcv[ch];
    act_cert_rcv[ch] = temp_ptr;
    clear_cert_rcv_buff(act_cert_rcv[ch]);    //clear new buffer
    return TRUE;
  } else  {
    return FALSE;
  }
}

void cert_xmit(uint8_t ch, uint8_t page){
  static uint8_t buffer[7];
  uint8_t mask = 0;

  uint8_t copy_size = 7;
  uint8_t * dest_ptr = buffer;
  uint8_t * source_ptr = NULL;

  ///>se_cert_xmit
  switch(page) {
    case 0:
      buffer[0] = se_j3072_status[ch];
      buffer[1] = 10; //pages to be sent
      buffer[2] =  1; //first (non zero) page
      buffer[3] =  9; //last page
      buffer[4] = 0x00; //CRC neither sent nor read
      mask = 0b0000011;
      break;
    case 1:
      buffer[0] = ((act_cert_xmit[ch]->v).SePwrCtrlModesSpt) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).SePwrCtrlModesSpt >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).SeWMaxEVSE) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).SeWMaxEVSE >> 8) & 0xFF;
      buffer[4] = ((act_cert_xmit[ch]->v).SeChaWMaxEVSE) & 0xFF;
      buffer[5] = ((act_cert_xmit[ch]->v).SeChaWMaxEVSE >> 8) & 0xFF;
      mask = 0b0000001;
      break;
    case 2:
      buffer[0] = ((act_cert_xmit[ch]->v).SeIvarMaxEVSE) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).SeIvarMaxEVSE >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).SeAvarMaxEVSE) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).SeAvarMaxEVSE >> 8) & 0xFF;
      mask = 0b0000111;
      break;
    case 3:
      source_ptr = (uint8_t *) (act_cert_xmit[ch]->s).SeUpdateTimeEVSE;
      break;
    case 4:
      buffer[0] = ((act_cert_xmit[ch]->v).SeFreqOver1FreqA) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).SeFreqOver1TimeA) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).SeFreqOver1TimeA >> 8) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).SeFreqOver2FreqA) & 0xFF;
      buffer[4] = ((act_cert_xmit[ch]->v).SeFreqOver2TimeA) & 0xFF;
      buffer[5] = ((act_cert_xmit[ch]->v).SeFreqOver2TimeA >> 8) & 0xFF;
      mask = 0b0000001;
      break;
    case 5:
      buffer[0] = ((act_cert_xmit[ch]->v).SeFreqUnder1FreqA) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).SeFreqUnder1TimeA) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).SeFreqUnder1TimeA >> 8) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).SeFreqUnder2FreqA) & 0xFF;
      buffer[4] = ((act_cert_xmit[ch]->v).SeFreqUnder2TimeA) & 0xFF;
      buffer[5] = ((act_cert_xmit[ch]->v).SeFreqUnder2TimeA >> 8) & 0xFF;
      mask = 0b0000001;
      break;
    case 6:
      buffer[0] = ((act_cert_xmit[ch]->v).SeLV3hLV2lLNA) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).SeLV3hLV2lLNA >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).SeLV3TimeA) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).SeLV3TimeA >> 8) & 0xFF;
      buffer[4] = ((act_cert_xmit[ch]->v).SeLV2hLV1lLNA) & 0xFF;
      buffer[5] = ((act_cert_xmit[ch]->v).SeLV2hLV1lLNA >> 8) & 0xFF;
      mask = 0b0000001;
      break;
    case 7:
      buffer[0] = ((act_cert_xmit[ch]->v).SeLV2TimeA) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).SeLV2TimeA >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).SeLV1hLNA) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).SeLV1hLNA >> 8) & 0xFF;
      buffer[4] = ((act_cert_xmit[ch]->v).SeLV1TimeA) & 0xFF;
      buffer[5] = ((act_cert_xmit[ch]->v).SeLV1TimeA >> 8) & 0xFF;
      mask = 0b0000001;
      break;
    case 8:
      buffer[0] = ((act_cert_xmit[ch]->v).SeHV1lLNA) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).SeHV1lLNA >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).SeHV1TimeA) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).SeHV1TimeA >> 8) & 0xFF;
      mask = 0b0000111;
      break;
    case 9:
      buffer[0] = ((act_cert_xmit[ch]->v).SeHV1hHV2lLNA) & 0xFF;
      buffer[1] = ((act_cert_xmit[ch]->v).SeHV1hHV2lLNA >> 8) & 0xFF;
      buffer[2] = ((act_cert_xmit[ch]->v).SeHV2TimeA) & 0xFF;
      buffer[3] = ((act_cert_xmit[ch]->v).SeHV2TimeA >> 8) & 0xFF;
      mask = 0b0000111;
      break;
  }
  ///<se_cert_xmit


  if (source_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, TRUE);
  }

  invalidate_bytes_page(buffer, mask);

  LW(ch, l_u8, SeJ3072Page, page);
  LW(ch, l_u8, SeJ3072ByteA, buffer[0]);
  LW(ch, l_u8, SeJ3072ByteB, buffer[1]);
  LW(ch, l_u8, SeJ3072ByteC, buffer[2]);
  LW(ch, l_u8, SeJ3072ByteD, buffer[3]);
  LW(ch, l_u8, SeJ3072ByteE, buffer[4]);
  LW(ch, l_u8, SeJ3072ByteF, buffer[5]);
  LW(ch, l_u8, SeJ3072ByteG, buffer[6]);
}


#endif
