#!/bin/bash

# ANSI color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Compile the program
gcc -o test_sort_list sort_list.c test_sort_list.c
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

# Run the test
./test_sort_list
if [ $? -ne 0 ]; then
    echo -e "${RED}Test failed.${NC}"
else
    echo -e "${GREEN}Test passed.${NC}"
fi
