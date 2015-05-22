cmake_minimum_required (VERSION 2.8)

project (TheTentacle)

include_directories("${TheTentacle_SOURCE_DIR}/src")
add_library(TheTentacle src/sample1.cc)

install (TARGETS TheTentacle DESTINATION bin)
