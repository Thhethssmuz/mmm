#!/usr/bin/env bash
set -e

BUILD_ARGS=( -DMMM_BUILD_UNIT_TESTS=1 -DUSE_LIBDW=0 )

# create build directory
mkdir -p build
cd build

# prefer ninja over make if available
if hash ninja 2>/dev/null; then
  cmake -GNinja .. "${BUILD_ARGS[@]}"
  ninja
else
  cmake .. "${BUILD_ARGS[@]}"
  make -j4 mmm_tests #VERBOSE=1
fi

ctest -R mmm_tests --verbose # --output-on-failure
