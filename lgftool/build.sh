#!/bin/sh

CXX="g++"
CXXFLAGS="-g"
LDFLAGS="-lz"
TARGET="lgftool"

rm -f *.o $TARGET

$CXX $CXXFLAGS $LDFLAGS src/*.cpp -o $TARGET && \
./$TARGET $@
