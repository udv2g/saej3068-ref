#ifndef _INFO_CODE_HANDLER_H
#define _INFO_CODE_HANDLER_H

bool set_info_code(uint8_t ch, uint8_t code);
bool set_priority_info_code(uint8_t ch, uint8_t code);
bool clear_info_code(uint8_t ch, uint8_t code);
void clear_all_info_codes(uint8_t ch);

void xmit_info_code_page(uint8_t ch);
void rcv_info_code_page(uint8_t ch);

#endif