#include "lin-cp.h"
#include "globals.h"
#include "info_codes.h"
#include "info_code_handler.h"
#include "utils.h"

#ifdef EV_CONFIG
#define XMIT_BUFFER_SIZE     MAX_EVINFOENTRIES
#define RCV_BUFFER_SIZE      MAX_SEINFOENTRIES * 2 //We know exactly how many codes we can possibly send, but can't know what we might receive
#define XMIT_INFOENTRY_EMPTY EVINFOENTRY_EMPTY
#define RCV_INFOENTRY_EMPTY  SEINFOENTRY_EMPTY
#define XMIT_INFO(x)         EvInfo##x
#define RCV_INFO(x)          SeInfo##x
#define MY_ID                "EV"
#define OTHER_ID             "SE"
#else
#define XMIT_BUFFER_SIZE     MAX_SEINFOENTRIES
#define RCV_BUFFER_SIZE      MAX_EVINFOENTRIES * 2
#define XMIT_INFOENTRY_EMPTY SEINFOENTRY_EMPTY
#define RCV_INFOENTRY_EMPTY  EVINFOENTRY_EMPTY
#define XMIT_INFO(x)         SeInfo##x
#define RCV_INFO(x)          EvInfo##x
#define MY_ID                "SE"
#define OTHER_ID             "EV"
#endif

//Initialize the first page to Empty
static uint8_t info_codes_xmit_buff_1[2][XMIT_BUFFER_SIZE] = {{XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY,
                                                               XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY},
                                                              {XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY,
                                                               XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY}};
static uint8_t info_codes_xmit_buff_2[2][XMIT_BUFFER_SIZE];

//No need for double buffering as we directly control parsing
static uint8_t info_codes_rcv_buff[2][RCV_BUFFER_SIZE];

static uint8_t xmit_page[2]  = {0,0};
static uint8_t rcvd_pages[2] = {0,0};

void copy_buffer(uint8_t source[], uint8_t destination[], uint8_t size) {
  uint8_t i, j;
  uint8_t index;
  size /= 6; //we know size is evenly divisible by 6

  for (i = 0; i < size; i++) {
    for (j = 0; j < 6; j++) {
      index              = i * 6 + j;
      destination[index] = source[index];
    }
    if (source[index] == XMIT_INFOENTRY_EMPTY) return;
  }
}

bool set_info_code(uint8_t ch, uint8_t code) {
  uint8_t i, j;
  uint8_t index;
  int8_t inserted = -1;
  uint8_t size    = XMIT_BUFFER_SIZE / 6; //we know size is evenly divisible by 6

  for (i = 0; i < size; i++) {
    for (j = 0; j < 6; j++) {
      index = i * 6 + j;
      if (info_codes_xmit_buff_1[ch][index] == code) return FALSE;
      if (inserted >= 0) {
        info_codes_xmit_buff_1[ch][index] = XMIT_INFOENTRY_EMPTY;
      } else {
        if (info_codes_xmit_buff_1[ch][index] == XMIT_INFOENTRY_EMPTY) {
          info_codes_xmit_buff_1[ch][index] = code;
          inserted                          = j;
        }
      }
    }
    if (inserted == 5) {
      inserted = 0;
    } else if (inserted >= 0) {
      return TRUE;
    }
  }
  return FALSE; //how did we get here?
}

//Insert at the beginning of the list.  Returns false if the code is already in the list.  It will be moved to the beginning.
bool set_priority_info_code(uint8_t ch, uint8_t code) {
  uint8_t i, j;
  uint8_t index;
  uint8_t prev = code, curr;
  bool end     = FALSE;
  uint8_t size = XMIT_BUFFER_SIZE / 6; //we know size is evenly divisible by 6

  for (i = 0; i < size; i++) {
    for (j = 0; j < 6; j++) {
      index = i * 6 + j;
      curr  = prev;
      prev  = info_codes_xmit_buff_1[ch][index];
      if ((index != 0) && (curr == code)) return FALSE;
      if (curr == XMIT_INFOENTRY_EMPTY) end = TRUE;
      info_codes_xmit_buff_1[ch][index] = end ? XMIT_INFOENTRY_EMPTY : curr;
    }
    if (end) return TRUE;
  }
  return FALSE; //how did we get here?
}

bool clear_info_code(uint8_t ch, uint8_t code) {
  uint8_t i, j;
  uint8_t index;
  bool removed = FALSE, end = FALSE;
  uint8_t size = XMIT_BUFFER_SIZE / 6; //we know size is evenly divisible by 6

  for (i = 0; i < size; i++) {
    for (j = 0; j < 6; j++) {
      index = i * 6 + j;
      if (info_codes_xmit_buff_1[ch][index] == code) removed = TRUE;
      if (removed) {
        if (end) {
          info_codes_xmit_buff_1[ch][index] = XMIT_INFOENTRY_EMPTY;
        } else {
#pragma MESSAGE DISABLE C5909 //Assignment in condition.  Fully intentional
          if ((info_codes_xmit_buff_1[ch][index] = info_codes_xmit_buff_1[ch][index + 1]) == XMIT_INFOENTRY_EMPTY) end = TRUE;
        }
      }
    }
    if (end) return removed;
  }

  return removed;
}

#pragma MESSAGE WARNING C5909

void clear_all_info_codes(uint8_t ch) {
  //Fill the first page with "Empty."  Any codes in later pages will be treated as uninitialized memory.
  mem_init_ff(info_codes_xmit_buff_1[ch], 6);
}

//We must handle empties between valid codes as the standard does not disallow this
void parse_info_codes(uint8_t ch) {
  uint8_t i, j;
  uint8_t index;
  uint8_t size     = RCV_BUFFER_SIZE / 6; //we know size is evenly divisible by 6
  bool valid_codes = FALSE;

  for (i = 0; i < size; i++) {
    for (j = 0; j < 6; j++) {
      index = i * 6 + j;
      if (info_codes_rcv_buff[ch][index] != RCV_INFOENTRY_EMPTY) {
        if (!valid_codes) {
          PrintConsoleString("Set " OTHER_ID " Channel:", 0);
          PrintConsoleChar(ch? 'B': 'A');
          PrintConsoleString(" Codes:", 0);
          valid_codes = TRUE;
        }
        PrintConsoleHex(info_codes_rcv_buff[ch][index]);
        PrintConsoleString(" ", 0);
      }
    }
    if (info_codes_rcv_buff[ch][index] == RCV_INFOENTRY_EMPTY) break;
  }
  if (valid_codes) PrintConsoleString("\r\n", 0);
#pragma MESSAGE DISABLE C12056 //debug info incorrect because of optimization or inline assembler
}

void xmit_info_code_page(uint8_t ch) {
  if (xmit_page[ch] == 0) {
    copy_buffer(info_codes_xmit_buff_1[ch], info_codes_xmit_buff_2[ch], XMIT_BUFFER_SIZE);
  }

#pragma MESSAGE DISABLE C2705 //possible loss of data
  LW(ch, l_u8, XMIT_INFO(PageNumber), xmit_page[ch]);
  LW(ch, l_u8, XMIT_INFO(Entry1), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6]);
  LW(ch, l_u8, XMIT_INFO(Entry2), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 1]);
  LW(ch, l_u8, XMIT_INFO(Entry3), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 2]);
  LW(ch, l_u8, XMIT_INFO(Entry4), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 3]);
  LW(ch, l_u8, XMIT_INFO(Entry5), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 4]);
  LW(ch, l_u8, XMIT_INFO(Entry6), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 5]);

  if (info_codes_xmit_buff_2[ch][(++xmit_page[ch]) * 6 - 1] == XMIT_INFOENTRY_EMPTY) xmit_page[ch] = 0;

  //clear flag
  LFC(ch, XMIT_INFO(List));
}

#pragma MESSAGE WARNING C2705

void rcv_info_code_page(uint8_t ch) {
  uint8_t rcv_page = LR(ch, l_u8, RCV_INFO(PageNumber));

  rcvd_pages[ch]++;
  if (rcv_page == 0) rcvd_pages[ch] = 1; //make sure we can resynchronize

  if (!(rcv_page * 6 > RCV_BUFFER_SIZE)) { //don't overflow the buffer
    info_codes_rcv_buff[ch][rcv_page * 6]     = LR(ch, l_u8, RCV_INFO(Entry1));
    info_codes_rcv_buff[ch][rcv_page * 6 + 1] = LR(ch, l_u8, RCV_INFO(Entry2));
    info_codes_rcv_buff[ch][rcv_page * 6 + 2] = LR(ch, l_u8, RCV_INFO(Entry3));
    info_codes_rcv_buff[ch][rcv_page * 6 + 3] = LR(ch, l_u8, RCV_INFO(Entry4));
    info_codes_rcv_buff[ch][rcv_page * 6 + 4] = LR(ch, l_u8, RCV_INFO(Entry5));
    info_codes_rcv_buff[ch][rcv_page * 6 + 5] = LR(ch, l_u8, RCV_INFO(Entry6));
  }

  if ((rcv_page + 1 == rcvd_pages[ch]) && (info_codes_rcv_buff[ch][rcv_page * 6 + 5] == RCV_INFOENTRY_EMPTY)) {
    parse_info_codes(ch);
    rcvd_pages[ch] = 0;
  }

  //clear flag
  LFC(ch, RCV_INFO(List));
}
