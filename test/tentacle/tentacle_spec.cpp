#include <limits.h>
#include "gtest/gtest.h"
#include "arduino-mock/Arduino.h"
#include "arduino-mock/Serial.h"

#include "../../src/tentacle.cpp"

using ::testing::Return;
TEST(TentacleTest, Constructor) {
  Tentacle tentacle;
}

TEST(TentacleTest, digitalRead) {
  ArduinoMock* arduinoMock = arduinoMockInstance();
  EXPECT_CALL(*arduinoMock, digitalRead(1));
  Tentacle tentacle;
  tentacle.digitalRead(1);
  releaseArduinoMock();
}

// //example arduino test
// TEST(TentacleTest, ArduinoMock) {
//   ArduinoMock* arduinoMock = arduinoMockInstance();
//   SerialMock* serialMock = serialMockInstance();
//   EXPECT_CALL(*arduinoMock, digitalRead(2))
//     .WillOnce(Return(1));
//   EXPECT_CALL(*serialMock, println(1, 10));
//   EXPECT_CALL(*arduinoMock, delay(1));
//   // loop();
//   releaseSerialMock();
//   releaseArduinoMock();
// }
