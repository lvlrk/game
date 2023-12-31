#!/bin/sh

CXX="g++"
CXXFLAGS="-g"
LDFLAGS="-lraylib -lfmt -lz"
TARGET="game"

rm -f *.o $TARGET

$CXX $CXXFLAGS $LDFLAGS src/*.cpp -o $TARGET && \
./$TARGET $@
