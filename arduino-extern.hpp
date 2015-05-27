#ifndef arduino_extern_h
#define arduino_extern_h

#ifndef INPUT
#define INPUT 1
#endif

typedef unsigned char uint8_t;

extern void pinMode(uint8_t pin, uint8_t mode);
extern void digitalWrite(uint8_t pin, uint8_t mode);
extern void analogWrite(uint8_t pin, uint8_t mode);
extern int digitalRead(uint8_t pin);
extern int  analogRead(uint8_t pin);

#endif
