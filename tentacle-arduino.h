#include "tentacle.h"

#ifndef tentacle_arduino_h
#define tentacle_arduino_h

#include "pins.hpp"

class TentacleArduino : public Tentacle {
  public:
    TentacleArduino();
    void setMode(Pin pin);
    void digitalWrite(int pin, int value);
    void analogWrite(int pin, int value);
    bool digitalRead(int pin);
    int analogRead(int pin);
};

#endif
