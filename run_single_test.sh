#!/bin/sh
set -e

name=$(echo "$1" | sed "s/test\///" | sed "s/\//_/g" | sed "s/.cpp//")
name="mmm_${name}_test"
mkdir -p build
cd build
cmake .. -DUSE_LIBDW=0
make -j4 $name #VERBOSE=1
ctest -R $name --output-on-failure
