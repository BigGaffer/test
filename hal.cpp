/************************************************************/
/* hal.cpp                                                  */
/*                                                          */
/* Hardware Abstraction Layer (HAL) implementation          */
/* Dr M A Oliver, October 2023                              */
/************************************************************/

#include "hal.h"


void Accel_init() {
  Serial.begin(115200);
  Wire.begin();
  Wire.beginTransmission(MPU_6050);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission(true);
}


void toggleLatch() {
  LATCH_HI;  // Pull the LATCH line high
  LATCH_LO;  // Pull the LATCH line low
}

void toggleCLK() {
  CLOCK_HI;  // Pull the CLOCK line high
  CLOCK_LO;  // Pull the CLOCK line low
}

void shiftBit(bool data) {
  // Pull the DATA line high or low depending on the value of data
  if (data) {
    DATA_HI;
  } else {
    DATA_LO;
  }
  toggleCLK();
}


// void toggleLatch() {
//   digitalWrite(LATCH, HIGH);   // Pull the LATCH line high
//   digitalWrite(LATCH, LOW);  // Pull the LATCH line low
// }

// void toggleCLK() {
//   PdigitalWrite(LATCH, LOW);   // Pull the CLOCK line high
//   digitalWrite(LATCH, LOW);  // Pull the CLOCK line low
// }

// void shiftBit(bool data) {
//   // Pull the DATA line high or low depending on the value of data
//   if (data) {
//     PORTD |= DATA;
//   } else {
//     PORTD &= ~DATA;
//   }
//   toggleCLK();
// }



void writeToShiftRegister(unsigned char value) {
  unsigned char mask = B10000000;  // use mask to select the bits in value one at a time
  while (mask > 0) {
    shiftBit(value & mask);
    mask = (mask >> 1);
  }
  toggleLatch();
}
