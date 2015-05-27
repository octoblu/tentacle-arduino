#ifndef pin_h
  #define pin_h
  #define STATE_UNDEFINED 254
  #ifndef TOTAL_PINS
    #define TOTAL_PINS 22
  #endif

namespace tentacle {
  typedef unsigned char byte;

  class Pin {
    public:
      Pin(byte pin, byte mode=INPUT, byte state=STATE_UNDEFINED);
      byte getPin();
      byte getMode();
      byte getState();
      void setState( byte state );

    private:
      byte pin;
      byte state;
      byte mode;
  };
}

#endif
