#include "pins.hpp"
namespace tentacle {

  Pin::Pin(byte pin, byte mode, byte state) {
    this->pin = pin;
    this->mode = mode;
    this->state = state;
  }

  byte Pin::getPin() {
    return pin;
  }

  byte Pin::getMode(){
    return mode;
  }

  byte Pin::getState() {
    return state;
  }

}
