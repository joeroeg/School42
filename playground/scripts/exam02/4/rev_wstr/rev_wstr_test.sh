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


# Assignment name  : rev_wstr
# Expected files   : rev_wstr.c
# Allowed functions: write, malloc, free
# --------------------------------------------------------------------------------

# Write a program that takes a string as a parameter, and prints its words in
# reverse order.

# A "word" is a part of the string bounded by spaces and/or tabs, or the
# begin/end of the string.

# If the number of parameters is different from 1, the program will display
# '\n'.

# In the parameters that are going to be tested, there won't be any "additional"
# spaces (meaning that there won't be additionnal spaces at the beginning or at
# the end of the string, and words will always be separated by exactly one space).

# Examples:

# $> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
# ironic? it Isn't gatherings. love I But people! hate You$
# $>./rev_wstr "abcdefghijklm"
# abcdefghijklm
# $> ./rev_wstr "Wingardium Leviosa" | cat -e
# Leviosa Wingardium$
# $> ./rev_wstr | cat -e
# $
# $>
