#!/bin/bash

# ANSI color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Compile the program with the test
gcc -o test_ft_list_foreach ft_list_foreach.c test_ft_list_foreach.c
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

# Run the test
./test_ft_list_foreach
result=$?

# Check the test result
if [ $result -eq 0 ]; then
    echo -e "${GREEN}Test passed.${NC}"
else
    echo -e "${RED}Test failed.${NC}"
fi
