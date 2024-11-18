#include "sci.h"
#include "derivative.h"
#include "hardware.h"
//#include "lin.h"
//#include "lin_cfg.h"
//#include "lin_hw_cfg.h"
#include "string_utils.h"
#include "globals.h"

#define PREV(i, size) (uint8_t)((index - i + size) % size)
#define NEXT(i, size) (uint8_t)((index + i) % size) 

void InitSCIBuffers(void) {
  CBufInit(SCI_BUF, &SCI2BDH, print_buf_data, BUFSIZE);
}

uint8_t get_hex8_from_2char(uint8_t char1, uint8_t char2) {
  uint8_t val = 0;
  val         = (hex_to_dex(char1) << 4) | hex_to_dex(char2);
  return val;
}

uint16_t get_hex16_from_4char(uint8_t *buf, uint8_t index, uint8_t size) {
  int i;
  uint16_t val = 0;
  for (i = 4; i > 0; --i) {
    val = (val << 4) | hex_to_dex(buf[PREV(i, size)]);
  }
  return val;
}

#define ASCII_LOWERCASE_BIT 0x20

void SCI_RXRoutine(uint8_t rcv) {
  static uint8_t prev;

  SCI2_receive_buffer[SCI2_receive_pointer++] = rcv;

  if (prev == '\r' && rcv == '\n') {
    SCI2_receive_buffer[SCI2_receive_pointer] = '\0';
    SCI2_receive_pointer                      = 0;
    SCI2_receive_flag                         = TRUE;
  }
  prev = rcv;
}

void SCIOpenCommunication(circular_buffer *buf, uint32_t baud_rate, bool wakeup, bool rie) {

  uint32_t baud_value;

  // Calculate Baud Module Divisor value depending on bus speed
  baud_value = (uint32_t)(MCU_BUS_FREQ / (16 * baud_rate));

  // Set Baud Rate Modulo Divisor
  buf->SCI->BDH = (uint8_t)(baud_value >> 8);
  buf->SCI->BDL = (uint8_t)baud_value;

  // Trasmitter and Receiver Enable
  buf->SCI->CR2 |= 0x0C;

  SetSCIRIE(buf, rie);

  // If we want to access RXEDGIE/RXEDGIF, we need to set the AMAP bit
  //turn AMAP on after setting baud rate and leave it on
  buf->SCI->SR2 |= 0x80;
  // Check if we want to wakeup on this SCI enable
  if(wakeup){
      //NOTE some older versions of the code incorrectly had ASR1 here!!
      buf->SCI->SCIACR1 |= 0x80;
  }
}

void SetSCIRIE(circular_buffer *buf, uint8_t mode) {
  if (mode == SCI_RIE_OFF) {
    // Disable Receive Interrupt
    buf->SCI->CR2 &= 0xDF;
    // Make two dummy reads to clear the flag
    (void)buf->SCI->SR1;
    (void)buf->SCI->DRL;
  } else if (mode == SCI_RIE_ON) {
    // Enable Receive Interrupt
    buf->SCI->CR2 |= 0x20;
    // Make two dummy reads to clear the flag
    (void)buf->SCI->SR1;
    (void)buf->SCI->DRL;
  }
}

void SendString(circular_buffer *buf, int8_t *string, uint16_t size) {
  uint16_t i;
  if (size == 0) {
    for (i = 0; string[i] != '\0'; i++)
      (void)SCISendBuffer(buf, string[i]);
  } else {
    for (i = 0; i < size; i++)
      (void)SCISendBuffer(buf, string[i]);
  }
}


void SendFarString(circular_buffer *buf, int8_t * _FAR_ string, uint16_t size){
    uint16_t i; 
    if (size == 0){
        for (i=0; string[i]!='\0'; i++)
            (void)SCISendBuffer(buf, string[i]);
    }
    else{
        for (i=0; i<size; i++)
            (void)SCISendBuffer(buf, string[i]);
    }
}


#ifdef CRC
void SendStringC(circular_buffer *buf,
                 int8_t *string, uint16_t size, uint16_t *checksum) {
  uint16_t i;
  uint16_t index = 0;
  uint16_t crc   = *checksum;

  if (size == 0) {
    for (i = 0; string[i] != '\0'; i++) {
      (void)SCISendBuffer(buf, string[i]);
      index       = ((crc >> 8) ^ ((uint16_t)string[i] & 0x00FF)) & 0xFF;
      crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
      (*checksum) = crc;
    }
  } else {
    for (i = 0; i < size; i++) {
      (void)SCISendBuffer(buf, string[i]);
      index       = ((crc >> 8) ^ ((uint16_t)string[i] & 0x00FF)) & 0xFF;
      crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
      (*checksum) = crc;
    }
  }
}

void SendFarStringC(circular_buffer *buf,
                    int8_t * _FAR_ string, uint16_t size, uint16_t *checksum) {
  uint16_t i;
  uint16_t index = 0;
  uint16_t crc   = *checksum;

  if (size == 0) {
    for (i = 0; string[i] != '\0'; i++) {
      (void)SCISendBuffer(buf, string[i]);
      index       = ((crc >> 8) ^ ((uint16_t)string[i] & 0x00FF)) & 0xFF;
      crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
      (*checksum) = crc;
    }
  } else {
    for (i = 0; i < size; i++) {
      (void)SCISendBuffer(buf, string[i]);
      index       = ((crc >> 8) ^ ((uint16_t)string[i] & 0x00FF)) & 0xFF;
      crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
      (*checksum) = crc;
    }
  }
}

void SendCharValueC(circular_buffer *buf, char char_value, uint16_t *checksum) {
  uint16_t index = 0;
  uint16_t crc   = *checksum;

  (void)SCISendBuffer(buf, char_value);
  index       = ((crc >> 8) ^ ((uint16_t)char_value & 0x00FF)) & 0xFF;
  crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
  (*checksum) = crc;
}
#endif

void SendHexValue(circular_buffer *buf, int raw, uint16_t hex_value) {
  uint8_t hex_0, hex_1, hex_2, hex_3;
  if (!raw) {
    hex_0 = ConvertCharAscii(hex_value & 0x000F);
    hex_1 = ConvertCharAscii((hex_value >> 4) & 0x000F);
    if (hex_value <= 255) {
      (void)SCISendBuffer(buf, hex_1);
      (void)SCISendBuffer(buf, hex_0);
    } else {
      hex_2 = ConvertCharAscii((hex_value >> 8) & 0x000F);
      hex_3 = ConvertCharAscii(hex_value >> 12);
      (void)SCISendBuffer(buf, hex_3);
      (void)SCISendBuffer(buf, hex_2);
      (void)SCISendBuffer(buf, hex_1);
      (void)SCISendBuffer(buf, hex_0);
    }
  } else {
    hex_0 = hex_value & 0x00FF;
    hex_1 = hex_value >> 8;
    (void)SCISendBuffer(buf, hex_1);
    (void)SCISendBuffer(buf, hex_0);
  }
}

void SendHexValueFixedW(circular_buffer *buf, uint16_t hex_value){
  uint8_t hex_0, hex_1, hex_2, hex_3;

  hex_0 = ConvertCharAscii(hex_value & 0x000F);
  hex_1 = ConvertCharAscii((hex_value >> 4) & 0x000F);
  hex_2 = ConvertCharAscii((hex_value >> 8) & 0x000F);
  hex_3 = ConvertCharAscii(hex_value >> 12);
  (void)SCISendBuffer(buf, hex_3);
  (void)SCISendBuffer(buf, hex_2);    
  (void)SCISendBuffer(buf, hex_1);
  (void)SCISendBuffer(buf, hex_0); 
}

#ifdef CRC
void SendHexValueC(circular_buffer *buf, uint16_t hex_value, uint16_t *checksum) {

  uint8_t hex_0, hex_1, hex_2, hex_3;
  uint16_t index = 0;
  uint16_t crc   = *checksum;

  hex_0 = ConvertCharAscii(hex_value & 0x000F);
  hex_1 = ConvertCharAscii((hex_value >> 4) & 0x000F);

  if (hex_value <= 255) {
    // Note hex1 is printed before hex0
    index       = ((crc >> 8) ^ hex_1) & 0xFF;
    crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
    index       = ((crc >> 8) ^ hex_0) & 0xFF;
    crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
    (*checksum) = crc;

    (void)SCISendBuffer(buf, hex_1);
    (void)SCISendBuffer(buf, hex_0);
  } else {
    hex_3 = ConvertCharAscii(hex_value >> 12);
    hex_2 = ConvertCharAscii((hex_value >> 8) & 0x000F);

    index       = ((crc >> 8) ^ hex_3) & 0xFF;
    crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
    index       = ((crc >> 8) ^ hex_2) & 0xFF;
    crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
    index       = ((crc >> 8) ^ hex_1) & 0xFF;
    crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
    index       = ((crc >> 8) ^ hex_0) & 0xFF;
    crc         = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
    (*checksum) = crc;

    (void)SCISendBuffer(buf, hex_3);
    (void)SCISendBuffer(buf, hex_2);
    (void)SCISendBuffer(buf, hex_1);
    (void)SCISendBuffer(buf, hex_0);
    (*checksum) = crc;
  }
}

void SendLongValueC(circular_buffer *buf, uint32_t hex32_value,
                    uint16_t *checksum) {
  int i;
  uint8_t hex;
  uint16_t index = 0;
  uint16_t crc   = *checksum;

  // Iterate through all the nibbles of a 32-bit value
  for (i = 0; i < 8; ++i) {
    uint8_t shift = 4 * (8 - i - 1);
    hex           = ConvertCharAscii((hex32_value >> shift) & 0x0F);
    index         = ((crc >> 8) ^ hex) & 0xFF;
    crc           = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
    (void)SCISendBuffer(buf, hex);
  }
  (*checksum) = crc;
}
#endif

void SendLongValue(circular_buffer *buf, uint32_t hex32_value) {
  int i;
  uint8_t hex;

  // Iterate through all the nibbles of a 32-bit value
  for (i = 0; i < 8; ++i) {
    uint8_t shift = 4 * (8 - i - 1);
    hex           = ConvertCharAscii((hex32_value >> shift) & 0x0F);
    (void)SCISendBuffer(buf, hex);
  }
}

void SendDecValue(circular_buffer *buf, uint16_t dec_value) {
  uint8_t dec_ones, dec_tens, dec_thous, dec_tenthou;

  dec_ones = dec_value % 10;
  dec_tens    = (uint8_t)((dec_value / 10) % 10);
  dec_thous   = (uint8_t)(dec_value / 100) % 10;
  dec_tenthou = (uint8_t)(dec_value / 1000);

  if (dec_value > 999) {
    (void)SCISendBuffer(buf, ConvertCharAscii(dec_tenthou));
  }
  if (dec_value > 99) {
    (void)SCISendBuffer(buf, ConvertCharAscii(dec_thous));
  }
  if (dec_value > 9) {
    (void)SCISendBuffer(buf, ConvertCharAscii(dec_tens));
  }
  (void)SCISendBuffer(buf, ConvertCharAscii(dec_ones));
}

/*
ifdef CRC
void SendDecValueC(circular_buffer *buf, uint16_t dec_value, uint16_t* checksum){
    
    uint8_t dec_ones, dec_tens;
    uint16_t index = 0;
    uint16_t crc = *checksum;
    
    if (dec_value > 99)      // Take care of numbers bigger than 99
        dec_value = 0;
    
    dec_ones = dec_value % 10;
    dec_tens = (UINT8)(dec_value / 10);
    
    dec_ones = ConvertCharAscii(dec_ones);
    index = ((crc >> 8) ^ dec_ones) & 0xFF;
    crc = (crc_table[index] ^ (crc << 8)) & 0xFFFF;

    dec_tens = ConvertCharAscii(dec_tens);
    index = ((crc >> 8) ^ dec_tens) & 0xFF;
    crc = (crc_table[index] ^ (crc << 8)) & 0xFFFF;
    
    (void)SCISendBuffer(buf, dec_tens);
    (void)SCISendBuffer(buf, dec_ones);
    
    (*checksum) = crc;
}
#endif
*/

uint8_t ConvertCharAscii(uint8_t value) {
  if (value < 10)
    return value + 48;
  else
    return value + 55;
}

void CBufInit(circular_buffer *buf, void *sci_base, uint8_t *data, uint16_t size) {
  buf->inpos = buf->outpos = 0;
  buf->SCI                 = sci_base;
  buf->data                = data;
  buf->size                = size;
}

bool CBufPush(circular_buffer *buf, char in) {
  uint16_t x = buf->inpos;

  //if (++x >= bufsize) x = 0;
  if (++x >= buf->size) x = 0;

  if (x == buf->outpos) {
    //PrintConsoleString("\r\nBUFFER FULL!!!", 0); YOU CANT PRINT FROM HERE! IT CREATES A CIRCULAR FUNC CALL UNTIL YOU RUN OUT OF OR OVERRUN MEM
    return FALSE; // buffer full
  }

  buf->data[buf->inpos] = in;
  buf->inpos            = x;

  return TRUE;
}

bool CBufPop(circular_buffer *buf) {
  uint16_t x = buf->outpos;
  if (x == buf->inpos) return FALSE; // buffer empty
  //if (++x >= bufsize) x = 0;
  if (++x >= buf->size) x = 0;
  buf->outpos = x;
  return TRUE;
}

bool CBufEmpty(circular_buffer *buf) {
  if (buf->outpos == buf->inpos) {
    return TRUE;
  } else {
    return FALSE;
  }
}

/* void SCISendBuffer(circular_buffer *buf, uint8_t c){  // send a byte out */
/*     (void)CBufPush(buf,  c); */
/*     buf->SCI->CR2 |= 0x80; */
/* } */

void SCISendBuffer(circular_buffer *buf, uint8_t c) { // send a byte out
  bool ret_value;
  uint8_t i;

  i = 0;
  do {
    ret_value = CBufPush(buf, c);
    buf->SCI->CR2 |= 0x80;

    if (ret_value)
      return;

    if (!check_interrupts_disabled())
      DelayMs(5);
    else
      return;

  } while (i++ < 2);
}

#undef NEXT
#undef PREV
#undef CBUFSIZE
