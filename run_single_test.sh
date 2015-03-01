#!/bin/sh
set -e

mkdir -p build
cd build
cmake .. -DUSE_LIBDW=0
make -j4 $1 #VERBOSE=1
ctest -R $1 -V
