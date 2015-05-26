#include "pins.hpp"
namespace tentacle {
  
  Pin::Pin(int pin, int state) {
    this->pin = pin; this->state = state;
  }

  int Pin::getPin() {
    return pin;
  };

  int Pin::getState(){
    return state;
  };


  PinConfig::PinConfig(int pin, int mode ) {
    this->pin = pin; this->mode = mode;
  }

  int PinConfig::getPin() {
    return pin;
  }

  int PinConfig::getMode() {
    return mode;
  }
}
