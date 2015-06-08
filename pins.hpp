#ifndef pin_h
#define pin_h

#ifndef INPUT
#define INPUT 0
#endif

#define STATE_UNDEFINED 254

typedef unsigned char byte;
namespace tentacle {
  //Todo: Pins should have an enum for mode and state, so we're not dependent on Arduino
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
