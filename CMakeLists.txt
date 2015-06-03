cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-std=c++98")
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build")
file(DOWNLOAD
 "https://raw.githubusercontent.com/octoblu/cmake-external-project-utils/master/external-project-utils.cmake"
 "${CMAKE_MODULE_PATH}/external-project-utils.cmake"
)

include(external-project-utils)

project (tentacle)

add_library(tentacle STATIC pins.cpp tentacle.cpp)

getExternalProject("gtest" "https://googletest.googlecode.com/files/gtest-1.7.0.zip")
getExternalProject("gmock" "https://googlemock.googlecode.com/files/gmock-1.7.0.zip")
getExternalProject("arduino-mock" "https://github.com/octoblu/arduino-mock/archive/master.zip")

include_directories( tentacle
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

set(TENTACLE_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)

set_target_properties(tentacle PROPERTIES ENABLE_EXPORTS true)

linkExternalProject(tentacle "gtest")
linkExternalProject(tentacle "gmock")
linkExternalProject(tentacle "arduino-mock")

option(test "Build all tests." OFF)

if (test)
  enable_testing()
  add_subdirectory(test)
endif()
