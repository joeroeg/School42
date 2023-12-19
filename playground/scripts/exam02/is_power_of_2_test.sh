#!/bin/bash

# Compile the C program
gcc -o is_power_of_2_test is_power_of_2.c

# Function to run a test case
run_test() {
    input=$1
    expected=$2

    # Run the program and capture the output
    result=$(./is_power_of_2_test "$input")

    # Check if the result matches the expected output
    if [ "$result" -eq "$expected" ]; then
        echo -e "${GREEN}PASS: Input '$input' -> Expected '$expected', got '$result'${NC}"
    else
        echo -e "${RED}FAIL: Input '$input' -> Expected '$expected', but got '$result'${NC}"
    fi
}

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Test cases with powers of 2
run_test 1 1
run_test 2 1
run_test 4 1
run_test 8 1
run_test 16 1
run_test 64 1
run_test 128 1
run_test 256 1
run_test 1024 1

# Test cases with even numbers that are not powers of 2
run_test 6 0
run_test 10 0
run_test 14 0
run_test 18 0
run_test 20 0
run_test 28 0
run_test 50 0
run_test 100 0
run_test 200 0

# Test cases with odd numbers and not powers of 2
run_test 3 0
run_test 5 0
run_test 7 0
run_test 9 0
run_test 15 0
run_test 21 0
run_test 31 0
run_test 63 0
run_test 127 0
run_test 255 0
run_test 511 0

# Add more test cases as needed
run_test 0 0
