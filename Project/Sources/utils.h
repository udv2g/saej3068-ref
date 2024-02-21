#ifndef _UTILS_H
#define _UTILS_H

int16_t read_int16_le(uint8_t *buf, int *offset, int size);
void write_int16_le(int16_t value, uint8_t *buf, int *offset, int size);

bool mem_compare(void *obj1_p, void *obj2_p, uint8_t size);
void mem_init(void *obj_p, uint8_t size, uint8_t value);
void mem_copy(void *source_p, void *dest_p, uint8_t size);

#endif