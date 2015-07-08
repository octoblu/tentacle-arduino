#include "tentacle-arduino.h"
// Make library cross-compatiable
// with Arduino, GNU C++ for tests, and Spark.
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#elif defined(SPARK)
#include "application.h"
#define NUM_DIGITAL_PINS 18
#endif

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

  switch(action) {
    case Action_digitalRead :
    case Action_analogRead  :
    default:
      pinMode(number, INPUT);
    break;

    case Action_digitalReadPullup:
    case Action_analogReadPullup:
      pinMode(number, INPUT_PULLUP);

    case Action_digitalWrite :
    case Action_servoWrite   :
    case Action_pwmWrite     :
      pinMode(number, OUTPUT);
    break;
  }

  return *this;
}

Tentacle& TentacleArduino::digitalWrite(int number, int value){
  ::digitalWrite(number, value);

  return *this;
}

Tentacle& TentacleArduino::analogWrite(int number, int value){
  ::analogWrite(number, value);

  return *this;
}

bool TentacleArduino::digitalRead(int number){
  return ::digitalRead(number);

}

int TentacleArduino::analogRead(int number){
  return ::analogRead(number);
}
