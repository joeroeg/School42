#!/bin/bash

# Compile the C program
gcc pgcd.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    num1=$1
    num2=$2
    expected=$3
    echo "Testing with input: $num1 $num2"

    # Run the program and capture the output
    result=$(./a.out "$num1" "$num2" | cat -e)

    # Check if the result matches the expected output
    if [ "$result" == "${expected}$" ]; then
        echo -e "${GREEN}PASS: Expected $expected, got ${result%$}${NC}"
    else
        echo -e "${RED}FAIL: Expected $expected, but got ${result%$}${NC}"
    fi
    echo
}

# Test cases
run_test 42 10 2
run_test 42 12 6
run_test 14 77 7
run_test 17 3 1

# Test cases with invalid inputs
run_test "" "" ""
run_test 42 0 42
run_test -42 0

#
