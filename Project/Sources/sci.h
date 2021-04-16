#ifndef _SCI_H
#define _SCI_H

#include "types.h"

#define SCI_RIE_OFF 0
#define SCI_RIE_ON  1

// SCI module numbers
#define SCI2_BUF &print_c2buf

#define BUFSIZE 240

typedef struct {

  uint8_t BDH;
  uint8_t BDL;
  uint8_t CR1;
  uint8_t CR2;
  uint8_t SR1;
  uint8_t SR2;
  uint8_t DRH;
  uint8_t DRL;

} SCI_REG;

#define SCIASR1 BDH
#define SCIACR1 BDL
#define SCIACR2 CR1

typedef struct {
  SCI_REG *SCI;
  uint16_t inpos;
  uint16_t outpos;
  uint8_t *data;
  uint16_t size;
} circular_buffer;

void SCI2_RXRoutine(uint8_t rcv);

uint8_t get_hex8_from_2char(uint8_t char1, uint8_t char2);
uint16_t get_hex16_from_4char(uint8_t *buf, uint8_t index, uint8_t size);

void InitSCIBuffers(void);
void CBufInit(circular_buffer *buf, void *sci_base, uint8_t *data, uint16_t size);
bool CBufPush(circular_buffer *buf, char in);
bool CBufPop(circular_buffer *buf);
bool CBufEmpty(circular_buffer *buf);
;

void SCIOpenCommunication(circular_buffer *buf, uint32_t baud_rate, bool wakeup, bool rie);
void SetSCIRIE(circular_buffer *buf, uint8_t mode);
void SCISendBuffer(circular_buffer *buf, uint8_t c);
void SendString(circular_buffer *buf, int8_t *string, uint16_t size);
void SendFarString(circular_buffer *buf, int8_t *far string, uint16_t size);
void SendStringC(circular_buffer *buf, int8_t *string, uint16_t size, uint16_t *checksum);
void SendFarStringC(circular_buffer *buf,
                    int8_t *far string, uint16_t size, uint16_t *checksum);
void SendHexValue(circular_buffer *buf, int raw, uint16_t hex_value);
void SendHexValueC(circular_buffer *buf, uint16_t hex_value, uint16_t *checksum);
void SendLongValueC(circular_buffer *buf, uint32_t hex32_value,
                    uint16_t *checksum);
void SendDecValue(circular_buffer *buf, uint16_t dec_value);
//void SendDecValueC(circular_buffer *buf, uint16_t dec_value, uint16_t* checksum);
void SendCharValueC(circular_buffer *buf, char char_value, uint16_t *checksum);
uint8_t ConvertCharAscii(uint8_t value);
void SendLongValue(circular_buffer *buf, uint32_t hex32_value);

#define PrintS2(x, size) SendString(&print_c2buf, x, size);
#define PrintDec2(x)     SendDecValue(&print_c2buf, x);
#define PrintChar2(x)    SCISendBuffer(&print_c2buf, x);
#define PrintHex2(x)     SendHexValue(&print_c2buf, 0, x);
#define PrintLongHex2(x) SendLongValue(&print_c2buf, x);

#define PrintConsoleString(x, y) PrintS2(x, y)
#define PrintConsoleDec(x)       PrintDec2(x)
#define PrintConsoleChar(x)      PrintChar2(x)
#define PrintConsoleHex(x)       PrintHex2(x)
#define PrintConsoleLongHex(x)   PrintLongHex2(x)

#define PrintCmdsString(x, y) PrintS2(x, y)
#define PrintCmdsHex(x)       PrintHex2(x)

#endif
