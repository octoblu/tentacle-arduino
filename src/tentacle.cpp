#include "tentacle.hpp"
#include "pin-config.hpp"

namespace tentacle {
  Tentacle::Tentacle () {
    this->pinConfigs = std::vector<PinConfig>();
  }

  void Tentacle::configurePins(std::vector<PinConfig> pins) {
    for(auto pin : pins) {
      pinMode(pin.getPin(), pin.getMode());
    }

    this->pinConfigs = pins;
  }

  void Tentacle::digitalWrite(int pin, int value){
    ::digitalWrite(pin, value);
  }

  void Tentacle::analogWrite(int pin, int value){
    ::analogWrite(pin, value);
  }

  std::vector<Pin> Tentacle::getState() {
    digitalRead(1);
  }
}
