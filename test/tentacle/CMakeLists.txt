message ("building tests for the TERRIFYING TENTACLE")
include_directories(${GTEST_INCLUDE_DIRS})
file(GLOB SRCS *.cpp *.hpp)
add_executable(tentacleSpec ${SRCS})
target_link_libraries(tentacleSpec
    tentacle
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
    ${CMAKE_THREAD_LIBS_INIT}
)
add_dependencies(tentacleSpec gtest)
add_test(tentacle_spec tentacleSpec)
