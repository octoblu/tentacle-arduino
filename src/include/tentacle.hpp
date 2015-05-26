#ifndef tentacle_h
#define tentacle_h

namespace tentacle {

  class Pin {
    public:
      Pin(int pin, int state=0);
      int getPin();
      int getState();

    private:
      int pin;
      int state;
  };

  class Tentacle {
    public:
      Tentacle();
      void configurePins(std::vector<PinConfig> pins);
      void digitalWrite(int pin, int value);
      void analogWrite(int pin, int value);
      std::vector<Pin> getState();
    private:
      std::vector<PinConfig> pinConfigs;
  };
};
#endif
