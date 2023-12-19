#include "Counter.h"
#include "hal.h"
#include "debounce.h"


Counter::counter() { //changed
  isRunning = false;
  module_delay = 30;
  state = 0;
}

void Counter::setSwitchstate(switch_state_t sw) {
  B1_state = sw;
}



int Counter::process() {
  static int i = 0;

  if (actionTask()) {
    switch (state) {

      case 0:
        if (B1_state == DEBOUNCED_PRESS) {
            i = i + 1;
            state = 1;
          }
        break;

      case 1:
        if (B1_state != DEBOUNCED_PRESS) {
          state = 0;
        }
        break;

      default:
        state = 0;
    }
  }
  return i;
}
