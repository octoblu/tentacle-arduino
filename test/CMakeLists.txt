# We need thread support
find_package(Threads REQUIRED)
add_subdirectory(lib/gtest)
add_subdirectory(lib/gmock)
add_subdirectory(lib/arduino_mock)

add_subdirectory(tentacle)
