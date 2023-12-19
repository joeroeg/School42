#!/bin/bash

# Compile the C program along with the test program
gcc ft_split.c test_ft_split.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    input="$1"
    expected_count=$2
    echo "Testing with input: '$input'"

    # Run the program and capture the output
    output=$(./a.out "$input")

    # Count the number of lines in the output, each line represents a word
    actual_count=$(echo "$output" | grep -c '^')

    # Check if the count matches the expected output
    if [ "$actual_count" -eq "$expected_count" ]; then
        echo -e "${GREEN}PASS: Input '$input' -> Expected word count $expected_count, got $actual_count${NC}"
    else
        echo -e "${RED}FAIL: Input '$input' -> Expected word count $expected_count, but got $actual_count${NC}"
    fi
    echo "$output"
    echo
}

# Test cases with known word counts
run_test "This is a test" 4
run_test "   Leading and trailing spaces   " 4
run_test "Word\tTab Separation" 2
run_test "Line\nBreaks\nIn\nString" 1
run_test "SingleWord" 1
# run_test "" 0  # Empty string (expected result must be tested)
# run_test "    " 0  # String with only spaces (expected result must be tested)

# Add more test cases as needed
