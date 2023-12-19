#!/bin/bash

# Compile the C program
gcc ft_atoi_base.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    input=$1
    base=$2
    expected=$3

    # Run the program and capture the output
    result=$(./a..out "$input" "$base")

    # Check if the result matches the expected output
    if [ "$result" -eq "$expected" ]; then
        echo -e "${GREEN}PASS: Input '$input' with base $base -> Expected $expected, got $result${NC}"
    else
        echo -e "${RED}FAIL: Input '$input' with base $base -> Expected $expected, but got $result${NC}"
    fi
}

# Test cases
run_test "101" 2 5
run_test "ff" 16 255
run_test "123" 10 123
run_test "-10" 10 -10
run_test "12fdb3" 16 1244595
run_test "12FDB3" 16 1244595
run_test "1234" 5 194

# Add more test cases as needed
