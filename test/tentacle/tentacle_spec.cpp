#include <limits.h>
#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"
#include "arduino-mock/Serial.h"

#include "pins.hpp"
#include "tentacle.hpp"


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
  Tentacle tentacle;

  EXPECT_CALL(*arduinoMock, pinMode(1, OUTPUT));
  EXPECT_CALL(*arduinoMock, pinMode(2, INPUT));

  auto pins = std::vector<Pin>({
    Pin(2, INPUT),
    Pin(1, OUTPUT)
  });

  tentacle.configurePins(pins);
  releaseArduinoMock();
}

TEST(TentacleTest, config_2) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, pinMode(5, OUTPUT));

  Tentacle tentacle;

  auto pins = std::vector<Pin>({
    Pin(5, OUTPUT)
  });

  tentacle.configurePins(pins);
  releaseArduinoMock();
}

TEST(TentacleTest, getState_1) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  Tentacle tentacle;

  EXPECT_CALL(*arduinoMock, digitalRead(0)).WillOnce(Return(1));
  EXPECT_CALL(*arduinoMock, digitalRead(1)).WillOnce(Return(0));
  EXPECT_CALL(*arduinoMock, digitalRead(2)).WillOnce(Return(0));
  EXPECT_CALL(*arduinoMock, digitalRead(3)).WillOnce(Return(0));
  EXPECT_CALL(*arduinoMock, digitalRead(4)).WillOnce(Return(1));
  EXPECT_CALL(*arduinoMock, digitalRead(5)).WillOnce(Return(0));
  EXPECT_CALL(*arduinoMock, digitalRead(6)).WillOnce(Return(0));
  EXPECT_CALL(*arduinoMock, digitalRead(7)).WillOnce(Return(1));

  auto pinStates = tentacle.getState();
  EXPECT_EQ(pinStates[0].getState(), 1);
  EXPECT_EQ(pinStates[1].getState(), 0);
  EXPECT_EQ(pinStates[2].getState(), 0);
  EXPECT_EQ(pinStates[3].getState(), 0);
  EXPECT_EQ(pinStates[4].getState(), 1);
  EXPECT_EQ(pinStates[5].getState(), 0);
  EXPECT_EQ(pinStates[6].getState(), 0);
  EXPECT_EQ(pinStates[7].getState(), 1);

  releaseArduinoMock();
}
