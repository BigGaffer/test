#include "Debounce.h"
#include "hal.h"


Debounce::Debounce() {
  isRunning = false;
  module_delay = 15;
  state1 = NOT_PRESSED;
  state2 = NOT_PRESSED;
}


void Debounce::process() {
  if (actionTask()) {
    switch (state1) {
      case NOT_PRESSED:
        if (SwitchA_released) state1 = NOT_PRESSED;
        else {
          debounce_count1 = millis();
          state1 = PARTIAL_PRESS;
        }
        break;
      case PARTIAL_PRESS:
        if (SwitchA_released) state1 = NOT_PRESSED;
        else if ((millis() - debounce_count1) < debounce) state1 = PARTIAL_PRESS;
        else state1 = DEBOUNCED_PRESS;
        break;
      default:
        state1 = NOT_PRESSED;
        break;
    }

    switch (state2) {
      case NOT_PRESSED:
        if (SwitchB_released) state2 = NOT_PRESSED;
        else {
          debounce_count2 = millis();
          state2 = PARTIAL_PRESS;
        }
        break;
      case PARTIAL_PRESS:
        if (SwitchB_released) state2 = NOT_PRESSED;
        else if ((millis() - debounce_count2) < debounce) state2 = PARTIAL_PRESS;
        else state2 = DEBOUNCED_PRESS;
        break;
      default:
        state2 = NOT_PRESSED;
        break;
    }
    B1_state = state1;
    B2_state = state2;
  }
}

switch_state_t Debounce::getSwitch1(){
  return state1;
} 
switch_state_t Debounce::getSwitch2() {
  return state2;
}