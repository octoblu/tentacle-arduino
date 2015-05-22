#ifndef tentacle_h
#define tentacle_h

class Tentacle {
  public:
    Tentacle(int pollInterval=POLL_INTERVAL_DEFAULT);
    void begin();
    int digitalRead(int pin);
    void digitalWrite(int pin, int value);
    int analogRead(int pin);
    void configurePins(std::vector<TentaclePin> pins);
    void tick();
    static const int POLL_INTERVAL_DEFAULT = 200;
  private:
    std::vector<TentaclePin> pins;
    int pollInterval;
};

#endif
