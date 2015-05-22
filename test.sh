#!/bin/sh
cd build
rm -rf *
cmake -Dtest=ON ..
make
make test
