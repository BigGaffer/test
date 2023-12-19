#include "Heartbeat.h"
#include "hal.h"


Heartbeat::Heartbeat() {
  isRunning = false;
  module_delay = 260;
  state = 0;
  hb = 0;
}

byte Heartbeat::process() {

  if (actionTask()) {
    static int state = 0;
    switch (state) {
      case 0:
        hb = HB;
        state = 1;
        break;
      case 1:
        hb = 0;
        state = 0;
        break;
      default:
        state = 0;
    }
  }
  return hb;
}