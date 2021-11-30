#!/bin/bash

./cmakeclean.sh

cmake     \
  -DCMAKE_CXX_FLAGS="${CXXFLAGS}"       \
  -DCMAKE_CXX_COMPILER="${CXX}"         \
  -DARCH="${ARCH}"                      \
  -DCMAKE_PREFIX_PATH="${TORCH_CMAKE}"  \
  ..

