cmake_minimum_required (VERSION 2.8)
project (tentacle)
option(test "Build all tests." OFF)
add_subdirectory(src)

if (test)
  enable_testing()
  add_subdirectory(test)
endif()
