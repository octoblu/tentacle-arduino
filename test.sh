#!/bin/sh
cd build
make
ctest -VV
