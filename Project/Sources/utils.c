#include "types.h"

/* read_int16_be:
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

bool mem_compare(void *obj1_p, void *obj2_p, uint8_t size) {
  uint8_t i, *obj1_u8_p = obj1_p, *obj2_u8_p = obj2_p;

  for (i = 0; i < size; i++) {
    if (obj1_u8_p[i] != obj2_u8_p[i]) {
      return FALSE;
    }
  }

  return TRUE;
}

void mem_init_ff(void *obj_p, uint8_t size) {
  uint8_t i, *obj_u8_p = obj_p;

  for (i = 0; i < size; i++) {
    obj_u8_p[i] = 0xFF;
  }
}