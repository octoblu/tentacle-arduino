#include "tentacle-arduino.h"
#include "Arduino.h"

TentacleArduino::TentacleArduino() {
  numPins = NUM_DIGITAL_PINS;
  pins = new Pin[numPins];
}

const MeshbluCredentials& TentacleArduino::getCredentials() {
  const MeshbluCredentials credentials(NULL, NULL);
  return credentials;
}

Tentacle& TentacleArduino::setCredentials(const char* uuid, const char* token) {
  return *this;
}

Tentacle& TentacleArduino::setMode(Pin pin){
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

  return *this;
}

Tentacle& TentacleArduino::digitalWrite(int pin, int value){
  ::digitalWrite(pin, value);

  return *this;
}

Tentacle& TentacleArduino::analogWrite(int pin, int value){
  ::analogWrite(pin, value);

  return *this;
}

bool TentacleArduino::digitalRead(int pin){
  return ::digitalRead(pin);

}

int TentacleArduino::analogRead(int pin){
  return ::analogRead(pin);
}
