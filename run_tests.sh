#!/bin/sh
set -e

mkdir -p build
cd build
cmake .. -DUSE_LIBDW=0
make -j4 mmm_tests #VERBOSE=1
ctest -R mmm_tests -V
