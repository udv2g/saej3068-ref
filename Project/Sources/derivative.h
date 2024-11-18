#ifdef S12X

#include <MC9S12XET256.h>

#pragma LINK_INFO DERIVATIVE "MC9S12XET256"

#else 

#include <mc9s12g96.h>

#pragma LINK_INFO DERIVATIVE "mc9s12g96"

#endif

/*******************************************************
 * Oscillator
 ********************************************************/

#ifdef S12X
#define __PLLON     PLLCTL_PLLON
#define __REFDIV    REFDV_REFDIV
#define __REFFRQ    REFDV_REFFRQ
#define __SYNDIV    SYNR_SYNDIV
#define __VCOFRQ    SYNR_VCOFRQ
#define __POSTDIV   POSTDIV_POSTDIV
#define __PLLSEL    CLKSEL_PLLSEL

#define Osc_Enable()    (void) 0
#define PLL_Disable()   PLLCTL_PLLON = 0
#define PLL_Enable()    PLLCTL_PLLON = 1; \
                        while(!CRGFLG_LOCK)        //Wait till the PLL VCO is within tolerance
#define OSC_Stabilize() (void) 0

#define COP_Enable()    COPCTL = 0b01000101
//101 2^22/12MHZ = .3 sec watchdog

#else
#define __REFDIV    CPMUREFDIV_REFDIV
#define __REFFRQ    CPMUREFDIV_REFFRQ
#define __SYNDIV    CPMUSYNR_SYNDIV
#define __VCOFRQ    CPMUSYNR_VCOFRQ
#define __POSTDIV   CPMUPOSTDIV
#define __PLLSEL    CPMUCLKS_PLLSEL
#define __SETCOP    COPCTL

#define Osc_Enable()    CPMUOSC_OSCE = 1
#define PLL_Disable()   (void) 0
#define PLL_Enable()    (void) 0
#define OSC_Stabilize() while(!CPMUFLG_UPOSC)

#define COP_Enable()    CPMUCLKS_COPOSCSEL1 = 1;  /*set COP to ACLK (10khz)*/ \
                        CPMUCOP_CR2 = 1           /*for ACLK 2^13 cycles set 0.8 seconds*/
#endif

/*******************************************************
 * Analog to Digital Converter (ADC)
 ********************************************************/
 
#ifdef S12X

#define ATDCTL1_SRES    ATD0CTL1_SRES
#define ATDCTL1_SMP_DIS ATD0CTL1_SMP_DIS
#define ATDCTL3         ATD0CTL3
#define ATDCTL4_SMP     ATD0CTL4_SMP
#define ATDCTL4_PRS     ATD0CTL4_PRS
#define ATDCTL5_MULT    ATD0CTL5_MULT
#define ATDCTL5_Cx      ATD0CTL5_Cx
#define ATDSTAT0_SCF    ATD0STAT0_SCF
#define ATDDR0H         ATD0DR0H

#endif

/*******************************************************
 * Real Time Interrupt (RTI)
 ********************************************************/
 
#ifdef S12X
#define rti_sel_oscclk()  (void) 0
#define __RTI_CTRL_REG    RTICTL
#define __RTIE            CRGINT_RTIE
#define __RTIF            CRGFLG_RTIF
#else
#define rti_sel_oscclk()  CPMUCLKS_RTIOSCSEL = 1
#define __RTI_CTRL_REG    CPMURTI
#define __RTIE            CPMUINT_RTIE
#define __RTIF            CPMUFLG_RTIF
#endif

/*******************************************************
 * Timers
 ********************************************************/

#ifdef S12X

#define TSCR1_TEN   ECT_TSCR1_TEN

#define OCPD_OCPD6  ECT_OCPD_OCPD6
#define TIOS_IOS6   ECT_TIOS_IOS6
#define CFORC_FOC6  ECT_CFORC_FOC6
#define TTOV_TOV6   ECT_TTOV_TOV6
#define TIE_C6I     ECT_TIE_C6I
#define TC6         ECT_TC6
#define TFLG1_C6F   ECT_TFLG1_C6F

#define OCPD_OCPD1  ECT_OCPD_OCPD1
#define TIOS_IOS1   ECT_TIOS_IOS1
#define CFORC_FOC1  ECT_CFORC_FOC1
#define TTOV_TOV1   ECT_TTOV_TOV1
#define TIE_C1I     ECT_TIE_C1I
#define TC1         ECT_TC1
#define TCNT        ECT_TCNT
#define TFLG1_C1F   ECT_TFLG1_C1F

#define VectorNumber_Vtimer1    VectorNumber_Vectch1
#define VectorNumber_Vtimer6    VectorNumber_Vectch6

#else

#define VectorNumber_Vtimer1    VectorNumber_Vtimch1
#define VectorNumber_Vtimer6    VectorNumber_Vtimch6

#endif

/*******************************************************
 * Controller Area Network Interrupt (CAN)
 ********************************************************/
 
#ifdef S12X
#define   CANCTL1_CANE_MASK     CAN0CTL1_CANE_MASK
#define   CANCTL0_INITRQ_MASK   CAN0CTL0_INITRQ_MASK
#define   CANCTL0_WUPE_MASK     CAN0CTL0_WUPE_MASK
#define   CANCTL1_INITAK_MASK   CAN0CTL1_INITAK_MASK
#define   CANCTL1_WUPM_MASK     CAN0CTL1_WUPM_MASK
#define   CANCTL1_LISTEN_MASK   CAN0CTL1_LISTEN_MASK
#define   CANRIER_WUPIE_MASK    CAN0RIER_WUPIE_MASK
#define   CANRIER_RXFIE_MASK    CAN0RIER_RXFIE_MASK
#else
#define VectorNumber_Vcan0rx   VectorNumber_Vcanrx
#define VectorNumber_Vcan0tx   VectorNumber_Vcantx 
#define CAN0RFLG               CANRFLG
#define VectorNumber_Vcan0wkup VectorNumber_Vcanwkup
#define CAN0RFLG_WUPIF         CANRFLG_WUPIF
#endif

/*******************************************************
 * Pointers
 ********************************************************/

#ifdef S12X
#define _FAR_ far
#else
#define _FAR_
#endif
