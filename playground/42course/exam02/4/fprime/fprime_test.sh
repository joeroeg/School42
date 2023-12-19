#!/bin/bash

# Compile the C program
gcc fprime.c

# Function to run a test case
run_test() {
    input="$1"
    expected="$2"

    # Run the program and capture the output
    if [ -z "$input" ]; then
        result=$(./a.out | cat -e)
    else
        result=$(./a.out "$input" | cat -e)
    fi

    # Check if the result matches the expected output
    if [ "$result" == "$expected" ]; then
        echo -e "${GREEN}PASS: Input '$input' -> Expected '$expected', got '$result'${NC}"
    else
        echo -e "${RED}FAIL: Input '$input' -> Expected '$expected', but got '$result'${NC}"
    fi
}

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Test cases
run_test "225225" "3*3*5*5*7*11*13$"
run_test "8333325" "3*3*5*5*7*11*13*37$"
run_test "9539" "9539$"
run_test "804577" "804577$"
run_test "42" "2*3*7$"
run_test "1" "1$"
run_test ""   "$"
