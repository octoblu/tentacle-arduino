#cmake_minimum_required (VERSION 3.2)
project (tentacle)
set(CMAKE_CXX_FLAGS "-std=c++11")
add_subdirectory(test)
get_property(ARDUINO_MOCK_INCLUDE_DIRS GLOBAL PROPERTY ARDUINO_MOCK_INCLUDE_DIRS)
get_property(GMOCK_INCLUDE_DIRS GLOBAL PROPERTY GMOCK_INCLUDE_DIRS)
get_property(GTEST_INCLUDE_DIRS GLOBAL PROPERTY GTEST_INCLUDE_DIRS)
include_directories(.
  ${ARDUINO_MOCK_INCLUDE_DIRS}
  ${GMOCK_INCLUDE_DIRS}
  ${GTEST_INCLUDE_DIRS})
add_library(tentacle tentacle.cpp pins.cpp)
enable_testing()
