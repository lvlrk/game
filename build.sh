#!/bin/sh

CXX="g++"
CXXFLAGS="-c -g"
LDFLAGS="-lraylib -lfmt -lz"
TARGET="game"

rm -f *.o $TARGET

$CXX $CXXFLAGS src/*.cpp && \
$CXX $LDFLAGS *.o -o $TARGET && \
./$TARGET $@
