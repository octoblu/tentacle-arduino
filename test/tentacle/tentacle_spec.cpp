#include <limits.h>
#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"
#include "arduino-mock/Serial.h"

#include "../../src/tentacle-pin.cpp"
#include "../../src/tentacle.cpp"


using ::testing::Return;
TEST(TentacleTest, Constructor) {
  Tentacle tentacle;
}

TEST(TentacleTest, digitalRead_1) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, digitalRead(1))
    .WillOnce(Return(LOW));
  Tentacle tentacle;
  int pinValue = tentacle.digitalRead(1);
  EXPECT_EQ(LOW, pinValue);
  releaseArduinoMock();
}


TEST(TentacleTest, digitalRead_2) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, digitalRead(2))
    .WillOnce(Return(HIGH));
  Tentacle tentacle;
  int pinValue = tentacle.digitalRead(2);
  EXPECT_EQ(HIGH, pinValue);
  releaseArduinoMock();
}

TEST(TentacleTest, analogRead_1) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, analogRead(1))
    .WillOnce(Return(314));
  Tentacle tentacle;
  float pinValue = tentacle.analogRead(1);
  EXPECT_EQ(314, pinValue);
  releaseArduinoMock();
}


TEST(TentacleTest, analogRead_2) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, analogRead(2))
    .WillOnce(Return(5));
  Tentacle tentacle;
  int pinValue = tentacle.analogRead(2);
  EXPECT_EQ(5, pinValue);
  releaseArduinoMock();
}

TEST(TentacleTest, config_1) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, pinMode(1, OUTPUT));
  EXPECT_CALL(*arduinoMock, pinMode(2, INPUT));
  Tentacle tentacle;

  auto tentaclePins = std::vector<TentaclePin>({
    TentaclePin(2, INPUT),
    TentaclePin(1, OUTPUT)
  });

  tentacle.configurePins(tentaclePins);
  releaseArduinoMock();
}
