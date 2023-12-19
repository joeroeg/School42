#!/bin/bash

# Compile the C program
gcc hidenp.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    s1=$1
    s2=$2
    expected=$3

    # Run the program and capture the output
    result=$(./a.out "$s1" "$s2" | cat -e)

    # Check if the result matches the expected output
    if [ "$result" == "${expected}$" ]; then
        echo -e "${GREEN}PASS: s1='$s1', s2='$s2' -> Expected '$expected', got '${result%$}'${NC}"
    else
        echo -e "${RED}FAIL: s1='$s1', s2='$s2' -> Expected '$expected', but got '${result%$}'${NC}"
    fi
}

# Test cases
run_test "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" 1
run_test "abc" "2altrb53c.sse" 1
run_test "abc" "btarc" 0
run_test "" "" 1  # Empty string is always hidden
run_test "a" "" 0  # Non-empty string is not hidden in empty string
run_test "" "any" 1 # Empty string is hidden in any string
run_test "" "" 1

# Add more test cases as needed
