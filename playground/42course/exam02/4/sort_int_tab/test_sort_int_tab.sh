#!/bin/bash

# ANSI color codes for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Compile the program with the test
gcc -o test_sort_int_tab sort_int_tab.c test_sort_int_tab.c
if [ $? -ne 0 ]; then
    echo -e "${RED}Compilation failed.${NC}"
    exit 1
fi

# Function to check if the array is sorted
is_sorted() {
    local -a arr=("$@")
    for (( i = 0; i < ${#arr[@]} - 1; i++ )); do
        if (( arr[i] > arr[i + 1] )); then
            return 1
        fi
    done
    return 0
}

# Run the test and capture only the sorted array
sorted_array=($(./test_sort_int_tab | sed -n '/Sorted array:/,$p' | grep -o '[0-9]\+'))

# Check if the array is sorted
if is_sorted "${sorted_array[@]}"; then
    echo -e "${GREEN}Test passed.${NC}"
else
    echo -e "${RED}Test failed.${NC}"
fi

