#include <hidef.h>
#include "derivative.h"
#include "hardware.h"
#include "types.h"
//#include "lin_hw_cfg.h"
//#include "sci.h"
#include "timers.h"
#include "globals.h"
#include "j1939.h"

void init_hardware(void)  {
  configure_oscillator();
  init_io();
  InitADC();
  InitRTI();
  InitSCIBuffers();
  SCIOpenCommunication(SCI2_BUF, UART_BAUD, FALSE, SCI_RIE_ON); // Initialize SCI2 with configured baud and interrupts
  init_pwm();
#ifdef EV_CONFIG
  j1939_init_hardware();
#endif
}

/*******************************************************
 * Oscillator
 ********************************************************/

//SYNDIV=0b11 and VCOFRQ = 0b11 for 48MHz for S12X ONLY

void configure_oscillator(void) {
  //configure oscillator for 24 MHz Fbus (pg. 387 (s12x pg. 486))
  PLL_Disable();              //disable PLL before changing settings
  Osc_Enable();               //enable external oscillator
  __REFDIV = 0x00;            //pre divider ratio at 1 (reference frequency = oscillator frequency)
  __REFFRQ = 0b10;            //reference frequency between 6 and 12 MHz [inc] (12)
  __SYNDIV = 0x01;            //Fvco = 2 * {reference frequency (12 MHz)} * {SYNDIV (1) + 1} = 48 MHz
  __VCOFRQ = 0b00;            //Fvco between 32 [inc] and 48 MHz [inc]
  __POSTDIV = 0b00;           //Fbus = Fvco / {POSTDIV (0) + 1} / 2 = 24 MHz
  PLL_Enable();               //enable PLL
  __PLLSEL = 1;               //select PLL
   OSC_Stabilize();           //wait for the oscillator to be stable, does not always work? needs investigation
}

/*******************************************************
 * I/O Configuration
 ********************************************************/

void init_io(void)  {
  //block 1 (top left)
  DDRT_DDRT5 = OUTPUT;        //uC_Pilot_B_State_C  /  Contactor B Error
  DDRT_DDRT4 = OUTPUT;        //uC_Pilot_B_State_B  /  Contactor B Close
  DDRT_DDRT3 = OUTPUT;        //uC_Pilot_A_State_C  /  Contactor A Error
  DDRT_DDRT2 = OUTPUT;        //uC_Pilot_A_State_B  /  Contactor A Close
  DDRT_DDRT1 = OUTPUT;        //CAN_SLEEP

  PTT = 0;                    //Drive all pins in T low

  //drive unused pins low
  DDRT_DDRT7 = OUTPUT; PTT_PTT7 = 0;
  DDRT_DDRT6 = OUTPUT; PTT_PTT6 = 0;
  DDRT_DDRT0 = OUTPUT; PTT_PTT0 = 0;

  //block 2
  PERS = 0;                   //disable pull resistors on port S
  PERS_PERS2 = 1;             //enable pull resistor on LI1 Rx (RXD_B)
  PERS_PERS0 = 1;             //enable pull resistor on LI0 Rx (RXD_A)

  //drive unused pins low
  DDRS_DDRS7 = OUTPUT; PTS_PTS7 = 0;
  DDRS_DDRS6 = OUTPUT; PTS_PTS6 = 0;
  DDRS_DDRS5 = OUTPUT; PTS_PTS5 = 0;
  DDRS_DDRS4 = OUTPUT; PTS_PTS4 = 0;

  //block 3
  DDRP_DDRP7 = INPUT;         //Over Temp Cutout
  DDRP_DDRP5 = OUTPUT;        //PWM_A
  DDRP_DDRP4 = OUTPUT;        //PWM_B
  DDRP_DDRP3 = INPUT;         //Pilot_det_B
  DDRP_DDRP2 = INPUT;         //Pilot_det_A

  //drive unused pins low
  DDRP_DDRP6 = OUTPUT; PTP_PTP6 = 0;
  DDRP_DDRP1 = OUTPUT; PTP_PTP1 = 0;
  DDRP_DDRP0 = OUTPUT; PTP_PTP0 = 0;

  PWM_A = 1;                  //drive CP line high so LIN possible
  PWM_B = 1;

  //block 4
#ifndef S12X  
  PERJ = 0;                   //disable pull resistors on port J
  DDRJ_DDRJ0 = OUTPUT;        //LIN_A_Enable (LI0)
  DDRJ_DDRJ1 = OUTPUT;        //LIN_B_Enable (LI1)
  DDRJ_DDRJ2 = OUTPUT;        //VMU_Wakeup
  DDRJ_DDRJ3 = OUTPUT;        //Sleep Shdn
#ifdef EV_CONFIG
  DDRJ_DDRJ4 = INPUT;         //uC_Sense_Signal_A_Lock
  DDRJ_DDRJ5 = INPUT;         //uC_Sense_Signal_A_Unlock
  DDRJ_DDRJ6 = INPUT;         //uC_Sense_Signal_B_Lock
  DDRJ_DDRJ7 = INPUT;         //uC_Sense_Signal_B_Unlock
#else
  DDRJ_DDRJ4 = OUTPUT;        //pre-release contactor control ch B
  DDRJ_DDRJ5 = OUTPUT;
  DDRJ_DDRJ6 = OUTPUT;
  DDRJ_DDRJ7 = OUTPUT;        //pre-release contactor control ch A
  
  PTJ = 0;                    //drive all contactor controls low
#endif //EV_CONFIG
#else  //S12X
  DDRA_DDRA0 = OUTPUT;        //LIN_A_Enable (LI0)
  DDRA_DDRA1 = OUTPUT;        //LIN_B_Enable (LI1)
  DDRA_DDRA2 = OUTPUT;        //VMU_Wakeup
  DDRA_DDRA3 = OUTPUT;        //Sleep Shdn
#ifdef EV_CONFIG
  DDRA_DDRA4 = INPUT;         //uC_Sense_Signal_A_Lock
  DDRA_DDRA5 = INPUT;         //uC_Sense_Signal_A_Unlock
  DDRA_DDRA6 = INPUT;         //uC_Sense_Signal_B_Lock
  DDRA_DDRA7 = INPUT;         //uC_Sense_Signal_B_Unlock
#else
  DDRA_DDRA4 = OUTPUT;        //pre-release contactor control ch B
  DDRA_DDRA5 = OUTPUT;
  DDRA_DDRA6 = OUTPUT;
  DDRA_DDRA7 = OUTPUT;        //pre-release contactor control ch A
  
  PORTA = 0;                  //drive all contactor controls low
#endif //EV_CONFIG
#endif //S12X

  VMU_WAKEUP = 0;
  SLEEP_SHDN = 0;             //Enable devices shut down in sleep

  LIN_A_ENABLE = 1;           //enable LIN A
  LIN_B_ENABLE = 1;           //enable LIN B

  //block 5 (second column) power only

  //block 6 controlled by peripherals

  //block 7
  /*
  AD0  => XX1AD0
  AD1  => XX1AD1
  AD2  => XX1AD2
  AD3  => XX1AD3
  AD4  => XX1AD4
  AD5  => XX1AD5
  AD6  => XX1AD6
  AD7  => XX1AD7
  AD8  => XX0AD0
  AD9  => XX0AD1
  AD10 => XX0AD2
  AD11 => XX0AD3
  AD12 => XX0AD4
  AD13 => XX0AD5
  AD14 => XX0AD6
  AD15 => XX0AD7
  */
  
#ifndef S12X
  DDR0AD_DDR0AD7 = OUTPUT;    //Relay_Control_B_Plus
  DDR0AD_DDR0AD6 = OUTPUT;    //Relay_Control_B_Minus
  DDR0AD_DDR0AD5 = OUTPUT;    //Relay_Control_A_Plus
  DDR0AD_DDR0AD4 = OUTPUT;    //Relay_Control_A_Minus
  DDR0AD_DDR0AD2 = OUTPUT;    //PWM_Enable_B
  DDR0AD_DDR0AD1 = OUTPUT;    //PWM_Enable_A
  ATDDIEN_IEN3 = 0;           //V_prox_B (disable digital input)
  ATDDIEN_IEN2 = 0;           //V_prox_A (disable digital input)
  ATDDIEN_IEN1 = 0;           //V_pilot_B (disable digital input)
  ATDDIEN_IEN0 = 0;           //V_pilot_A (disable digital input)
  
  //drive unused pins low
  DDR1AD_DDR1AD7 = OUTPUT; PT1AD_PT1AD7 = 0;
  DDR1AD_DDR1AD6 = OUTPUT; PT1AD_PT1AD6 = 0;
  DDR1AD_DDR1AD5 = OUTPUT; PT1AD_PT1AD5 = 0;
  DDR1AD_DDR1AD4 = OUTPUT; PT1AD_PT1AD4 = 0;
  DDR0AD_DDR0AD3 = OUTPUT; PT0AD_PT0AD3 = 0;
  DDR0AD_DDR0AD0 = OUTPUT; PT0AD_PT0AD0 = 0;
#else
  ATD0DIEN_IEN3 = 0;          //V_prox_B (disable digital input)
  ATD0DIEN_IEN2 = 0;          //V_prox_A (disable digital input)
  ATD0DIEN_IEN1 = 0;          //V_pilot_B (disable digital input)
  ATD0DIEN_IEN0 = 0;          //V_pilot_A (disable digital input)
  
  DDRB_DDRB7 = OUTPUT;        //Relay_Control_B_Plus
  DDRB_DDRB6 = OUTPUT;        //Relay_Control_B_Minus
  DDRB_DDRB5 = OUTPUT;        //Relay_Control_A_Plus
  DDRB_DDRB3 = OUTPUT;        //Relay_Control_A_Minus
  DDRB_DDRB4 = OUTPUT;        //CAN4_SLEEP
  DDRB_DDRB2 = OUTPUT;        //PWM_Enable_B
  DDRB_DDRB1 = OUTPUT;        //PWM_Enable_A
  DDRB_DDRB0 = OUTPUT;        //CAN1_SLEEP 
#endif  
  
  PWM_ENABLE_A = 0;           //Enable PWM switch A
  PWM_ENABLE_B = 0;           //Enable PWM switch B

}

/*******************************************************
 * Pulse Width Modulation Init (PWM)
 ********************************************************/

void init_pwm(void) {
  PWMPRCLK_PCKA = 0b011;      //PWM clock A 1/8 Fbus (3.0 MHz)          Use 0b100 (1/16) for 48MHz clock
  PWMSCLA = 15;               //3.0 MHz / (2 * 15) = 100 kHz
  PWMCAE_CAE4 = 0;            //set PWM4 to left aligned
  //PWMCLKAB_PCLKAB4 = 0;       //choose clock A for PWM4 (note: this setting is different for channels 2,3,6,7)        This is the default behavior and not supported on the S12X
  PWMCLK_PCLK4 = 1;           //scale the clock further by PWMSCLA (*2) (clock SA)
  PWMPER4 = 100;              //set period 100 kHz / 100 = 1 kHz
  PWMDTY4 = 50;               //set duty cycle to 50 / 100 = 50%
  PWMPOL_PPOL4 = 1;           //pin high for first part of duty cycle
  PWMCAE_CAE5 = 0;            //set PWM5 to left aligned
  ///PWMCLKAB_PCLKAB5 = 0;       //choose clock A for PWM5 (note: this setting is different for channels 2,3,6,7)       This is the default behavior and not supported on the S12X
  PWMCLK_PCLK5 = 1;           //scale the clock further by PWMSCLA (*2) (clock SA)
  PWMPER5 = 100;              //set period 100 kHz / 100 = 1 kHz
  PWMDTY5 = 50;               //set duty cycle to 50 / 100 = 50%
  PWMPOL_PPOL5 = 1;           //pin high for first part of duty cycle
}

/*******************************************************
 * Analog to Digital Converter (ADC)
 ********************************************************/
 
void InitADC(void){
    // Configures the ATD peripheral
    ATDCTL1_SRES = 0b00;      // 8-bit resolution
    ATDCTL1_SMP_DIS = 1;      // Automatically discharge sampling cap before sample.  Detect disconnects
    ATDCTL3 = 0b00001000;     // Right justified(bit 7), Number of conversion is 1 (bits 6-3), FIFO 0(bit 2), Continue on breakpoint (bits 1-0).
    ATDCTL4_SMP = 0b111;      // Sample time of 24 clocks (max)
    //ATDCTL4_PRS = 11;         // ATDCLK prescaler of 11 --> 24 MHz / 2 * (11 + 1) = 1 MHz                             -- Check
    ATDCTL4_PRS = 0;          // ATDCLK prescaler of 0  --> 24 MHz / 2 * (0 + 1) = 12 MHz
}

uint8_t PilotAReadADC(void){
  ATDCTL5_MULT = 0;           //single channel conversion
  ATDCTL5_Cx = ATDPILOTACH;
  while(!ATDSTAT0_SCF);       // wait for the sequence complete flag.
  return ATDDR0H;
}

uint8_t PilotBReadADC(void){
  ATDCTL5_MULT = 0;           //single channel conversion
  ATDCTL5_Cx = ATDPILOTBCH;
  while(!ATDSTAT0_SCF);       // wait for the sequence complete flag.
  return ATDDR0H;
}

uint8_t ProxAReadADC(void){
  ATDCTL5_MULT = 0;           //single channel conversion
  ATDCTL5_Cx = ATDPROXACH;
  while(!ATDSTAT0_SCF);       // wait for the sequence complete flag.
  return ATDDR0H;
}

uint8_t ProxBReadADC(void){
  ATDCTL5_MULT = 0;           //single channel conversion
  ATDCTL5_Cx = ATDPROXBCH;
  while(!ATDSTAT0_SCF);       // wait for the sequence complete flag.
  return ATDDR0H;
}

/*******************************************************
 * Timers
 ********************************************************/

//NOTE:!! LIN system uses timer 0

void init_timers(void)  {
  TSCR1_TEN = 0;              //disable timers while changing configuration

  //configure timer 6 to interrupt every 2.5 ms for LIN tick
  OCPD_OCPD6 = 1;             //disconnect output compare pin (pg. 755)
  TIOS_IOS6 = 1;              //enable output compare/interrupt
  CFORC_FOC6 = 1;             //force a compare event without firing interrupt (no idea why this is needed but is in the example code)
  TTOV_TOV6 = 1;              //cause output compare (interrupt) on overflow
  TIE_C6I = 1;                //enable timer6 compare interrupt
  TC6 = TIMER_6_PERIOD;       //see timers.h

  //configure timer 1 to interrupt every 1.3 ms for analog sample timeout
  OCPD_OCPD1 = 1;             //disconnect output compare pin (pg. 755)
  TIOS_IOS1 = 1;              //enable output compare/interrupt
  CFORC_FOC1 = 1;             //force a compare event without firing interrupt (no idea why this is needed but is in the example code)
  TTOV_TOV1 = 1;              //cause output compare (interrupt) on overflow
  TIE_C1I = 1;                //enable timer1 compare interrupt
  TC1 = TIMER_1_PERIOD;       //see timers.h

  TSCR1_TEN = 1;              //enable timers
}

/*******************************************************
 * Real Time Interrupt (RTI)
 ********************************************************/

void InitRTI(void){
  //pgs. 369-371
  rti_sel_oscclk();           //use OSCCLK for RTI source
  //period = 12MHz (OSCCLK) / 12e3 => 1ms
  //rti_sel_oscclk() = 0x8B;  // This is for 1ms
  //period = 12MHz (OSCCLK) / 13e3 => 923 Hz / 1.08ms
  __RTI_CTRL_REG = 0x8C;
  // Enable RTI Interrupt
  __RTIE = 1;
}

/*******************************************************
 * Delay Functions
 ********************************************************/

void DelayMs(uint16_t ms){
  volatile uint16_t i;  // Needs volatile so compiler does not optimize
  while (ms > 0){
    i = (MCU_BUS_FREQ/1000/13);    //this is gross, consider fixing (loop takes 13 cycles)
    _FEED_COP();  //important
    while (i > 0) {
      i = i - 1;
    }
    ms = ms - 1;
  }
}

void DelayUs(uint16_t us){
  volatile uint16_t i;  // Needs volatile so compiler does not optimize
  while (us > 0){
    //i =  ((MCU_BUS_FREQ+(13*1000000/2))/1000000/13);    //Extra term to improve rounding
    i =  (MCU_BUS_FREQ/1000000/13);    //Closer to the time it is supposed to be
    _FEED_COP();
    while (i > 0) {
      i = i - 1;
    }
    us = us - 1;
  }
}

/*******************************************************
 * Interrupt Helper Functions
 ********************************************************/

#undef A               //We need the identifier 'A' to refer to register A

//This must be a (non-inline) function to avoid trampling on the A register of the calling code
uint8_t check_interrupts_disabled() {
  uint8_t interruptsDisabled;
    asm{
      TFR CCR,A;
      ANDA #$10;
      STAA interruptsDisabled;
    }
  return interruptsDisabled;
}
