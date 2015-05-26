#ifndef tentacle_h
#define tentacle_h
#include "pins.hpp"

namespace tentacle {

  class Tentacle {
    public:
      Tentacle();
      void configurePins(std::vector<PinConfig> pins);
      void digitalWrite(int pin, int value);
      void analogWrite(int pin, int value);
      std::vector<Pin> getState();
    private:
      std::vector<PinConfig> pinConfigs;
  };
};
#endif
