#!/bin/sh
set -e

mkdir -p build
cd build
cmake .. -DMMM_BUILD_UNIT_TESTS=1 -DUSE_LIBDW=0
make -j4 mmm_tests #VERBOSE=1
ctest -R mmm_tests --output-on-failure
