#include "tentacle-arduino.h"
#include "Arduino.h"

TentacleArduino::TentacleArduino() {
  this->setup(NUM_DIGITAL_PINS);
}

void TentacleArduino::setMode(const Pin &pin) const {
  int input_mode = (pin.pullup ? INPUT_PULLUP : INPUT );

  switch(pin.action) {
    case Pin::Action::digitalRead :
    case Pin::Action::analogRead  :
    default:
      ::pinMode(pin.number, input_mode);
    break;

    case Pin::Action::digitalWrite :
    case Pin::Action::servoWrite   :
    case Pin::Action::pwmWrite     :
      ::pinMode(pin.number, OUTPUT);
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
