#include "Scheduler.h"
#include "hal.h"


Scheduler::Scheduler() {
  isRunning = false;
  module_delay = 10;
  state = 0;
  mode = 1;
}
bool Scheduler::getAccelerometer() {
  return Accelerometer; 
}

bool Scheduler::getCounter() {
  return Counter; 
}
bool Scheduler::getHeartbeat() {
  return Heartbeat; 
}
bool Scheduler::getTrafficLightsEq() {
  return TrafficLightsEq; 
}
bool Scheduler::getDebounce() {
  return Debounce; 
}

byte Scheduler::process(switch_state_t B2_state) {
  if (actionTask()) {
    switch (state) {
      case 0:
        Accelerometer = false;
        Counter = false;
        Heartbeat = true;
        TrafficLightsEq = true;
        mode = 1;
        if (B2_state != DEBOUNCED_PRESS) {
          state = 1;
        }
        break;
      case 1:
        mode = 1;
        if (B2_state == DEBOUNCED_PRESS) {
          state = 2;
        }
        break;
      
      case 2:
      Accelerometer = false;
      Counter = true;
      Heartbeat = true;
      TrafficLightsEq = false;
      mode = 2;
      if (B2_state != DEBOUNCED_PRESS) {
        state = 3;
      }
      break;
    case 3:
      mode = 2;
      if (B2_state == DEBOUNCED_PRESS) {
        state = 4;
      }

      break;

    case 4:
        Accelerometer = true;
        Counter = false;
        Heartbeat = true;
        TrafficLightsEq = false;
        mode = 3;
        if (B2_state != DEBOUNCED_PRESS) {
          state = 5;
        }
        break;

      case 5:
        mode = 3;
        if (B2_state == DEBOUNCED_PRESS) {
          state = 6;
        }
        break;

      case 6:
        Accelerometer = false;
        Counter = true;
        Heartbeat = true;
        TrafficLightsEq = true;
        mode = 4;
        if (B2_state != DEBOUNCED_PRESS){
          state = 7;
        }
        break;

      case 7:
        mode = 4;
        if (B2_state == DEBOUNCED_PRESS){
          state = 8;
        }
        break;
      case 8:
        Accelerometer = true;
        Counter = false;
        Heartbeat = true;
        TrafficLightsEq = true;
        mode = 5;
        if (B2_state != DEBOUNCED_PRESS){
          state = 9;
        }
        break;

      case 9:
        mode = 5;
        if (B2_state == DEBOUNCED_PRESS) {
          state = 0;
        }
        break;


    }
  }
  return mode;
}