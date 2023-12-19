/************************************************************/
/* hal.h                                                    */
/*                                                          */
/* Hardware Abstration Layer (HAL) definitions              */
/* Dr M A Oliver, October 2023                              */
/************************************************************/

#ifndef _HAL_H_
#define _HAL_H_

#include <Arduino.h>
#include <Wire.h>


#define LEDS_OFF B00000000
#define LED_RED_L B00000100
#define LED_RED_R B00100000
#define LED_AMBER_L B00001000
#define LED_AMBER_R B01000000
#define LED_GREEN_L B00010000
#define LED_GREEN_R B10000000


#define DATA B00000001
#define CLOCK B00010000
#define LATCH B00100000




#define THRESHOLD 14000
#define MPU_6050 0x68
#define PWR_MGMT_1 0x6B
#define ACCEL_XOUT_HI 0x3B




#define ORIENTATION_FLAT 0
#define ORIENTATION_BASEUP 1
#define ORIENTATION_LANDSCAPE 2
#define ORIENTATION_UPSIDEDOWN_LANDSCAPE 3
#define ORIENTATION_LEFTPORTRAIT 4
#define ORIENTATION_RIGHTPORTRAIT 5 



#define DATA_HI PORTB |= DATA
#define DATA_LO PORTB &= ~DATA
#define CLOCK_HI PORTB |= CLOCK
#define CLOCK_LO PORTB &= ~CLOCK
#define LATCH_HI PORTB |= LATCH
#define LATCH_LO PORTB &= ~LATCH


#define SEG_A B00000001
#define SEG_B B00000010
#define SEG_C B00000100
#define SEG_D B00001000
#define SEG_E B00010000
#define SEG_F B00100000
#define SEG_G B01000000
#define HB B10000000

#define Switch_A B00000010  // button 1 pin
#define Switch_B B00000001  // button 2 pin

#define SwitchA_released (PINC & Switch_A)
#define SwitchB_released (PINC & Switch_A)
#define SwitchA_pressed !SwitchA_released
#define SwitchB_pressed !SwitchB_released

#define debounce 500


typedef enum {
  NOT_PRESSED,
  PARTIAL_PRESS,
  DEBOUNCED_PRESS
}
switch_state_t;
















#define CHAR_0 B00111111
#define CHAR_1 B00000110
#define CHAR_2 B01011011
#define CHAR_3 B01001111
#define CHAR_4 B01100110
#define CHAR_5 B01101101
#define CHAR_6 B01111101
#define CHAR_7 B00000111
#define CHAR_8 B01111111
#define CHAR_9 B01101111
#define CHAR_A B01110111
#define CHAR_B B01111100
#define CHAR_C B00111001
#define CHAR_D B01011110
#define CHAR_E B01111001
#define CHAR_F B01110001
#define CHAR_L B00111000
#define CHAR_U B00111110
#define CHAR_r B00010000  //may be wrong
#define CHAR_l B00001100
//#define HB B10000000


const byte characters[] = {
  CHAR_0,
  CHAR_1,
  CHAR_2,
  CHAR_3,
  CHAR_4,
  CHAR_5,
  CHAR_6,
  CHAR_7,
  CHAR_8,
  CHAR_9,
  CHAR_0,
  CHAR_A,
  CHAR_B,
  CHAR_C,
  CHAR_D,
  CHAR_E,
  CHAR_F
};

const byte orientationchars[] = {
  CHAR_F,
  CHAR_B,
  CHAR_L,
  CHAR_U,
  CHAR_r,
  CHAR_l
};


void writeToShiftRegister(unsigned char value);
void Accel_init();

#endif
