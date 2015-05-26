#include "pin-config.hpp"

PinConfig::PinConfig(int pin, int mode ) {
  this->pin = pin; this->mode = mode;
}

int PinConfig::getPin() {
  return pin;
}

int PinConfig::getMode() {
  return mode;
}
