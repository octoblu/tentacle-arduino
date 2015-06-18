#include "tentacle.h"

#ifndef tentacle_arduino_h
#define tentacle_arduino_h

#include "pins.hpp"

class TentacleArduino : public Tentacle {
  public:
    TentacleArduino();
    void setMode(const Pin &pin) const;
    void digitalWrite(const int pin, const int value);
    void analogWrite(const int pin, const int value);
    bool digitalRead(const int pin);
    int analogRead(const int pin);
};

#endif
