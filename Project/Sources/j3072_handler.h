#ifndef J3072_HANDLER_H
#define J3072_HANDLER_H

enum {CERT_INCOMPLETE = 0, CERT_COMPLETE, SUNSPEC};

bool cert_parse(uint8_t ch);
void cert_xmit(uint8_t ch, uint8_t page);

void j3072_init(uint8_t ch);
void on_j3072_frame_receipt(uint8_t ch);
void on_j3072_frame_xmit(uint8_t ch);


#endif