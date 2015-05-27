#include "tentacle.hpp"

namespace tentacle {

void Tentacle::configurePins(std::vector<Pin> pins) {
    for(Pin pin : pins) {
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
    std::vector<Pin> pins = std::vector<Pin>();

    for(byte i = 0; i < TOTAL_PINS; i++) {
      byte pinState = digitalRead(i);
      pins.push_back( Pin(i, 0, pinState));
    }

    return pins;
  }
}
