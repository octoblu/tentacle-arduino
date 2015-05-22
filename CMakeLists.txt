cmake_minimum_required (VERSION 2.8)

project (TheTentacle)

option(test "Build all tests." OFF)

include_directories("${TheTentacle_SOURCE_DIR}/src", "${TheTentacle_SOURCE_DIR}/test")

add_library(tentacle src/sample1.cc)

################################
# Testing
################################
if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(lib/gtest)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  ##############
  # Unit Tests
  ##############
  add_executable(runUnitTests test/sample1_unittest.cc)

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)
  target_link_libraries(runUnitTests tentacle)

  # Extra linking for the project.
  # target_link_libraries(runUnitTests project1_lib)

  # This is so you can do 'make test' to see all your tests run, instead of
  # manually running the executable runUnitTests to see those specific tests.
  add_test(NAME sample1_unittest COMMAND runUnitTests)

  # You can also omit NAME and COMMAND. The second argument could be some other
  # test executable.
  add_test(that-other-test-I-made runUnitTests)
endif()
