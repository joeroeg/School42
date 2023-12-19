#!/bin/bash

# Compile the C program along with the test program
gcc -o test_flood_fill flood_fill.c test.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Run the test
output=$(./test_flood_fill)

# Define the expected output
expected_output="11111111
10001001
10010001
10110001
11100001
FFFFFFFF
F000F00F
F00F000F
F0FF000F
FFF0000F"

# Initialize a flag to indicate a successful test
success=true

# Compare each line
while IFS= read -r line; do
    expected_lines+=("$line")
done <<< "$expected_output"

IFS=$'\n' read -rd '' -a output_lines <<< "$output"

for i in "${!expected_lines[@]}"; do
    if [ "${output_lines[i]}" != "${expected_lines[i]}" ]; then
        success=false
        break
    fi
done

# Check if the result matches the expected output
if $success; then
    echo -e "${GREEN}PASS: The output matches the expected result.${NC}"
else
    echo -e "${RED}FAIL: The output does not match the expected result.${NC}"
    echo "Expected:"
    printf "%s\n" "${expected_lines[@]}"
    echo "Got:"
    printf "%s\n" "${output_lines[@]}"
fi
