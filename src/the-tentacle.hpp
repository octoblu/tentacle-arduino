#ifndef The_Tentacle_h
#define The_Tentacle_h

class TheTentacle {
  public:
    TheTentacle();
    void begin();
    int digitalRead(int pin);
    void digitalWrite(int pin, int value);
    void tick();
};

#endif
