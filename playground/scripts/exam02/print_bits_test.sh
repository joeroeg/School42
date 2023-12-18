#!/bin/bash

# Compile the C program
gcc -o print_bits_test print_bits.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    input=$1
    echo "Testing with input: $input"
    expected=$(printf '%08d' $(bc <<< "ibase=10;obase=2;$input"))
    echo -e "Expected output: ${GREEN}$expected${NC}"
    echo -n "Actual output:   "
    ./print_bits_test "$input"
    echo -e "\n"
}

# Test cases
run_test 0
run_test 1
run_test 2
run_test 127
run_test 128
run_test 255

# Add more test cases as needed
