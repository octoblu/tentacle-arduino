#ifndef pin_h
#define pin_h
typedef unsigned char byte;

#define INPUT 0
#define STATE_UNDEFINED 254
#ifndef TOTAL_PINS
#define TOTAL_PINS 22
#endif

namespace tentacle {

  class Pin {
    public:
      Pin(byte pin, byte mode=INPUT, byte state=STATE_UNDEFINED);
      byte getNumber();
      byte getMode();
      byte getValue();
      void setState( byte state );

    private:
      byte pin;
      byte state;
      byte mode;
  };
}

#endif
