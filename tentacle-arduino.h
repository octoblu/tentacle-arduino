#include "tentacle.h"

#ifndef tentacle_arduino_h
#define tentacle_arduino_h

class TentacleArduino : public Tentacle {
  public:
    TentacleArduino();

    const MeshbluCredentials& getCredentials();
    Tentacle& setCredentials(const char* uuid, const char* token);

    Tentacle& setMode(int pin, Action action);
    Tentacle& digitalWrite(int pin, int value);
    Tentacle& analogWrite(int pin, int value);
    bool digitalRead(int pin);
    int analogRead(int pin);
};

#endif
