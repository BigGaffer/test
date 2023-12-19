/************************************************************/
/* trafficLights.h                                           */
/*                                                          */
/* Class library for blinking the Green LED.                */
/*                                                          */
/* ENGD2103, November 2023                                  */
/************************************************************/

#ifndef _TrafficLightsEq_h_
#define _TrafficLightsEq_h_

#include "Concurrent.h"  // Base class
#include "hal.h"


class TrafficLightsEq : public Concurrent {
  public:
    void process(byte sunny);
    TrafficLightsEq();

  private:
    int state;
};

#endif
