cmake_minimum_required (VERSION 2.8)
message ("building the TERRIFYING TENTACLE")
include_directories("/include")
add_library(tentacle sample1.cc)
set_target_properties( tentacle
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin"
)
