class MockPinChangeListener : public PinChangeListener {
 public:
  MOCK_METHOD1(pinChange, void(int value));
};
