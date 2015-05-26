#ifndef pinconfig_h
#define pinconfig_h
class PinConfig {
  public:
    PinConfig(int pin, int mode );
    int getPin();
    int getMode();

  private:
    PinConfig();
    int pin;
    int mode;
};
#endif
