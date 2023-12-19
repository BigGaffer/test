#ifndef _Scheduler_h_
#define _Scheduler_h_

#include <Arduino.h>
#include "Concurrent.h"
#include "debounce.h"

class Scheduler : public Concurrent {
  public:
    byte process(switch_state_t B2_state);
    Scheduler();
    bool getAccelerometer();
    bool getCounter();
    bool getHeartbeat();
    bool getTrafficLightsEq();
    bool getDebounce();
    //void process(switch_state_t state);

  private:
    int state;
    bool Accelerometer, Counter, Heartbeat, TrafficLightsEq, Debounce;
    byte mode;
};
#endif