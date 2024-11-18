#ifndef _UTILS_H
#define _UTILS_H

#include "derivative.h"

int16_t read_int16_le(uint8_t *buf, int *offset, int size);
void write_int16_le(int16_t value, uint8_t *buf, int *offset, int size);
int16_t read_int16_be(uint8_t *buf, int *offset, int size);
void write_int16_be(int16_t value, uint8_t *buf, int *offset, int size);
int32_t read_int32_be(uint8_t *buf, int *offset, int size);
void write_int32_be(uint32_t value, uint8_t *buf, int *offset, int size);

bool mem_compare(void * _FAR_ obj1_p, void * _FAR_ obj2_p, uint8_t size);
void mem_init(void * _FAR_ obj_p, uint8_t size, uint8_t value);
void mem_copy(void * _FAR_ source_p, void * _FAR_ dest_p, uint8_t size);

#endif