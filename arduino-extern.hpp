#ifndef ARDUINO_H
#define ARDUINO_H

#ifndef INPUT
#define INPUT 1
#endif

#include <stdint.h>

typedef uint8_t byte;

#ifdef __cplusplus
extern "C" {
#endif

extern void pinMode(uint8_t pin, uint8_t mode);
extern void digitalWrite(uint8_t pin, uint8_t mode);
extern void analogWrite(uint8_t pin, uint8_t mode);
extern int digitalRead(uint8_t pin);
extern int  analogRead(uint8_t pin);

#ifdef __cplusplus
}
#endif

// #include "arduino-mock/Arduino.h"

#endif
