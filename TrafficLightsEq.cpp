/************************************************************/
/* GreenBlinker.cpp                                         */
/*                                                          */
/* Class library for blinking the Green LED.                */
/*                                                          */
/* ENGD2103, November 2023                                  */
/************************************************************/

#include "TrafficLightsEq.h"
#include "hal.h"

//--------------------------------------------------------------
// Constructor
// Puts class into a sane state whenever an instance of the
// class is declared.
//--------------------------------------------------------------

TrafficLightsEq::TrafficLightsEq() {
  isRunning = false;
  module_delay = 10;
  state = 0;
}


//--------------------------------------------------------------
// process()
//
// Member function that processes timed activity. It takes care
// of timeouts, running / not running etc.
// Returns: nothing
//--------------------------------------------------------------

void TrafficLightsEq::process(byte sunny) {
  // Only process the finite state machine on a 'tick' / 'step'
  if (actionTask())
  // FSM belongs here
  {


    static char state = 0;
    switch (state) {
      case 0:
        PORTD = LED_AMBER_R | LED_AMBER_L;
        module_delay = 1500;
        state = 1;
        break;
      case 1:
        PORTD = LED_RED_R | LED_RED_L;
        module_delay = 1000;
        state = 2;
        break;
      case 2:
        PORTD = LED_RED_R | LED_RED_L | LED_AMBER_L;
        module_delay = 1000;
        state = 3;
        break;
      case 3:
        PORTD = LED_RED_R | LED_GREEN_L;
        if (sunny == ORIENTATION_LEFTPORTRAIT) {
          module_delay = 7000;
        } else if (sunny == ORIENTATION_RIGHTPORTRAIT) {
          module_delay = 3000;
        } else {
          module_delay = 5000;
        }
        state = 4;
        break;
      case 4:
        PORTD = LED_RED_R | LED_AMBER_L;
        module_delay = 2000;
        state = 5;
        break;
      case 5:
        PORTD = LED_RED_R | LED_RED_L;
        module_delay = 1000;
        state = 6;
        break;
      case 6:
        PORTD = LED_RED_R | LED_RED_L | LED_AMBER_R;
        module_delay = 1000;
        state = 7;
        break;
      case 7:
        PORTD = LED_RED_L | LED_GREEN_R;
        if (sunny == ORIENTATION_LEFTPORTRAIT) {
          module_delay = 3000;
        } else if (sunny == ORIENTATION_RIGHTPORTRAIT) {
          module_delay = 7000;
        } else {
          module_delay = 5000;
        }

        state = 8;
        break;
      case 8:
        PORTD = LED_RED_L | LED_AMBER_R;
        module_delay = 2000;
        state = 1;
        break;
      default:
        state = 0;
    }
  }
}
