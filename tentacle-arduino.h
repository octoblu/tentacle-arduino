#include "tentacle.h"

#ifndef tentacle_arduino_h
#define tentacle_arduino_h

class TentacleArduino : public Tentacle {
  public:
    TentacleArduino();

    const MeshbluCredentials& getCredentials();
    Tentacle& setCredentials(const char* uuid, const char* token);

    Tentacle& setMode(int number, Action action);
    Tentacle& digitalWrite(int number, int value);
    Tentacle& analogWrite(int number, int value);
    bool digitalRead(int number);
    int analogRead(int number);
};

#endif
