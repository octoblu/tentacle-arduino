#ifndef tentacle_h
#define tentacle_h

class Tentacle {
  public:
    Tentacle();
    void begin();
    int digitalRead(int pin);
    void digitalWrite(int pin, int value);
    int analogRead(int pin);
    void configurePins(std::vector<TentaclePin> pins);
    void tick();
  private:
    std::vector<TentaclePin> pins;
};

#endif
