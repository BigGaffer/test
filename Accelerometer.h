#ifndef _Accelerometer_h_
#define _Accelerometer_h_

#include <Arduino.h>
#include "Concurrent.h"

class Accelerometer : public Concurrent {
  public:
    byte process();
    Accelerometer();

  private:
    int state;
};

#endif