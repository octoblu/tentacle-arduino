set(CMAKE_CXX_FLAGS "-std=c++11")
message ("building tests for the TERRIFYING TENTACLE")

file(GLOB SRCS *.cpp)

add_executable(tentacle-test ${SRCS})

linkExternalProject(tentacle-test "gtest")
linkExternalProject(tentacle-test "gmock")
linkExternalProject(tentacle-test "arduino-mock")

target_link_libraries(tentacle-test
    tentacle
    ${GTEST_LIB_DIR}/libgtest_main.a
)

add_test(tentacle tentacle-test)
