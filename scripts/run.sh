#!/usr/bin/env bash
set -e

BUILD_DIR="build"
EXECUTABLE="$BUILD_DIR/src/mapreduce_app"

# Configure if build directory doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
  cmake -S . -B "$BUILD_DIR" -G Ninja
fi

# Build
cmake --build "$BUILD_DIR"

# Run
echo "Running mapreduce_app..."
"$EXECUTABLE" "$@"
