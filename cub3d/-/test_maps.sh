#!/bin/bash

# Path to your executable program
PROGRAM="./cub3D"

# Function to test a map file
test_map() {
  if "$PROGRAM" "$1" > /dev/null 2>&1; then
    echo "✅ $1"
  else
    # Assuming your program exits with a non-zero status on failure
    echo "❌ $1"
  fi
}

# Directory paths
VALID_MAPS_DIR="./maps/valid_maps"
INVALID_MAPS_DIR="./maps/invalid_maps"

echo "
❌ = invalid map
✅ = valid map"
echo " "
echo "Testing valid maps:"
for FILE in "$VALID_MAPS_DIR"/*; do
  test_map "$FILE"
done

echo "" # New line for separation

echo "Testing invalid maps:"
for FILE in "$INVALID_MAPS_DIR"/*; do
  test_map "$FILE"
done
