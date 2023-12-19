#!/bin/bash

# ANSI color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Compile the program
gcc -o test_list_remove_if ft_list_remove_if.c test_ft_list_remove_if.c
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

# Run the test
./test_list_remove_if
if [ $? -ne 0 ]; then
    echo -e "${RED}Test failed.${NC}"
else
    echo -e "${GREEN}Test passed.${NC}"
fi
