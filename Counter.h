#ifndef _Counter_h_
#define _Counter_h_

#include "Concurrent.h"
#include "hal.h"
#include "debounce.h"


class Counter : public Concurrent {
  public:
    int process();
    counter();
    void setSwitchstate(switch_state_t sw);
  private:
    switch_state_t B1_state;
    int state;

};

#endif