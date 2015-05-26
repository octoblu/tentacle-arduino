#include "tentacle.hpp"

namespace tentacle {

void Tentacle::configurePins(std::vector<Pin> pins) {
    for(auto pin : pins) {
      configurePin(pin);
    }
  }

  void Tentacle::configurePin(Pin pin) {
    pinMode(pin.getPin(), pin.getMode());
    if(pin.getState() != STATE_UNDEFINED) {
      digitalWrite(pin.getPin(), pin.getState());
    }
  }

  void Tentacle::digitalWrite(int pin, int value){
    ::digitalWrite(pin, value);
  }

  void Tentacle::analogWrite(int pin, int value){
    ::analogWrite(pin, value);
  }

  std::vector<Pin> Tentacle::getState() {
    return std::vector<Pin>();
  }
}
