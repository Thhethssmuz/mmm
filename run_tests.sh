#!/usr/bin/env bash
set -e

BUILD_ARGS=( -DMMM_BUILD_UNIT_TESTS=1 -DUSE_LIBDW=0 )

# if any arguments are given then only build the first test matching all the
# given patterns
if [ $# -gt 0 ]; then

  SRC=$(find test/ -type f -name "*.cpp" | sed 's/test\///')
  while [[ $# -gt 0 ]]; do
    SRC=$(echo "$SRC" | grep "$1") || (echo "no test matched"; exit 1)
    shift
  done

  SRC=$(echo "$SRC" | head -n1)

  BUILD_ARGS+=( -DMMM_BUILD_UNIT_TESTS_SINGLE="$SRC" )
else
  BUILD_ARGS+=( -DMMM_BUILD_UNIT_TESTS_SINGLE=0 )
fi

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
