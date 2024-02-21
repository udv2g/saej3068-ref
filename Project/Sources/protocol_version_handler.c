#include "globals.h"
#include "lin-cp.h"
#include "protocol_version_handler.h"
#include "utils.h"

#ifdef EV_CONFIG
#define XMIT_PVER_EMPTY      0xFF
#define RCV_PVER_EMPTY       0xFF
#define XMIT_PVER(x)         Ev##x
#define RCV_PVER(x)          Se##x
#define MY_ID_BOOL           FALSE
#else
#define XMIT_PVER_EMPTY      0xFF
#define RCV_PVER_EMPTY       0xFF
#define XMIT_PVER(x)         Se##x
#define RCV_PVER(x)          Ev##x
#define MY_ID_BOOL           TRUE
#endif

#ifdef PWM_CHARGE_ENABLE
    #define PWM_SUPPORT PVER_PWM,
#else
    #define PWM_SUPPORT
#endif

uint8_t pversions_list[] = { PWM_SUPPORT PVER_BASE, SUPPORTED_PVERSIONS 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }; //the missing commas are intentional, add a full page worth of N/A to not have to worry about it later

//#ifdef EV_CONFIG
//uint8_t pversions_list[] = { PWM_SUPPORT PVER_BASE, SUPPORTED_PVERSIONS 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }; //the missing comma is intentional, add a full page worth of N/A to not have to worry about it later
//#else
//uint8_t pversions_list[] = { PWM_SUPPORT PVER_BASE, PVER_SLASH_1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }; //the missing comma is intentional, add a full page worth of N/A to not have to worry about it later
//#endif

static uint8_t xmit_page[2]  = {0,0};
static uint8_t rcvd_pages[2] = {0,0};

uint8_t rcvd_protocol_versions[2][32] = {0};

void xmit_protocol_version_page(uint8_t ch) {
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_PVER(VersionPageNumber), xmit_page[ch]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_PVER(SupportedVersion1), pversions_list[xmit_page[ch] * 5]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_PVER(SupportedVersion2), pversions_list[xmit_page[ch] * 5 + 1]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_PVER(SupportedVersion3), pversions_list[xmit_page[ch] * 5 + 2]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_PVER(SupportedVersion4), pversions_list[xmit_page[ch] * 5 + 3]);
#pragma MESSAGE DISABLE C2705 //possible loss of data.is this the flags again? FIXME
  LW(ch, l_u8, XMIT_PVER(SupportedVersion5), pversions_list[xmit_page[ch] * 5 + 4]);

  if (pversions_list[(++xmit_page[ch]) * 5 - 1] == XMIT_PVER_EMPTY) xmit_page[ch] = 0;

  //clear flag
  LFC(ch, XMIT_PVER(VersionList));
}

uint8_t parse_protocol_versions(uint8_t ch)    {
#ifdef PWM_CHARGE_ENABLE
  uint8_t i = 2;
#else
  uint8_t i = 1;
#endif

  uint8_t chosen_pver = 0xFF;

  while (pversions_list[i] != 0xFF) {                                   //check the preference list
    if (check_rcvd_pvers(ch, pversions_list[i]))  {
      chosen_pver = pversions_list[i];
      break;
    }
    i++;
  }

  if ((chosen_pver == 0xFF) && check_rcvd_pvers(ch, PVER_BASE))  {          //check the base version if no other version was chosen
    chosen_pver = PVER_BASE;
  }

  return chosen_pver;
}

uint8_t rcv_protocol_version_page(uint8_t ch) {
  uint8_t rcv_page = LR(ch, l_u8, RCV_PVER(VersionPageNumber));
  uint8_t chosen_pver = 0xFF;

  static uint8_t new_rcvd_protocol_versions[2][32] = {0};

#define set_rcvd_pver(pver) new_rcvd_protocol_versions[ch][(pver) >> 3] |= (1 << ((pver) & 0b00000111))

  rcvd_pages[ch]++;
  if (rcv_page == 0) rcvd_pages[ch] = 1; //make sure we can resynchronize

    set_rcvd_pver(LR(ch, l_u8, RCV_PVER(SupportedVersion1)));
    set_rcvd_pver(LR(ch, l_u8, RCV_PVER(SupportedVersion2)));
    set_rcvd_pver(LR(ch, l_u8, RCV_PVER(SupportedVersion3)));
    set_rcvd_pver(LR(ch, l_u8, RCV_PVER(SupportedVersion4)));
    set_rcvd_pver(LR(ch, l_u8, RCV_PVER(SupportedVersion5)));

  if ((rcv_page + 1 == rcvd_pages[ch]) && (LR(ch, l_u8, RCV_PVER(SupportedVersion5)) == RCV_PVER_EMPTY)) {
    mem_copy(new_rcvd_protocol_versions[ch], rcvd_protocol_versions, 32);
    mem_init(new_rcvd_protocol_versions[ch], 32, 0);
#ifdef EV_CONFIG
    chosen_pver = parse_protocol_versions(ch);
#else //SE_CONFIG
    chosen_pver = 0;          //just need to know all pages have been received
#endif
    rcvd_pages[ch] = 0;
  }

  //clear flag
  LFC(ch, RCV_PVER(VersionList));
  return chosen_pver;
}

bool check_pver_supported(uint8_t pver) {
  uint8_t i = 0;

  if (pver == PVER_PWM) return FALSE;                                   //always reject PWM

  while (pversions_list[i] != 0xFF) {
    if (pversions_list[i] == pver) return TRUE;
    i++;
  }

  return FALSE;
}

#pragma INLINE
bool check_rcvd_pvers(uint8_t ch, uint8_t pver)	{
	return !!(rcvd_protocol_versions[ch][pver >> 3] & (1 << (pver & 0b00000111)));
}