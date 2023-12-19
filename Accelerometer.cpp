#include "Accelerometer.h"
#include "hal.h"


Accelerometer::Accelerometer() {
  isRunning = false;
  module_delay = 260;
  state = 0;
}





byte Accelerometer::process() {

  static int orientation = ORIENTATION_FLAT; 
    if (actionTask()) {
      static int AccX;
      static int AccY;
      static int AccZ;

      Wire.beginTransmission(MPU_6050);
      Wire.write(ACCEL_XOUT_HI);
      Wire.endTransmission(false);


      Wire.requestFrom(MPU_6050, 6, true);
      if(Wire.available() >= 6) {
        AccX = (Wire.read() << 8 | Wire.read());
        AccY = (Wire.read() << 8 | Wire.read());
        AccZ = (Wire.read() << 8 | Wire.read());

        AccZ = AccZ + 3500;


        if (AccZ > THRESHOLD) {
          orientation = ORIENTATION_FLAT;
      }
        if (AccZ > -THRESHOLD) {
          orientation = ORIENTATION_BASEUP;
      }
        if (AccX > THRESHOLD) {
          orientation = ORIENTATION_LANDSCAPE;
      }
        if (AccX > -THRESHOLD) {
          orientation = ORIENTATION_UPSIDEDOWN_LANDSCAPE;
      }
        if (AccY > THRESHOLD) {
          orientation = ORIENTATION_LEFTPORTRAIT;
      }
        if (AccY > -THRESHOLD) {
          orientation = ORIENTATION_RIGHTPORTRAIT;
      }
    }
  }
  return orientation;
}