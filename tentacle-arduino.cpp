#include "tentacle-arduino.h"
#include "Arduino.h"

int TentacleArduino::getNumberOfPins() {
  return NUM_DIGITAL_PINS;
}

void TentacleArduino::setMode(Pin pin){
  int input_mode = (pin.getPullup() ? INPUT_PULLUP : INPUT );

  switch(pin.getAction()) {
    case Pin::digitalRead :
    case Pin::analogRead  :
    default:
      pinMode(pin.getNumber(), input_mode);
    break;

    case Pin::digitalWrite :
    case Pin::servoWrite   :
    case Pin::pwmWrite     :
      pinMode(pin.getNumber(), OUTPUT);
    break;
  }
}

void TentacleArduino::digitalWrite(int pin, int value){
  ::digitalWrite(pin, value);
}

void TentacleArduino::analogWrite(int pin, int value){
  ::analogWrite(pin, value);
}

bool TentacleArduino::digitalRead(int pin){
  return ::digitalRead(pin);
}

int TentacleArduino::analogRead(int pin){
  return ::analogRead(pin);
}