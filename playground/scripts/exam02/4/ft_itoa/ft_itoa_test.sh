#!/bin/bash

# Compile the C program along with the test program
gcc ft_itoa.c ft_itoa_test.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    input=$1
    expected=$2

    # Run the program and capture the output
    result=$(./a.out "$input")

    # Check if the result matches the expected output
    if [ "$result" == "$expected" ]; then
        echo -e "${GREEN}PASS: Input '$input' -> Expected '$expected', got '$result'${NC}"
    else
        echo -e "${RED}FAIL: Input '$input' -> Expected '$expected', but got '$result'${NC}"
    fi
}

# Test cases
run_test 0 "0"
run_test -42 "-42"
run_test 42 "42"
run_test 2147483647 "2147483647"
run_test -2147483648 "-2147483648"

# Add more test cases as needed
