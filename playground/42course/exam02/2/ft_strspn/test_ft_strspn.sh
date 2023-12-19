#!/bin/bash

# Compile the C program along with the test program
gcc -o test_ft_strspn ft_strspn.c test_ft_strspn.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    s=$1
    accept=$2
    expected=$3

    # Run the program and capture the output
    result=$(./test_ft_strspn "$s" "$accept")

    # Check if the result matches the expected output
    if [ "$result" -eq "$expected" ]; then
        echo -e "${GREEN}PASS: s='$s', accept='$accept' -> Expected $expected, got $result${NC}"
    else
        echo -e "${RED}FAIL: s='$s', accept='$accept' -> Expected $expected, but got $result${NC}"
    fi
}

# Test cases
run_test "abcdefgh" "abc" 3
run_test "129th" ""1234567890"" 3
run_test "hello world" "hel" 4
run_test "test123" "12345" 0
run_test "prefixsuffix" "prefix" 6

# Add more test cases as needed
