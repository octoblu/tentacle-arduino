#ifndef tentacle_pin
#define tentacle_pin
#include "tentacle-pin.hpp"
  TentaclePin::TentaclePin(int pin, int mode ) {
    this->pin = pin; this->mode = mode;
  }

  int TentaclePin::getPin() { return pin; };
  int TentaclePin::getMode() {return mode;}

#endif
