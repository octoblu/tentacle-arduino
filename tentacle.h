#ifndef tentacle_h
#define tentacle_h

#include "Arduino.h"
#include "pins.hpp"
#include <vector>

namespace tentacle {

  class Tentacle {
    public:
      // Tentacle();
      void configurePins(std::vector<Pin> pins);
      void configurePin(Pin pin);
      void digitalWrite(int pin, int value);
      void analogWrite(int pin, int value);
      std::vector<Pin> getValue();
  };
};
#endif
