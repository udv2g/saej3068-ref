#ifndef IDS_HANDLER_H
#define IDS_HANDLER_H

enum {ID_INCOMPLETE = 0, ID_COMPLETE, DATA};

bool id_parse(uint8_t ch);
void id_xmit(uint8_t ch, uint8_t page);

void data_parse(uint8_t ch);
void data_xmit(uint8_t ch, uint8_t page);

void ids_init(uint8_t ch);
void on_id_frame_receipt(uint8_t ch);
void on_id_frame_xmit(uint8_t ch);


#endif