#include "tentacle-arduino.h"
#include "Arduino.h"

TentacleArduino::TentacleArduino() {
  this->setup(NUM_DIGITAL_PINS);
}

void TentacleArduino::setMode(const Pin &pin) const {
  int input_mode = (pin.getPullup() ? INPUT_PULLUP : INPUT );

  switch(pin.getAction()) {
    case Pin::digitalRead :
    case Pin::analogRead  :
    default:
      ::pinMode(pin.getNumber(), input_mode);
    break;

    case Pin::digitalWrite :
    case Pin::servoWrite   :
    case Pin::pwmWrite     :
      ::pinMode(pin.getNumber(), OUTPUT);
    break;
  }
}

void TentacleArduino::digitalWrite(const int pin, const int value){
  ::digitalWrite(pin, value);
}

void TentacleArduino::analogWrite(const int pin, const int value){
  ::analogWrite(pin, value);
}

bool TentacleArduino::digitalRead(const int pin){
  return ::digitalRead(pin);
}

int TentacleArduino::analogRead(const int pin){
  return ::analogRead(pin);
}
