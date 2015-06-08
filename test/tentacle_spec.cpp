#include <limits.h>
#include "gtest/gtest.h"
#include "Arduino.h"
#include "Serial.h"

#include "pins.hpp"
#include "tentacle.h"


using namespace tentacle;
using namespace testing;

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

TEST(TentacleTest, getValue_1) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  Tentacle tentacle;

  EXPECT_CALL(*arduinoMock, digitalRead(Lt(NUM_DIGITAL_PINS)))
    .Times(NUM_DIGITAL_PINS)
    .WillOnce(Return(1))
    .WillOnce(Return(0))
    .WillOnce(Return(0))
    .WillOnce(Return(0))
    .WillOnce(Return(1))
    .WillOnce(Return(0))
    .WillOnce(Return(0))
    .WillOnce(Return(1))
    .WillRepeatedly(Return(0));

  auto pinStates = tentacle.getValue();
  EXPECT_EQ(pinStates[0].getValue(), 1);
  EXPECT_EQ(pinStates[1].getValue(), 0);
  EXPECT_EQ(pinStates[2].getValue(), 0);
  EXPECT_EQ(pinStates[3].getValue(), 0);
  EXPECT_EQ(pinStates[4].getValue(), 1);
  EXPECT_EQ(pinStates[5].getValue(), 0);
  EXPECT_EQ(pinStates[6].getValue(), 0);
  EXPECT_EQ(pinStates[7].getValue(), 1);

  releaseArduinoMock();
}
