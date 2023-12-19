#ifndef _Debounce_h_
#define _Debounce_h_

#include "Concurrent.h"
#include "hal.h"

class Debounce : public Concurrent {
public:
  void process();
  switch_state_t getSwitch1();
  switch_state_t getSwitch2();
  Debounce();

private:
  switch_state_t B1_state, B2_state;
  switch_state_t state1, state2;
  unsigned long debounce_count1, debounce_count2;
};

#endif
