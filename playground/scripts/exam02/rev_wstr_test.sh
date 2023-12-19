#!/bin/bash

# Compile the C program
gcc rev_wstr.c

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
run_test "You hate people! But I love gatherings. Isn't it ironic?" "ironic? it Isn't gatherings. love I But people! hate You$"
run_test "abcdefghijklm" "abcdefghijklm$"
run_test "Wingardium Leviosa" "Leviosa Wingardium$"
run_test "" "$"

# Add more test cases as needed
