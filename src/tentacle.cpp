#include "tentacle.hpp"

Tentacle::Tentacle () {
}

int Tentacle::digitalRead(int pin){
  return ::digitalRead(pin);
}

int Tentacle::analogRead(int pin){
  return ::analogRead(pin);
}
