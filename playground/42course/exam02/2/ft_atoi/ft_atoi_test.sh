#!/bin/bash

# ANSI color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Compile the program with the test
gcc -o test_ft_atoi ft_atoi.c test_ft_atoi.c
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

# Initialize the failure flag
failed=0

# Run the test and capture the output
output=$(./test_ft_atoi)

# Check the test result
echo "$output" | while read -r line; do
    if [[ $line == *"FAILED"* ]]; then
        echo -e "${RED}$line${NC}"
        failed=1
    else
        echo -e "${GREEN}$line${NC}"
    fi
done

# Final test result output
if [ $failed -eq 0 ]; then
    echo -e "${GREEN}All tests passed.${NC}"
else
    echo -e "${RED}Some tests failed.${NC}"
fi


# this test does not work
