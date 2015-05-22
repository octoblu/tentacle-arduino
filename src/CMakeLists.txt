message ("building the TERRIFYING TENTACLE")
file(GLOB SRC
    "*.hpp"
    "*.cpp"
)
include_directories(include)
add_library(tentacle STATIC ${SRC})
target_include_directories(tentacle
    PUBLIC "include"
)
set_target_properties( tentacle
  PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/dist/bin"
)
