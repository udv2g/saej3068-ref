#include "lin-cp.h"
#include "globals.h"
#include "info_codes.h"
#include "info_code_handler.h"
#include "utils.h"

# include "InfoCodeStrings.h" //not a proper header, be careful

#ifdef EV_CONFIG
#define XMIT_BUFFER_SIZE     MAX_EVINFOENTRIES
#define RCV_BUFFER_SIZE      MAX_SEINFOENTRIES * 2 //We know exactly how many codes we can possibly send, but can't know what we might receive
#define XMIT_INFOENTRY_EMPTY EVINFOENTRY_EMPTY
#define RCV_INFOENTRY_EMPTY  SEINFOENTRY_EMPTY
#define XMIT_INFO(x)         EvInfo##x
#define RCV_INFO(x)          SeInfo##x
#define MY_ID                "EV"
#define OTHER_ID             "SE"
#define MY_ID_BOOL           FALSE
#else
#define XMIT_BUFFER_SIZE     MAX_SEINFOENTRIES
#define RCV_BUFFER_SIZE      MAX_EVINFOENTRIES * 2
#define XMIT_INFOENTRY_EMPTY SEINFOENTRY_EMPTY
#define RCV_INFOENTRY_EMPTY  EVINFOENTRY_EMPTY
#define XMIT_INFO(x)         SeInfo##x
#define RCV_INFO(x)          EvInfo##x
#define MY_ID                "SE"
#define OTHER_ID             "EV"
#define MY_ID_BOOL           TRUE
#endif

//Initialize the first page to Empty
static uint8_t info_codes_xmit_buff_1[2][XMIT_BUFFER_SIZE] = {{XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY,
                                                               XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY},
                                                              {XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY,
                                                               XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY}};
static uint8_t info_codes_xmit_buff_2[2][XMIT_BUFFER_SIZE] = {{XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY,
                                                               XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY},
                                                              {XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY,
                                                               XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY, XMIT_INFOENTRY_EMPTY}};;

//No need for double buffering as we directly control parsing
static uint8_t info_codes_rcv_buff[2][RCV_BUFFER_SIZE] = {{RCV_INFOENTRY_EMPTY, RCV_INFOENTRY_EMPTY, RCV_INFOENTRY_EMPTY,
                                                           RCV_INFOENTRY_EMPTY, RCV_INFOENTRY_EMPTY, RCV_INFOENTRY_EMPTY},
                                                          {RCV_INFOENTRY_EMPTY, RCV_INFOENTRY_EMPTY, RCV_INFOENTRY_EMPTY,
                                                           RCV_INFOENTRY_EMPTY, RCV_INFOENTRY_EMPTY, RCV_INFOENTRY_EMPTY}};;

static uint8_t xmit_page[2]  = {0,0};
static uint8_t rcvd_pages[2] = {0,0};

uint8_t current_rcvd_codes[32] = {0};

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
      print_info_code_change(ch, MY_ID_BOOL, code, TRUE);
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
    if (end) {
      print_info_code_change(ch, MY_ID_BOOL, code, PRIORITY);
      return TRUE;
    }
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
      if (info_codes_xmit_buff_1[ch][index] == code)  {
        print_info_code_change(ch, MY_ID_BOOL, code, FALSE);
        removed = TRUE;
      }
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

void clear_all_info_codes(uint8_t ch) {
  //Fill the first page with "Empty."  Any codes in later pages will be treated as uninitialized memory.
  mem_init(info_codes_xmit_buff_1[ch], 6, XMIT_INFOENTRY_EMPTY);
}

//We must handle empties between valid codes as the standard does not disallow this
void parse_info_codes(uint8_t ch) {
  uint8_t i, j;
  uint8_t index;
  uint8_t size     = RCV_BUFFER_SIZE / 6; //we know size is evenly divisible by 6
  bool valid_codes = FALSE;
  uint8_t new_rcvd_codes[32] = {0};
  uint8_t partial, check_bit;

#define set_rcvd_code(code) new_rcvd_codes[(code) >> 3] |= (1 << ((code) & 0b00000111))

  for (i = 0; i < size; i++) {
    for (j = 0; j < 6; j++) {
      index = i * 6 + j;
      if (info_codes_rcv_buff[ch][index] != RCV_INFOENTRY_EMPTY) {
        valid_codes = TRUE;
        set_rcvd_code(info_codes_rcv_buff[ch][index]);
      }
    }
    if (info_codes_rcv_buff[ch][index] == RCV_INFOENTRY_EMPTY) break;
  }

  if (valid_codes) {
    for (i = 0; i < 32; i++)	{
      if ((partial = (new_rcvd_codes[i] ^ current_rcvd_codes[i])))	{
        for (j = 0; j < 8; j++)	{
          check_bit = (1 << j);
          if (partial & check_bit)	{
            if (partial & check_bit & current_rcvd_codes[i])	{
              print_info_code_change(ch, !MY_ID_BOOL, ((i << 3) | j), FALSE);
            }	else{
              print_info_code_change(ch, !MY_ID_BOOL, ((i << 3) | j), TRUE);
            }
          }
        }
      }
    }
  }

  mem_copy(new_rcvd_codes, current_rcvd_codes, 32);
}

void xmit_info_code_page(uint8_t ch) {
  if (xmit_page[ch] == 0) {
    copy_buffer(info_codes_xmit_buff_1[ch], info_codes_xmit_buff_2[ch], XMIT_BUFFER_SIZE);
  }

#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_INFO(PageNumber), xmit_page[ch]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_INFO(Entry1), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_INFO(Entry2), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 1]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_INFO(Entry3), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 2]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_INFO(Entry4), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 3]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_INFO(Entry5), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 4]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_INFO(Entry6), info_codes_xmit_buff_2[ch][xmit_page[ch] * 6 + 5]);

  if (info_codes_xmit_buff_2[ch][(++xmit_page[ch]) * 6 - 1] == XMIT_INFOENTRY_EMPTY) xmit_page[ch] = 0;

  //clear flag
  LFC(ch, XMIT_INFO(List));
}

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

// >IA:<SE [S] or EV [E]>:<Hexadecimal code>:<set [S], or clear [C]>(:<channel>)(#Comment)
// >IA:E:19:C#Internal Fault
void print_info_code_change(uint8_t ch, uint8_t id, uint8_t code, uint8_t op){	//id TRUE->SE, FALSE->EV; op 0->clear, 1-> set, 2->priority set (local only)
	int8_t xmit_buffer1[] = ">IA:X:";
#ifdef CH_A_ONLY
	int8_t xmit_buffer2[] = ":Y#";
#else
	int8_t xmit_buffer2[] = ":Y:Z#";
#endif

	xmit_buffer1[4] = id ? 'S' : 'E';
	xmit_buffer2[1] = op ? ((op == 2) ? 'P': 'S') : 'C';

#ifndef CH_A_ONLY
	xmit_buffer2[3] = ch ? 'B' : 'A';
#endif

	PrintCmdsString( (char *) xmit_buffer1,0);
	PrintCmdsHex(code);
	PrintCmdsString(xmit_buffer2,0);
	if (id)	{
		PrintCmdsString(SE_Info_Codes[code],0);
	}	else	{
		PrintCmdsString(EV_Info_Codes[code],0);
	}
	PrintCmdsString("\r\n",0);
}

//We must handle empties between valid codes as the standard does not disallow this
void print_all_info_codes_int(uint8_t ch, uint8_t id, uint8_t * buffer, uint8_t buffer_size) {
  uint8_t i, j;
  uint8_t index;
  uint8_t size     = buffer_size / 6; //we know size is evenly divisible by 6
  bool valid_codes = FALSE;

  for (i = 0; i < size; i++) {
    for (j = 0; j < 6; j++) {
      index = i * 6 + j;
      if (buffer[index] != RCV_INFOENTRY_EMPTY) {
        if (!valid_codes) {
          PrintConsoleString("Set ", 0);
          if (id) {
            PrintConsoleString("SE", 0);
          } else{
            PrintConsoleString("EV", 0);
          }
          PrintConsoleString(" Channel:", 0);
          PrintConsoleChar(ch? 'B': 'A');
          PrintConsoleString(" Codes:\r\n", 0);
          valid_codes = TRUE;
        }
        PrintConsoleString("\t", 0);
        PrintConsoleHex(buffer[index]);
        PrintConsoleString("\t", 0);
        if (id)	{
          PrintConsoleString(SE_Info_Codes[buffer[index]],0);
        }	else	{
          PrintConsoleString(EV_Info_Codes[buffer[index]],0);
        }
        PrintConsoleString("\r\n", 0);
      }
    }
    if (buffer[index] == RCV_INFOENTRY_EMPTY) break;
  }
  if (valid_codes) PrintConsoleString("\r\n", 0);
#pragma MESSAGE DISABLE C12056 //debug info incorrect because of optimization or inline assembler
}

void print_all_info_codes(uint8_t ch) {
  print_all_info_codes_int(ch, MY_ID_BOOL, &(info_codes_xmit_buff_2[ch][0]), XMIT_BUFFER_SIZE);
  print_all_info_codes_int(ch, !MY_ID_BOOL, &(info_codes_rcv_buff[ch][0]), RCV_BUFFER_SIZE);
}

#pragma INLINE
bool check_remote_code(uint8_t code)  {
  return !!(current_rcvd_codes[code >> 3] & (1 << (code & 0b00000111)));
}
