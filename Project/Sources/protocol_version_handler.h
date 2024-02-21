#ifndef _protocol_version_HANDLER_H
#define _protocol_version_HANDLER_H

void xmit_protocol_version_page(uint8_t ch);
uint8_t rcv_protocol_version_page(uint8_t ch);

bool check_rcvd_pvers(uint8_t ch, uint8_t pver);
bool check_pver_supported(uint8_t pver);

#endif