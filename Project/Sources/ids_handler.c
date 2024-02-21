#include "lin-cp.h"
#include "globals.h"
#include "ids_handler.h"
#include "utils.h"

uint8_t ev_id_status[2] = {ID_INCOMPLETE, ID_INCOMPLETE};
uint8_t se_id_status[2] = {ID_INCOMPLETE, ID_INCOMPLETE};

///>Declarations

#define SERMTMGMTSTATUS_CONNECTED 0x00
#define SERMTMGMTSTATUS_CONNECTING 0x01
#define SERMTMGMTSTATUS_NOT_CONNECTED 0x02
#define SERMTMGMTSTATUS_FALLBACK 0x03
#define SERMTMGMTSTATUS_LOCAL 0x04
#define SERMTMGMTSTATUS_ERROR 0xFE
#define SERMTMGMTSTATUS_NONE_OR_STATUS_UNKNOWN 0xFF

typedef struct  {
  uint8_t EvVIN[18];
  uint8_t EvVehicleName[22];
  uint8_t EvFirmwareRevision[29];
  uint8_t EvManufacturer[43];
} ev_ids_strings_t;

typedef struct  {
  uint8_t SeSerialNum[43];
  uint8_t SeFirmwareRevision[29];
  uint8_t SeManufacturer[43];
} se_ids_strings_t;

typedef struct  {
  uint32_t EvOdometer;
} ev_data_vars_t;

typedef struct  {
  uint8_t SeRmtMgmtStatus;
} se_data_vars_t;

typedef struct  {
  ev_ids_strings_t  s;
} ev_ids_t;

typedef struct  {
  se_ids_strings_t  s;
} se_ids_t;

typedef struct  {
  ev_data_vars_t    v;
} ev_data_t;

typedef struct  {
  se_data_vars_t    v;
} se_data_t;

#ifdef EV_CONFIG
  ev_ids_t ids_xmit_buff_1_A = {{
    {'V','I','N','g','o','e','s','H','e','r','e','2','3','4','5','6','7','\0'},
    {'V','e','h','i','c','l','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'F','i','r','m','w','a','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'M','a','n','u','f','a','c','t','u','r','e','r','G','o','e','s','H','e','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
  }};
  ev_ids_t ids_xmit_buff_2_A = {{
    {'V','I','N','g','o','e','s','H','e','r','e','2','3','4','5','6','7','\0'},
    {'V','e','h','i','c','l','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'F','i','r','m','w','a','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'M','a','n','u','f','a','c','t','u','r','e','r','G','o','e','s','H','e','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
  }};
  ev_ids_t ids_xmit_buff_1_B = {{
    {'V','I','N','g','o','e','s','H','e','r','e','2','3','4','5','6','7','\0'},
    {'V','e','h','i','c','l','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'F','i','r','m','w','a','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'M','a','n','u','f','a','c','t','u','r','e','r','G','o','e','s','H','e','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
  }};
  ev_ids_t ids_xmit_buff_2_B = {{
    {'V','I','N','g','o','e','s','H','e','r','e','2','3','4','5','6','7','\0'},
    {'V','e','h','i','c','l','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'F','i','r','m','w','a','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'M','a','n','u','f','a','c','t','u','r','e','r','G','o','e','s','H','e','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
  }};
  ev_data_t data_xmit_buff_1_A;
  ev_data_t data_xmit_buff_2_A;
  ev_data_t data_xmit_buff_1_B;
  ev_data_t data_xmit_buff_2_B;
  ev_ids_t *act_ids_xmit[2], *inact_ids_xmit[2];
  se_ids_t ids_rcv_buff_1_A, ids_rcv_buff_2_A, ids_rcv_buff_1_B, ids_rcv_buff_2_B, *act_ids_rcv[2], *inact_ids_rcv[2];
  ev_data_t *act_data_xmit[2], *inact_data_xmit[2];
  se_data_t data_rcv_buff_1_A, data_rcv_buff_2_A, data_rcv_buff_1_B, data_rcv_buff_2_B, *act_data_rcv[2], *inact_data_rcv[2];
#else
  se_ids_t ids_xmit_buff_1_A = {{
    {'A','1','2','3','4','5','6','7','B','8','9','0','1','2','3','4',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'F','i','r','m','w','a','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'M','a','n','u','f','a','c','t','u','r','e','r',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
  }};
  se_ids_t ids_xmit_buff_2_A = {{
    {'A','1','2','3','4','5','6','7','B','8','9','0','1','2','3','4',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'F','i','r','m','w','a','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'M','a','n','u','f','a','c','t','u','r','e','r',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
  }};
  se_ids_t ids_xmit_buff_1_B = {{
    {'A','1','2','3','4','5','6','7','B','8','9','0','1','2','3','4',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'F','i','r','m','w','a','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'M','a','n','u','f','a','c','t','u','r','e','r',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
  }};
  se_ids_t ids_xmit_buff_2_B = {{
    {'A','1','2','3','4','5','6','7','B','8','9','0','1','2','3','4',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'F','i','r','m','w','a','r','e',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
    {'M','a','n','u','f','a','c','t','u','r','e','r',0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,'\0'},
  }};
  se_data_t data_xmit_buff_1_A;
  se_data_t data_xmit_buff_2_A;
  se_data_t data_xmit_buff_1_B;
  se_data_t data_xmit_buff_2_B;
  se_ids_t *act_ids_xmit[2], *inact_ids_xmit[2];
  ev_ids_t ids_rcv_buff_1_A, ids_rcv_buff_2_A, ids_rcv_buff_1_B, ids_rcv_buff_2_B, *act_ids_rcv[2], *inact_ids_rcv[2];
  se_data_t *act_data_xmit[2], *inact_data_xmit[2];
  ev_data_t data_rcv_buff_1_A, data_rcv_buff_2_A, data_rcv_buff_1_B, data_rcv_buff_2_B, *act_data_rcv[2], *inact_data_rcv[2];
#endif

///<Declarations

///>pgs_to_send
#ifdef EV_CONFIG
#define NUM_ID_PGS2SND 17
uint8_t id_pages_to_send[NUM_ID_PGS2SND] = { 0, 1, 2, 3, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, };
#define NUM_DATA_PGS2SND 2
uint8_t data_pages_to_send[NUM_DATA_PGS2SND] = { 0, 97, };
#else
#define NUM_ID_PGS2SND 17
uint8_t id_pages_to_send[NUM_ID_PGS2SND] = { 0, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, };
#define NUM_DATA_PGS2SND 2
uint8_t data_pages_to_send[NUM_DATA_PGS2SND] = { 0, 98, };
#endif
///<pgs_to_send

static bool first_data[2] = {FALSE, FALSE};

void copy_buffer_data(uint8_t * source, uint8_t * destination, uint8_t size, bool string) {
  uint8_t i;

  for(i=0; i<size; i++) {
    destination[i] = source[i];
    if(string)  {
      if (source[i] == 0xFF)  {
        destination[i] = '\0';
      }
    }
  }
}

void invalidate_bytes_page(uint8_t * buffer, uint8_t mask)  {
  uint8_t i;

  if (mask != 0)  {
    for(i=6; i<=6; i--) { //>=0 not working because unsigned?
      if (mask & 0b00000001)  {
        buffer[i] = 0xFF;
      }
      mask = mask >> 1;
    }
  }
}

///>ids_init()

#ifdef EV_CONFIG
void clear_ids_xmit_buff(ev_ids_t* ids_xmit_buff)  {
}
void clear_ids_rcv_buff(se_ids_t* ids_rcv_buff)  {
  mem_init(&(ids_rcv_buff->s), (uint8_t)sizeof(se_ids_strings_t), 0x00);
}
void clear_data_xmit_buff(ev_data_t* data_xmit_buff)  {
  mem_init(&(data_xmit_buff->v), (uint8_t)sizeof(ev_data_vars_t), 0xFF);
}
void clear_data_rcv_buff(se_data_t* data_rcv_buff)  {
  mem_init(&(data_rcv_buff->v), (uint8_t)sizeof(se_data_vars_t), 0xFF);
}
#else
void clear_ids_xmit_buff(se_ids_t* ids_xmit_buff)  {
}
void clear_ids_rcv_buff(ev_ids_t* ids_rcv_buff)  {
  mem_init(&(ids_rcv_buff->s), (uint8_t)sizeof(ev_ids_strings_t), 0x00);
}
void clear_data_xmit_buff(se_data_t* data_xmit_buff)  {
  mem_init(&(data_xmit_buff->v), (uint8_t)sizeof(se_data_vars_t), 0xFF);
}
void clear_data_rcv_buff(ev_data_t* data_rcv_buff)  {
  mem_init(&(data_rcv_buff->v), (uint8_t)sizeof(ev_data_vars_t), 0xFF);
}
#endif


void ids_init(uint8_t ch) {
  se_id_status[ch] = ID_INCOMPLETE;
  ev_id_status[ch] = ID_INCOMPLETE;
  first_data[ch]= FALSE;

  act_ids_xmit[ch] = ch ? &ids_xmit_buff_1_B : &ids_xmit_buff_1_A;
  inact_ids_xmit[ch] = ch ? &ids_xmit_buff_2_B : &ids_xmit_buff_2_A;
  act_ids_rcv[ch] = ch ? &ids_rcv_buff_1_B : &ids_rcv_buff_1_A;
  inact_ids_rcv[ch] = ch ? &ids_rcv_buff_2_B : &ids_rcv_buff_2_A;

  act_data_xmit[ch] = ch ? &data_xmit_buff_1_B : &data_xmit_buff_1_A;
  inact_data_xmit[ch] = ch ? &data_xmit_buff_2_B : &data_xmit_buff_2_A;
  act_data_rcv[ch] = ch ? &data_rcv_buff_1_B : &data_rcv_buff_1_A;
  inact_data_rcv[ch] = ch ? &data_rcv_buff_2_B : &data_rcv_buff_2_A;

  clear_ids_xmit_buff(act_ids_xmit[ch]);
  clear_ids_xmit_buff(inact_ids_xmit[ch]);
  clear_ids_rcv_buff(act_ids_rcv[ch]);
  clear_ids_rcv_buff(inact_ids_rcv[ch]);
  clear_data_xmit_buff(act_data_xmit[ch]);
  clear_data_xmit_buff(inact_data_xmit[ch]);
  clear_data_rcv_buff(act_data_rcv[ch]);
  clear_data_rcv_buff(inact_data_rcv[ch]);

  id_xmit(ch, 0); //preload the control page

#ifdef EV_CONFIG
#else
#endif
}

///<ids_init()

#ifdef EV_CONFIG

#define LC_ID_STATUS(ch)           ev_id_status[ch]
#define RM_ID_STATUS(ch)           se_id_status[ch]
#define READ_LC_PAGE_NUMBER(ch)    LR(ch, l_u8, EvIDPage)
#define READ_RM_PAGE_NUMBER(ch)    LR(ch, l_u8, SeIDPage)
#define READ_RM_BYTE_A(ch)         LR(ch, l_u8, SeIDByteA)

#else

#define LC_ID_STATUS(ch)           se_id_status[ch]
#define RM_ID_STATUS(ch)           ev_id_status[ch]
#define READ_LC_PAGE_NUMBER(ch)    LR(ch, l_u8, SeIDPage)
#define READ_RM_PAGE_NUMBER(ch)    LR(ch, l_u8, EvIDPage)
#define READ_RM_BYTE_A(ch)         LR(ch, l_u8, EvIDByteA)

#endif

void on_id_frame_receipt(uint8_t ch)  {
  if (READ_RM_PAGE_NUMBER(ch) == 0)  {   //make sure we are always reading the status
    RM_ID_STATUS(ch) = READ_RM_BYTE_A(ch);
  }

  if (LC_ID_STATUS(ch) == ID_INCOMPLETE && id_parse(ch)) {
    LC_ID_STATUS(ch) = ID_COMPLETE;

#ifdef EV_CONFIG
    PrintConsoleString("---Serial:", 0);
    PrintConsoleString((inact_ids_rcv[ch]->s).SeSerialNum, 0);
    PrintConsoleString("\r\n---Manu:",0);
    PrintConsoleString((inact_ids_rcv[ch]->s).SeManufacturer,0);
    PrintConsoleString(", Firmware:", 0);
    PrintConsoleString((inact_ids_rcv[ch]->s).SeFirmwareRevision, 0);
    PrintConsoleString("\r\n", 0);
#else
    PrintConsoleString("---VIN:", 0);
    PrintConsoleString((inact_ids_rcv[ch]->s).EvVIN, 0);
    PrintConsoleString(", Veh:", 0);
    PrintConsoleString((inact_ids_rcv[ch]->s).EvVehicleName, 0);
    PrintConsoleString("\r\n---Manu:", 0);
    PrintConsoleString((inact_ids_rcv[ch]->s).EvManufacturer, 0);
    PrintConsoleString(", Firmware:", 0);
    PrintConsoleString((inact_ids_rcv[ch]->s).EvFirmwareRevision, 0);
    PrintConsoleString("\r\n", 0);
#endif
  }

  if (LC_ID_STATUS(ch) == ID_COMPLETE && (RM_ID_STATUS(ch) == ID_COMPLETE || RM_ID_STATUS(ch) == DATA))  {
    PrintConsoleString("====ID COMPLETE!!!!===\r\n",0);
    LC_ID_STATUS(ch) = DATA;
    first_data[ch] = TRUE;
  }

  if (LC_ID_STATUS(ch) == DATA ) {
    if (RM_ID_STATUS(ch) == DATA)  {
      data_parse(ch);
    }
  }
}

void on_id_frame_xmit(uint8_t ch) {
  static uint8_t xmit_pgs_indx[2] = {0, 0};
  void* temp_ptr;

  if (LC_ID_STATUS(ch) == ID_INCOMPLETE || LC_ID_STATUS(ch) == ID_COMPLETE) {
    if (xmit_pgs_indx[ch] == NUM_ID_PGS2SND-1)  {
      xmit_pgs_indx[ch] = 0;
      temp_ptr = inact_ids_xmit[ch];            //swap id xmit buffers
      inact_ids_xmit[ch] = act_ids_xmit[ch];
      act_ids_xmit[ch] = temp_ptr;
      //don't clear id xmit buffers ad info is static
    } else  {
      xmit_pgs_indx[ch]++;
    }
    id_xmit(ch, id_pages_to_send[xmit_pgs_indx[ch]]);
  }

  if (LC_ID_STATUS(ch) == DATA ) {
    if (first_data[ch])  {
      xmit_pgs_indx[ch] = 0;
      first_data[ch] = FALSE;
    } else  {
      //printf("Success!\n");
      if (xmit_pgs_indx[ch] == NUM_DATA_PGS2SND-1)  {
        xmit_pgs_indx[ch] = 0;
        temp_ptr = inact_data_xmit[ch];            //swap data xmit buffers
        inact_data_xmit[ch] = act_data_xmit[ch];
        act_data_xmit[ch] = temp_ptr;
        clear_data_xmit_buff(act_data_xmit[ch]);  //clear data xmit buffer
      } else  {
        xmit_pgs_indx[ch]++;
      }
    }
    data_xmit(ch, data_pages_to_send[xmit_pgs_indx[ch]]);
  }
}

#ifdef EV_CONFIG

bool id_parse(uint8_t ch) {
  static uint8_t buffer[7];
  static uint8_t pgs_to_read[2] = {255, 255};
  static uint8_t pgs_read[2] = {0, 0};
  static uint8_t last_pg[2] = {255, 255};

  uint8_t copy_size = 7;
  uint8_t * source_ptr = buffer;
  uint8_t * dest_ptr = NULL;
  bool is_string = TRUE;

  void * temp_ptr;

  buffer[0] = LR(ch, l_u8, SeIDByteA);
  buffer[1] = LR(ch, l_u8, SeIDByteB);
  buffer[2] = LR(ch, l_u8, SeIDByteC);
  buffer[3] = LR(ch, l_u8, SeIDByteD);
  buffer[4] = LR(ch, l_u8, SeIDByteE);
  buffer[5] = LR(ch, l_u8, SeIDByteF);
  buffer[6] = LR(ch, l_u8, SeIDByteG);

  //printf("-->%c%c\n", buffer[0], buffer[1]);
  //printf("page:%d\n", l_u8_rd_LI0_EvIDPage());

  pgs_read[ch]++;

  ///>ev_id_parse
  switch(LR(ch, l_u8, SeIDPage)) {
    case 0:
      pgs_to_read[ch] = buffer[1];
      se_id_status[ch] = buffer[0];
      last_pg[ch] = buffer[3];
      pgs_read[ch] = 1;
        clear_ids_rcv_buff(act_ids_rcv[ch]);  //clear rcv buffer on control page to remove data from corrupted cycle
      break;
    case 17:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeSerialNum;
      break;
    case 18:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeSerialNum + 7;
      break;
    case 19:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeSerialNum + 14;
      break;
    case 20:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeSerialNum + 21;
      break;
    case 21:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeSerialNum + 28;
      break;
    case 22:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeSerialNum + 35;
      break;
    case 23:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeFirmwareRevision;
      break;
    case 24:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeFirmwareRevision + 7;
      break;
    case 25:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeFirmwareRevision + 14;
      break;
    case 26:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeFirmwareRevision + 21;
      break;
    case 27:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeManufacturer;
      break;
    case 28:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeManufacturer + 7;
      break;
    case 29:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeManufacturer + 14;
      break;
    case 30:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeManufacturer + 21;
      break;
    case 31:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeManufacturer + 28;
      break;
    case 32:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).SeManufacturer + 35;
      break;
  }
  ///<ev_id_parse

  //printf("pointer:%p\n",dest_ptr);

  //fflush(stdout);

  if (dest_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, is_string);
  }

  if ((pgs_read[ch] == pgs_to_read[ch]) && (LR(ch, l_u8, SeIDPage) == last_pg[ch]))  {
    temp_ptr = inact_ids_rcv[ch];            //swap id rcv buffers
    inact_ids_rcv[ch] = act_ids_rcv[ch];
    act_ids_rcv[ch] = temp_ptr;
    clear_ids_rcv_buff(act_ids_rcv[ch]);    //clear new buffer
    return TRUE;
  } else  {
    return FALSE;
  }
}

void id_xmit(uint8_t ch, uint8_t page){
  static uint8_t buffer[7];
  uint8_t mask = 0;

  uint8_t copy_size = 7;
  uint8_t * dest_ptr = buffer;
  uint8_t * source_ptr = NULL;

  ///>ev_id_xmit
  switch(page) {
    case 0:
      buffer[0] = ev_id_status[ch];
      buffer[1] = 17; //pages to be sent
      buffer[2] =  1; //first (non zero) page
      buffer[3] = 38; //last page
      buffer[4] = 0x00; //CRC neither sent nor read
      mask = 0b0000011;
      break;
    case 1:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvVIN;
      break;
    case 2:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvVIN + 7;
      break;
    case 3:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvVIN + 14;
      copy_size = 3;
      mask = 0b0001111;
      break;
    case 26:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvVehicleName;
      break;
    case 27:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvVehicleName + 7;
      break;
    case 28:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvVehicleName + 14;
      break;
    case 29:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvFirmwareRevision;
      break;
    case 30:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvFirmwareRevision + 7;
      break;
    case 31:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvFirmwareRevision + 14;
      break;
    case 32:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvFirmwareRevision + 21;
      break;
    case 33:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvManufacturer;
      break;
    case 34:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvManufacturer + 7;
      break;
    case 35:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvManufacturer + 14;
      break;
    case 36:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvManufacturer + 21;
      break;
    case 37:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvManufacturer + 28;
      break;
    case 38:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).EvManufacturer + 35;
      break;
  }
  ///<ev_id_xmit


  if (source_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, TRUE);
  }

  invalidate_bytes_page(buffer, mask);

  LW(ch, l_u8, EvIDPage, page);
  LW(ch, l_u8, EvIDByteA, buffer[0]);
  LW(ch, l_u8, EvIDByteB, buffer[1]);
  LW(ch, l_u8, EvIDByteC, buffer[2]);
  LW(ch, l_u8, EvIDByteD, buffer[3]);
  LW(ch, l_u8, EvIDByteE, buffer[4]);
  LW(ch, l_u8, EvIDByteF, buffer[5]);
  LW(ch, l_u8, EvIDByteG, buffer[6]);
}

void data_xmit(uint8_t ch, uint8_t page) {
  static uint8_t buffer[7];
  uint8_t mask = 0;

  uint8_t copy_size = 7;
  uint8_t * dest_ptr = buffer;
  uint8_t * source_ptr = NULL;

  ///>ev_data_xmit
  switch(page) {
    case 0:
      buffer[0] = ev_id_status[ch];
      buffer[1] =  2; //pages to be sent
      buffer[2] = 97; //first (non zero) page
      buffer[3] = 97; //last page
      buffer[4] = 0x00; //CRC neither sent nor read
      mask = 0b0000011;
      break;
    case 97:
      buffer[0] = ((act_data_xmit[ch]->v).EvOdometer) & 0xFF;
      buffer[1] = ((act_data_xmit[ch]->v).EvOdometer >> 8) & 0xFF;
      buffer[2] = ((act_data_xmit[ch]->v).EvOdometer >> 16) & 0xFF;
      buffer[3] = ((act_data_xmit[ch]->v).EvOdometer >> 24) & 0xFF;
      mask = 0b0000111;
      break;
  }
  ///<ev_data_xmit

  if (source_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, FALSE);
  }

  invalidate_bytes_page(buffer, mask);

  LW(ch, l_u8, EvIDPage, page);
  LW(ch, l_u8, EvIDByteA, buffer[0]);
  LW(ch, l_u8, EvIDByteB, buffer[1]);
  LW(ch, l_u8, EvIDByteC, buffer[2]);
  LW(ch, l_u8, EvIDByteD, buffer[3]);
  LW(ch, l_u8, EvIDByteE, buffer[4]);
  LW(ch, l_u8, EvIDByteF, buffer[5]);
  LW(ch, l_u8, EvIDByteG, buffer[6]);
}

void data_parse(uint8_t ch)  {
  static uint8_t buffer[7];
  static uint8_t pgs_to_read[2] = {255, 255};
  static uint8_t pgs_read[2] = {0, 0};
  static uint8_t last_pg[2] = {255, 255};

  uint8_t copy_size = 7;
  uint8_t * source_ptr = buffer;
  uint8_t * dest_ptr = NULL;
  bool is_string = TRUE;

  void* temp_ptr;

  buffer[0] = LR(ch, l_u8, SeIDByteA);
  buffer[1] = LR(ch, l_u8, SeIDByteB);
  buffer[2] = LR(ch, l_u8, SeIDByteC);
  buffer[3] = LR(ch, l_u8, SeIDByteD);
  buffer[4] = LR(ch, l_u8, SeIDByteE);
  buffer[5] = LR(ch, l_u8, SeIDByteF);
  buffer[6] = LR(ch, l_u8, SeIDByteG);

  pgs_read[ch]++;

  ///>ev_data_parse
  switch(LR(ch, l_u8, SeIDPage)) {
    case 0:
      pgs_to_read[ch] = buffer[1];
      se_id_status[ch] = buffer[0];
      last_pg[ch] = buffer[3];
      pgs_read[ch] = 1;
        clear_data_rcv_buff(act_data_rcv[ch]);  //clear rcv buffer on control page to remove data from corrupted cycle
      break;
    case 98:
      (act_data_rcv[ch]->v).SeRmtMgmtStatus = ((uint8_t)buffer[0]);
      //printf("SeRmtMgmtStatus 0x%02X Enum\n", ((act_data_rcv[ch]->v).SeRmtMgmtStatus));
      break;
  }
  ///<ev_data_parse

  if (dest_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, is_string);
  }

  if ((pgs_read[ch] == pgs_to_read[ch]) && (LR(ch, l_u8, EvIDPage) == last_pg[ch]))  {
    temp_ptr = inact_data_rcv[ch];           //swap data rcv buffers
    inact_data_rcv[ch] = act_data_rcv[ch];
    act_data_rcv[ch] = temp_ptr;
    clear_data_rcv_buff(act_data_rcv[ch]);   //clear new buffer
  }
}
#else
bool id_parse(uint8_t ch) {
  static uint8_t buffer[7];
  static uint8_t pgs_to_read[2] = {255, 255};
  static uint8_t pgs_read[2] = {0, };
  static uint8_t last_pg[2] = {255, 255};

  uint8_t copy_size = 7;
  uint8_t * source_ptr = buffer;
  uint8_t * dest_ptr = NULL;
  bool is_string = TRUE;

  void* temp_ptr;

  buffer[0] = LR(ch, l_u8, EvIDByteA);
  buffer[1] = LR(ch, l_u8, EvIDByteB);
  buffer[2] = LR(ch, l_u8, EvIDByteC);
  buffer[3] = LR(ch, l_u8, EvIDByteD);
  buffer[4] = LR(ch, l_u8, EvIDByteE);
  buffer[5] = LR(ch, l_u8, EvIDByteF);
  buffer[6] = LR(ch, l_u8, EvIDByteG);

  //printf("-->%c%c\n", buffer[0], buffer[1]);
  //printf("page:%d\n", l_u8_rd_LI0_EvIDPage());

  pgs_read[ch]++;

  ///>se_id_parse
  switch(LR(ch, l_u8, EvIDPage)) {
    case 0:
      pgs_to_read[ch] = buffer[1];
      ev_id_status[ch] = buffer[0];
      last_pg[ch] = buffer[3];
      pgs_read[ch] = 1;
        clear_ids_rcv_buff(act_ids_rcv[ch]);  //clear rcv buffer on control page to remove data from corrupted cycle
      break;
    case 1:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvVIN;
      break;
    case 2:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvVIN + 7;
      break;
    case 3:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvVIN + 14;
      copy_size = 3;
      break;
    case 26:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvVehicleName;
      break;
    case 27:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvVehicleName + 7;
      break;
    case 28:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvVehicleName + 14;
      break;
    case 29:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvFirmwareRevision;
      break;
    case 30:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvFirmwareRevision + 7;
      break;
    case 31:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvFirmwareRevision + 14;
      break;
    case 32:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvFirmwareRevision + 21;
      break;
    case 33:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvManufacturer;
      break;
    case 34:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvManufacturer + 7;
      break;
    case 35:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvManufacturer + 14;
      break;
    case 36:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvManufacturer + 21;
      break;
    case 37:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvManufacturer + 28;
      break;
    case 38:
      dest_ptr = (uint8_t *) (act_ids_rcv[ch]->s).EvManufacturer + 35;
      break;
  }
  ///<se_id_parse

  //printf("pointer:%p\n",dest_ptr);

  //fflush(stdout);

  if (dest_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, is_string);
  }

  if ((pgs_read[ch] == pgs_to_read[ch]) && (LR(ch, l_u8, EvIDPage) == last_pg[ch]))  {
    temp_ptr = inact_ids_rcv[ch];            //swap id rcv buffers
    inact_ids_rcv[ch] = act_ids_rcv[ch];
    act_ids_rcv[ch] = temp_ptr;
    clear_ids_rcv_buff(act_ids_rcv[ch]);    //clear new buffer
    return TRUE;
  } else  {
    return FALSE;
  }
}

void id_xmit(uint8_t ch, uint8_t page){
  static uint8_t buffer[7];
  uint8_t mask = 0;

  uint8_t copy_size = 7;
  uint8_t * dest_ptr = buffer;
  uint8_t * source_ptr = NULL;

  ///>se_id_xmit
  switch(page) {
    case 0:
      buffer[0] = se_id_status[ch];
      buffer[1] = 17; //pages to be sent
      buffer[2] = 17; //first (non zero) page
      buffer[3] = 32; //last page
      buffer[4] = 0x00; //CRC neither sent nor read
      mask = 0b0000011;
      break;
    case 17:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeSerialNum;
      break;
    case 18:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeSerialNum + 7;
      break;
    case 19:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeSerialNum + 14;
      break;
    case 20:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeSerialNum + 21;
      break;
    case 21:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeSerialNum + 28;
      break;
    case 22:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeSerialNum + 35;
      break;
    case 23:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeFirmwareRevision;
      break;
    case 24:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeFirmwareRevision + 7;
      break;
    case 25:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeFirmwareRevision + 14;
      break;
    case 26:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeFirmwareRevision + 21;
      break;
    case 27:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeManufacturer;
      break;
    case 28:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeManufacturer + 7;
      break;
    case 29:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeManufacturer + 14;
      break;
    case 30:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeManufacturer + 21;
      break;
    case 31:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeManufacturer + 28;
      break;
    case 32:
      source_ptr = (uint8_t *) (act_ids_xmit[ch]->s).SeManufacturer + 35;
      break;
  }
  ///<se_id_xmit


  if (source_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, TRUE);
  }

  invalidate_bytes_page(buffer, mask);

  LW(ch, l_u8, SeIDPage, page);
  LW(ch, l_u8, SeIDByteA, buffer[0]);
  LW(ch, l_u8, SeIDByteB, buffer[1]);
  LW(ch, l_u8, SeIDByteC, buffer[2]);
  LW(ch, l_u8, SeIDByteD, buffer[3]);
  LW(ch, l_u8, SeIDByteE, buffer[4]);
  LW(ch, l_u8, SeIDByteF, buffer[5]);
  LW(ch, l_u8, SeIDByteG, buffer[6]);
}

void data_xmit(uint8_t ch, uint8_t page) {
  static uint8_t buffer[7];
  uint8_t mask = 0;
  uint32_t temp;

  uint8_t copy_size = 7;
  uint8_t * dest_ptr = buffer;
  uint8_t * source_ptr = NULL;

  ///>se_data_xmit
  switch(page) {
    case 0:
      buffer[0] = se_id_status[ch];
      buffer[1] =  2; //pages to be sent
      buffer[2] = 98; //first (non zero) page
      buffer[3] = 98; //last page
      buffer[4] = 0x00; //CRC neither sent nor read
      mask = 0b0000011;
      break;
    case 98:
      buffer[0] = ((act_data_xmit[ch]->v).SeRmtMgmtStatus) & 0xFF;
      mask = 0b0111111;
      break;
  }
  ///<se_data_xmit

  if (source_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, FALSE);
  }

  invalidate_bytes_page(buffer, mask);

  LW(ch, l_u8, SeIDPage, page);
  LW(ch, l_u8, SeIDByteA, buffer[0]);
  LW(ch, l_u8, SeIDByteB, buffer[1]);
  LW(ch, l_u8, SeIDByteC, buffer[2]);
  LW(ch, l_u8, SeIDByteD, buffer[3]);
  LW(ch, l_u8, SeIDByteE, buffer[4]);
  LW(ch, l_u8, SeIDByteF, buffer[5]);
  LW(ch, l_u8, SeIDByteG, buffer[6]);
}

void data_parse(uint8_t ch)  {
  static uint8_t buffer[7];
  static uint8_t pgs_to_read[2] = {255, 255};
  static uint8_t pgs_read[2] = {0, 0};
  static uint8_t last_pg[2] = {255, 255};

  uint8_t copy_size = 7;
  uint8_t * source_ptr = buffer;
  uint8_t * dest_ptr = NULL;
  bool is_string = TRUE;

  void* temp_ptr;

  buffer[0] = LR(ch, l_u8, EvIDByteA);
  buffer[1] = LR(ch, l_u8, EvIDByteB);
  buffer[2] = LR(ch, l_u8, EvIDByteC);
  buffer[3] = LR(ch, l_u8, EvIDByteD);
  buffer[4] = LR(ch, l_u8, EvIDByteE);
  buffer[5] = LR(ch, l_u8, EvIDByteF);
  buffer[6] = LR(ch, l_u8, EvIDByteG);

  pgs_read[ch]++;

  ///>se_data_parse
  switch(LR(ch, l_u8, EvIDPage)) {
    case 0:
      pgs_to_read[ch] = buffer[1];
      ev_id_status[ch] = buffer[0];
      last_pg[ch] = buffer[3];
      pgs_read[ch] = 1;
        clear_data_rcv_buff(act_data_rcv[ch]);  //clear rcv buffer on control page to remove data from corrupted cycle
      break;
    case 97:
      (act_data_rcv[ch]->v).EvOdometer = ((uint32_t)buffer[3] << 24) | ((uint32_t)buffer[2] << 16) | ((uint32_t)buffer[1] << 8) | ((uint32_t)buffer[0]);
      //printf("EvOdometer %.3lf km\n", ((double)(act_data_rcv[ch]->v).EvOdometer * 0.125000));
      break;
  }
  ///<se_data_parse

  if (dest_ptr != NULL) {
    copy_buffer_data(source_ptr, dest_ptr, copy_size, is_string);
  }

  if ((pgs_read[ch] == pgs_to_read[ch]) && (LR(ch, l_u8, SeIDPage) == last_pg[ch]))  {
    temp_ptr = inact_data_rcv[ch];           //swap data rcv buffers
    inact_data_rcv[ch] = act_data_rcv[ch];
    act_data_rcv[ch] = temp_ptr;
    clear_data_rcv_buff(act_data_rcv[ch]);   //clear new buffer
  }
}
#endif
