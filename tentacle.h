#ifndef tentacle_h
#define tentacle_h

//guess what? the order of these includes really, really matter, because
//the stdlib for Arduino undefines abs(), then defines it's own. So you have
//to include Arduino.h to re-define it. But if, you know, you include it twice in another header,
//it will guard against the double-include, and prevent the abs definition from taking place.
//This will break everything, with no indication of why this is happening. Lovely.

#include <vector>
#include "pins.hpp"
#include "Arduino.h"
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
