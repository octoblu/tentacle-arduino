#include <limits.h>
#include "tentacle.hpp"
#include "gtest/gtest.h"

TEST(TentacleTest, Constructor) {
  Tentacle tentacle;
}

TEST(TentacleTest, digitalRead) {
  Tentacle tentacle;
  tentacle.digitalRead(1);
}
