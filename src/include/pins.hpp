#ifndef pinconfig_h
  #define pinconfig_h

  #ifndef TOTAL_PINS
    #define TOTAL_PINS 22
  #endif

namespace tentacle {

  class Pin {
    public:
      Pin(int pin, int state=LOW);
      int getPin();
      int getState();

    private:
      int pin;
      int state;
  };

  class PinConfig {
    public:
      PinConfig(int pin, int mode=INPUT );
      int getPin();
      int getMode();

    private:
      PinConfig();
      int pin;
      int mode;
  };
}

#endif
