#!/bin/sh
set -e

mkdir -p build
cd build
cmake .. -DUSE_LIBDW=0
make -j4 #VERBOSE=1
ctest -V
