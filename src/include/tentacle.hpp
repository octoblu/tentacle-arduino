#ifndef tentacle_h
#define tentacle_h

class Tentacle {
  public:
    Tentacle();
    void begin();
    int digitalRead(int pin);
    void digitalWrite(int pin, int value);
    int analogRead(int pin);
    void tick();
};

#endif
