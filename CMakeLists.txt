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

# set_target_properties(tentacle PROPERTIES ENABLE_EXPORTS true)

target_link_libraries( tentacle
    ${CMAKE_THREAD_LIBS_INIT}
)

linkExternalProject("gtest")
linkExternalProject("gmock")
linkExternalProject("arduino-mock")

if (test)
  enable_testing()
  add_subdirectory(test)
endif()



# cmake_minimum_required(VERSION 2.8)
# set(CMAKE_CXX_FLAGS "-std=c++98")
# set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/build")
#
# include(external-project-utils)
#
# project (arduino-mock)
#
# add_library(arduino-mock STATIC "src/ArduinoMockAll.cc")
#
# getExternalProject("gtest" "https://googletest.googlecode.com/files/gtest-1.7.0.zip")
# getExternalProject("gmock" "https://googlemock.googlecode.com/files/gmock-1.7.0.zip")
#
# include_directories(arduino-mock include)
# #library setup
#
# target_include_directories(arduino-mock
#     PUBLIC "include"
# )
#
# target_link_libraries( arduino-mock
#     ${CMAKE_THREAD_LIBS_INIT}
# )
#
# linkExternalProject("gtest")
# linkExternalProject("gmock")
#
# set_target_properties( arduino-mock
#   PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
#     LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin"
# )
#
# option(test "Build all tests." OFF)
#
# if (test)
#   enable_testing()
#   add_subdirectory(test)
# endif()
