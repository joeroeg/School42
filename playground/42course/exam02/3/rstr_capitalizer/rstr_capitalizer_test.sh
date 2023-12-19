#!/bin/bash

# Compile the C program
gcc -o rstr_capitalizer_test rstr_capitalizer.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    input="$1"
    expected="$2"
    echo "Testing with input: '$input'"

    # Run the program and capture the output
    result=$(./rstr_capitalizer_test "$input" | cat -e)

    # Check if the result matches the expected output
    if [ "$result" == "${expected}$" ]; then
        echo -e "${GREEN}PASS: Expected '$expected', got '${result%$}'${NC}"
    else
        echo -e "${RED}FAIL: Expected '$expected', but got '${result%$}'${NC}"
    fi
    echo
}

# Test cases
run_test "a FiRSt LiTTlE TESt" "A firsT littlE tesT"
run_test "SecONd teST A LITtle BiT   Moar comPLEX" "seconD tesT A littlE biT   moaR compleX"
run_test "   But... This iS not THAT COMPLEX" "   but... thiS iS noT thaT compleX"
run_test "     Okay, this is the last 1239809147801 but not    the least    t" "     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T"
run_test "" ""

# Add more test cases as needed
