#ifndef _Heartbeat_h_
#define _Heartbeat_h_

#include <Arduino.h>
#include "Concurrent.h"

class Heartbeat : public Concurrent {
public:
  byte                process();
  Heartbeat();

private:
  int state;
  byte hb;
};

#endif