/************************************************************/
/* MainCode.ino           Taylor elton                     */
/*                        P2725355                          */
/* Bare metal / concurrency                                 */
/* ENGD2103, October 2023                                   */
/************************************************************/


#include "Concurrent.h"
#include "hal.h"
#include "TrafficLightsEq.h"
#include "Heartbeat.h"
#include "debounce.h"
#include "Counter.h"
#include "Accelerometer.h"
#include "Scheduler.h"

byte hbeat;
byte t;
byte orientation;
byte mode;

Debounce Debouncecontrol;
TrafficLightsEq TrafficLightsEqcontrol;
Heartbeat Heartbeatcontrol;
Counter Countercontrol;
Accelerometer Accelerometercontrol;
Scheduler scheduler;

void setup() {

  DDRC &= ~Switch_A;
  PORTC |= Switch_A;

  DDRC &= ~Switch_B;
  PORTC |= Switch_B;

  DDRB |= CLOCK;
  DDRB |= LATCH;
  DDRB |= DATA;
  PORTB = 0;

  DDRD |= B11111100;
  Accel_init();
  Serial.begin(9600);
  Debouncecontrol.setRunning(true);
  TrafficLightsEqcontrol.setRunning(false);
  Countercontrol.setRunning(false);
  Accelerometercontrol.setRunning(false);
  scheduler.setRunning(true);
  t = B01111000;
}


void loop() {
  int count;
  switch_state_t B1_state, B2_state;

  TrafficLightsEqcontrol.process(orientation);
  hbeat = Heartbeatcontrol.process();

  Debouncecontrol.process();
  B1_state = Debouncecontrol.getSwitch1();
  B2_state = Debouncecontrol.getSwitch2();

  Countercontrol.setSwitchstate(B1_state);
  count = Countercontrol.process();

  orientation = Accelerometercontrol.process();

  mode = scheduler.process(B2_state);


  TrafficLightsEqcontrol.setRunning(scheduler.getTrafficLightsEq());
  Heartbeatcontrol.setRunning(scheduler.getHeartbeat());
  Countercontrol.setRunning(scheduler.getCounter());
  Accelerometercontrol.setRunning(scheduler.getAccelerometer());

  switch (mode) {
    case 1:
      writeToShiftRegister(hbeat | t);
      break;
    case 2:
      writeToShiftRegister(hbeat | characters[count % 16]);
      break;
    case 3:
      writeToShiftRegister(hbeat | orientationchars[orientation]);
      break;
    case 4:
      writeToShiftRegister(hbeat | characters[count % 16]);
      break;
    case 5:
      writeToShiftRegister(hbeat | orientationchars[orientation]);
      break;
  }
}








