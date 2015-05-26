#include <limits.h>
#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"
#include "arduino-mock/Serial.h"

#define TOTAL_PINS 8
#include "../../src/pins.cpp"
#include "../../src/tentacle.cpp"


using ::testing::Return;
using namespace tentacle;

TEST(TentacleTest, Constructor) {
  Tentacle tentacle;
}

TEST(TentacleTest, digitalWrite_1) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, digitalWrite(1, 0));
  Tentacle tentacle;
  tentacle.digitalWrite(1, 0);
  releaseArduinoMock();
}

TEST(TentacleTest, digitalWrite_2) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, digitalWrite(2, 1));

  Tentacle tentacle;
  tentacle.digitalWrite(2, 1);
  releaseArduinoMock();
}

TEST(TentacleTest, analogWrite_1) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  Tentacle tentacle;

  EXPECT_CALL(*arduinoMock, analogWrite(3, 4));
  tentacle.analogWrite(3, 4);

  releaseArduinoMock();
}

TEST(TentacleTest, analogWrite_2) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, analogWrite(5, 100));

  Tentacle tentacle;
  tentacle.analogWrite(5, 100);
  releaseArduinoMock();
}

TEST(TentacleTest, config_1) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, pinMode(1, OUTPUT));
  EXPECT_CALL(*arduinoMock, pinMode(2, INPUT)).Times(2);

  //Yes, this is dumb. I can't figure out how to tell gtest to ignore extra calls.
  EXPECT_CALL(*arduinoMock, pinMode(0, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(1, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(3, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(4, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(5, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(6, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(7, INPUT));
  Tentacle tentacle;

  auto PinConfigs = std::vector<PinConfig>({
    PinConfig(2, INPUT),
    PinConfig(1, OUTPUT)
  });

  tentacle.configurePins(PinConfigs);
  releaseArduinoMock();
}

TEST(TentacleTest, config_2) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, pinMode(5, OUTPUT));

  //Yes, this is dumb. I can't figure out how to tell gtest to ignore extra calls.
  EXPECT_CALL(*arduinoMock, pinMode(0, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(1, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(2, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(3, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(4, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(5, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(6, INPUT));
  EXPECT_CALL(*arduinoMock, pinMode(7, INPUT));
  Tentacle tentacle;

  auto PinConfigs = std::vector<PinConfig>({
    PinConfig(5, OUTPUT)
  });

  tentacle.configurePins(PinConfigs);
  releaseArduinoMock();
}

TEST(TentacleTest, getState_1) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  Tentacle tentacle;

  auto PinConfigs = std::vector<PinConfig>({
    PinConfig(13, OUTPUT)
  });

  tentacle.configurePins(PinConfigs);
  auto pinStates = tentacle.getState();

  for(PinState pinState : pinStates) {
    EXPECT_EQ(pinState.getState(), LOW);
  }

  releaseArduinoMock();
}
