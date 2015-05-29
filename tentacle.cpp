#include "tentacle.h"

namespace tentacle {

void Tentacle::configurePins(std::vector<Pin> pins) {
    for(int i = 0; i < pins.size(); i++) {
      Pin pin = pins[i];
      configurePin(pin);
    }
  }

  void Tentacle::configurePin(Pin pin) {
    pinMode(pin.getNumber(), pin.getMode());
    if(pin.getValue() != STATE_UNDEFINED) {
      digitalWrite(pin.getNumber(), pin.getValue());
    }
  }

  void Tentacle::digitalWrite(int pin, int value){
    ::digitalWrite(pin, value);
  }

  void Tentacle::analogWrite(int pin, int value){
    ::analogWrite(pin, value);
  }

  std::vector<Pin> Tentacle::getValue() {
    std::vector<Pin> pins = std::vector<Pin>();

    for(byte i = 0; i < TOTAL_PINS; i++) {
      byte pinState = digitalRead(i);
      pins.push_back( Pin(i, 0, pinState));
    }

    return pins;
  }
}
