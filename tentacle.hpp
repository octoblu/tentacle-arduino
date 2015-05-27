#ifndef tentacle_h
#define tentacle_h

#ifndef INPUT
#define INPUT 1
#endif

#include "pins.hpp"
#include <vector>
typedef unsigned char uint8_t;

extern void pinMode(uint8_t pin, uint8_t mode);
extern void digitalWrite(uint8_t pin, uint8_t mode);
extern void analogWrite(uint8_t pin, uint8_t mode);
extern int digitalRead(uint8_t pin);
extern int  analogRead(uint8_t pin);

namespace tentacle {

  class Tentacle {
    public:
      // Tentacle();
      void configurePins(std::vector<Pin> pins);
      void configurePin(Pin pin);
      void digitalWrite(int pin, int value);
      void analogWrite(int pin, int value);
      std::vector<Pin> getState();
  };
};
#endif
