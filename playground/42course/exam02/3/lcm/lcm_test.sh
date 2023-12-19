#!/bin/bash

# Compile the C program along with the test program
gcc lcm.c test_lcm.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    num1=$1
    num2=$2
    expected=$3

    # Run the program and capture the output
    result=$(./a.out "$num1" "$num2")

    # Check if the result matches the expected output
    if [ "$result" -eq "$expected" ]; then
        echo -e "${GREEN}PASS: num_a = $num1, num_b = $num2 -> Expected $expected, got $result${NC}"
    else
        echo -e "${RED}FAIL: num_a = $num1, num_b = $num2 -> Expected $expected, but got $result${NC}"
    fi
}

# Test cases
run_test 6 8 24
run_test 21 6 42
run_test 0 5 0
run_test 7 0 0
run_test 15 17 255
run_test 1 1 1
run_test 0 0 0

# Add more test cases as needed
