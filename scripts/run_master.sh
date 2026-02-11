#!/usr/bin/env bash
set -e

BUILD_DIR="build"
EXECUTABLE="$BUILD_DIR/master/master"

# Configure if build directory doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
  cmake -S . -B "$BUILD_DIR" -G Ninja
fi

# Build
cmake --build "$BUILD_DIR"

# Run
echo "Running master..."
"$EXECUTABLE" "$@"
