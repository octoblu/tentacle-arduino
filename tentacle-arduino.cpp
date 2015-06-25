#include "tentacle-arduino.h"
#include "Arduino.h"

TentacleArduino::TentacleArduino() : Tentacle(NUM_DIGITAL_PINS) {
}

const MeshbluCredentials& TentacleArduino::getCredentials() {
  const MeshbluCredentials credentials(NULL, NULL);
  return credentials;
}

Tentacle& TentacleArduino::setCredentials(const char* uuid, const char* token) {
  return *this;
}

Tentacle& TentacleArduino::setMode(int number, Action action){
  int input_mode = (pin.getPullup() ? INPUT_PULLUP : INPUT );

  switch(action) {
    case Pin::digitalRead :
    case Pin::analogRead  :
    default:
      pinMode(number, input_mode);
    break;

    case Pin::digitalWrite :
    case Pin::servoWrite   :
    case Pin::pwmWrite     :
      pinMode(number), OUTPUT);
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
