#!/bin/bash
set -e  
BUILD_DIR="build"
CORES=$(nproc)  
mkdir -p $BUILD_DIR
cd $BUILD_DIR
cmake -G Ninja ..
ninja -j$CORES
