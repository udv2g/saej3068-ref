#include "types.h"
#include "utils.h"

/* read_int16_le:
 * Reads a 16 bit integer from the given circular buffer of length size
 * at the specified offset.
 *
 * Note: The offset is updated by 2 to reflect the size
 *       of the read integer in bytes
 * Returns: The just read 16-bit short integer
 */

int16_t read_int16_le(uint8_t *buf, int *offset, int size) {
  int16_t value;
  int i = *offset;

  value = (buf[(i + 1) % size] & 0x00FF);
  value = (value << 8) | (buf[i] & 0x00FF);

  *offset = (i + 2) % size;
  return value;
}

/* write_int16_le:
 * Write a signed or unsigned short value at the given offset in buf
 * The bytes are written in a LITTLE ENDIAN fashion
 */

void write_int16_le(int16_t value, uint8_t *buf, int *offset, int size) {
  int i = *offset;

  buf[i % size]       = value & 0xFF;
  buf[(i + 1) % size] = ((value >> 8) & 0xFF);
  *offset             = (i + 2) % size;
}

/* read_int16_be:
 * Reads a 16 bit integer from the given circular buffer of length size
 * at the specified offset. 
 *
 * Note: The offset is updated by 2 to reflect the size 
 *       of the read integer in bytes
 * Returns: The just read 16-bit short integer
 */
int16_t read_int16_be(int8_t *buf, int *offset, int size)
{
    int16_t value;
    int i = *offset;
    
    value = (buf[i % size] & 0x00FF);
    value = (value << 8) | (buf[(i + 1) % size] & 0x00FF);
    *offset = (i + 2) % size;
    return value;
}

/* write_int16_be:
 * Write a signed or unsigned short value at the given offset in buf
 * The bytes are written in a BIG ENDIAN fashion
 */

void write_int16_be(int16_t value, int8_t *buf, int *offset, int size)
{
    int i = *offset;
    
    buf[i % size] = ((value >> 8) & 0xFF);
    buf[(i + 1) % size] = value & 0xFF;
    *offset = (i + 2) % size;
}

/* read_int32_be:
 * Reads a 32 bit integer from the given circular buffer of length size
 * at the specified offset. 
 * Assumes BIG ENDIAN encoding
 *
 * Note: The offset is updated by 4 to reflect the size 
 *       of the read integer in bytes
 * Returns: The just read integer
 */
#pragma MESSAGE DISABLE C12056
int32_t read_int32_be(uint8_t *buf, int *offset, int size)
{
    int32_t value;
    int i = *offset;
    
    value = (buf[i % size] & 0x000000FF);
    value = (value << 8) | (buf[(i + 1) % size] & 0x000000FF);
    value = (value << 8) | (buf[(i + 2) % size] & 0x000000FF);
    value = (value << 8) | (buf[(i + 3) % size] & 0x000000FF);
    
    *offset = (i + 4) % size;
    
    return value;
}

/* write_int32_be:
 * Write a signed or unsigned short value at the given offset in buf
 * The bytes are written in a BIG ENDIAN fashion
 */

void write_int32_be(uint32_t value, uint8_t *buf, int *offset, int size)
{
    int i = *offset;
    
    buf[i % size]       = ((value >> 24) & 0xFF); 
    buf[(i + 1) % size] = ((value >> 16) & 0xFF);
    buf[(i + 2) % size] = ((value >>  8) & 0xFF);
    buf[(i + 3) % size] = value & 0xFF;
    
    *offset = (i + 4) % size;
}

bool mem_compare(void * _FAR_ obj1_p, void * _FAR_ obj2_p, uint8_t size) {
  uint8_t i, * _FAR_ obj1_u8_p = obj1_p, * _FAR_ obj2_u8_p = obj2_p;

  for (i = 0; i < size; i++) {
    if (obj1_u8_p[i] != obj2_u8_p[i]) {
      return FALSE;
    }
  }

  return TRUE;
}

void mem_init(void * _FAR_ obj_p, uint8_t size, uint8_t value) {
  uint8_t i, * _FAR_ obj_u8_p = obj_p;

  for (i = 0; i < size; i++) {
    obj_u8_p[i] = value;
  }
}

void mem_copy(void * _FAR_ source_p, void * _FAR_ dest_p, uint8_t size) {
  uint8_t i, * _FAR_ source_u8_p = source_p, * _FAR_ dest_u8_p = dest_p;

  for (i = 0; i < size; i++) {
    dest_u8_p[i] = source_u8_p[i];
  }
}