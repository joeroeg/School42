#!/bin/bash

# Compile the C program
gcc -o rostring_test rostring.c

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
    if [ -z "$input" ]; then
        result=$(./rostring_test | cat -e)
    else
        result=$(./rostring_test "$input" | cat -e)
    fi

    # Check if the result matches the expected output
    if [ "$result" == "${expected}$" ]; then
        echo -e "${GREEN}PASS: Expected '$expected', got '${result%$}'${NC}"
    else
        echo -e "${RED}FAIL: Expected '$expected', but got '${result%$}'${NC}"
    fi
    echo
}

# Test cases
run_test "abc   " "abc"
run_test "Que la      lumiere soit et la lumiere fut" "la lumiere soit et la lumiere fut Que"
run_test "     AkjhZ zLKIJz , 23y" "zLKIJz , 23y AkjhZ"
run_test "first" "first" # Only one word
run_test "" ""  # No input

# Add more test cases as needed


# Assignment name  : rostring
# Expected files   : rostring.c
# Allowed functions: write, malloc, free
# --------------------------------------------------------------------------------

# Write a program that takes a string and displays this string after rotating it
# one word to the left.

# Thus, the first word becomes the last, and others stay in the same order.

# A "word" is defined as a part of a string delimited either by spaces/tabs, or
# by the start/end of the string.

# Words will be separated by only one space in the output.

# If there's less than one argument, the program displays \n.

# Example:

# $>./rostring "abc   " | cat -e
# abc$
# $>
# $>./rostring "Que la      lumiere soit et la lumiere fut"
# la lumiere soit et la lumiere fut Que
# $>
# $>./rostring "     AkjhZ zLKIJz , 23y"
# zLKIJz , 23y AkjhZ
# $>
# $>./rostring "first" "2" "11000000"
# first
# $>
# $>./rostring | cat -e
# $
# $>
