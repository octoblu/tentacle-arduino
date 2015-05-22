#include "tentacle.hpp"

Tentacle::Tentacle (int pollInterval) {
  this->pins = std::vector<TentaclePin>();
  this->pollInterval = pollInterval;
}

int Tentacle::digitalRead(int pin){
  return ::digitalRead(pin);
}

int Tentacle::analogRead(int pin){
  return ::analogRead(pin);
}

void Tentacle::configurePins(std::vector<TentaclePin> pins) {
  for(auto pin : pins){
    pinMode(pin.getPin(), pin.getMode());
  }
  this->pins = pins;
}
