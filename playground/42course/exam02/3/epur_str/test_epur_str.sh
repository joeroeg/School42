#!/bin/bash

# ANSI color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Compile the program
gcc -o epur_str epur_str.c
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

# Function to run a test case
run_test() {
    expected="$1"
    shift
    echo "Testing with input: $*"

    # Run the program with the inputs as arguments and capture the output
    result=$(./epur_str "$@")

    # Check if the result matches the expected output
    if [ "$result" == "$expected" ]; then
        echo -e "${GREEN}PASS: Expected '$expected', got '$result'${NC}"
    else
        echo -e "${RED}FAIL: Expected '$expected', but got '$result'${NC}"
    fi
}

# Test cases
run_test "See? It's easy to print the same thing" "See? It's easy to print the same thing"
run_test "this time it will be more complex ." " this        time it      will     be    more complex  . "
run_test "" "No S*** Sherlock..." "nAw S*** ShErLaWQ..."
run_test "" ""

# Add more test cases as needed
