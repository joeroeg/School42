#!/bin/bash

# Compile the C program
gcc add_prime_sum.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    input=$1
    expected=$2

    # Run the program and capture the output
    result=$(./a.out "$input" | cat -e)

    # Check if the result matches the expected output
    if [ "$result" == "${expected}$" ]; then
        echo -e "${GREEN}PASS: Input '$input' -> Expected '$expected', got '${result%$}'${NC}"
    else
        echo -e "${RED}FAIL: Input '$input' -> Expected '$expected', but got '${result%$}'${NC}"
    fi
}

# Test cases with valid inputs
run_test 5 10
run_test 7 17
run_test 2 2  # Since 2 is the only prime number less than or equal to itself
run_test 3 5  # Sum of primes 2 and 3
run_test 8 17  # Same as for 7
run_test 12 28 # Same as for 11
run_test 100 1060

# Test cases with invalid inputs
run_test "" 0
run_test "-1" 0
run_test "abc" 0
run_test "1 2" 0
run_test 1 0


# Add more test cases as needed
