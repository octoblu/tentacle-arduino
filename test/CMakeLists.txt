cmake_minimum_required (VERSION 2.8)
message ("building tests for the TERRIFYING TENTACLE")
# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(
  ${gtest_SOURCE_DIR}/include
  ${gtest_SOURCE_DIR}
  ${tentacle_SOURCE_DIR}/src
  ${tentacle_SOURCE_DIR}/include
)

##############
# Unit Tests
##############
add_executable(runUnitTests tentacle_unittest.cpp)

# Standard linking to gtest stuff.
target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests tentacle)

# Extra linking for the project.
# target_link_libraries(runUnitTests project1_lib)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(tentacle_unittest runUnitTests)
