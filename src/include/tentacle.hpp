#ifndef tentacle_h
#define tentacle_h

class PinChangeListener {
  public:
    virtual void pinChange(int value);
};

class Tentacle {
  public:
    Tentacle();
    void tick();
    int digitalRead(int pin);
    void digitalWrite(int pin, int value);
    int analogRead(int pin);
    void configurePins(std::vector<TentaclePin> pins);
    void subscribeToPin(int pin, PinChangeListener);
  private:
    std::vector<TentaclePin> pins;
    int pollInterval;
};

#endif
