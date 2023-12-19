#!/bin/bash

# Assignment name  : ft_strrev
# Expected files   : ft_strrev.c
# Allowed functions:
# --------------------------------------------------------------------------------

# Write a function that reverses (in-place) a string.
# It must return its parameter.
# Your function must be declared as follows:
# char    *ft_strrev(char *str);


# Compile the C program along with the test program
gcc -o test_ft_strrev ft_strrev.c test_ft_strrev.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    input=$1
    expected=$2

    # Run the program and capture the output
    result=$(./test_ft_strrev "$input")

    # Check if the result matches the expected output
    if [ "$result" == "$expected" ]; then
        echo -e "${GREEN}PASS: Input '$input' -> Expected '$expected', got '$result'${NC}"
    else
        echo -e "${RED}FAIL: Input '$input' -> Expected '$expected', but got '$result'${NC}"
    fi
}

# Test cases
run_test "hello" "olleh"
run_test "test" "tset"
run_test "12345" "54321"
run_test "A" "A" # Test single character
run_test "" ""   # Test empty string

# Add more test cases as needed
