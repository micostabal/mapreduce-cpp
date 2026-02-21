#!/usr/bin/env bash
set -euo pipefail

BUILD_DIR="build"

# Configure
if [ ! -d "$BUILD_DIR" ]; then
  echo "Configuring project..."
  cmake -S . -B "$BUILD_DIR" -G Ninja
fi

# Build tests
echo "Building tests..."
cmake --build "$BUILD_DIR"

# Run tests
echo "Running tests..."
cd "$BUILD_DIR"
ctest --output-on-failure