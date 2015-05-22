#!/bin/sh
cd build
cmake ..
make
ctest -VV
