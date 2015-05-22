class TentaclePin {
  public:
    TentaclePin(int pin, int mode );
    int getPin();
    int getMode();

  private:
    TentaclePin();
    int pin;
    int mode;
};
