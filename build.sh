#!/bin/sh
cd build && \
cmake .. && \
make VERBOSE=1 && \
ctest -VV
