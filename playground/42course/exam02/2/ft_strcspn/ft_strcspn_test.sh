#!/bin/bash

# Assignment name	: ft_strcspn
# Expected files	: ft_strcspn.c
# Allowed functions: None
# ---------------------------------------------------------------
# Reproduce exactly the behavior of the function strcspn
# (man strcspn).
# The function should be prototyped as follows:
# size_t	ft_strcspn(const char *s, const char *reject);

# Compile the C program along with the test program
gcc ft_strcspn.c test_ft_strcspn.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    string=$1
    reject=$2
    expected=$3

    # Run the program and capture the output
    result=$(./a.out "$string" "$reject")

    # Check if the result matches the expected output
    if [ "$result" -eq "$expected" ]; then
        echo -e "${GREEN}PASS: String '$string', Reject '$reject' -> Expected '$expected', got '$result'${NC}"
    else
        echo -e "${RED}FAIL: String '$string', Reject '$reject' -> Expected '$expected', but got '$result'${NC}"
    fi
}

# Test cases
run_test "hello world" "def" 1
run_test "example string" " " 7
run_test "test" "test" 0
run_test "another test" " " 7
run_test "123456" "789" 6

# Add more test cases as needed
