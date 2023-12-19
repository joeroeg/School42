#!/bin/bash

# Assignment name	: ft_strpbrk
# Expected files	: ft_strpbrk.c
# Allowed functions: None
# ---------------------------------------------------------------

# Reproduce exactly the behavior of the function strpbrk
# (man strpbrk).
# The function should be prototyped as follows:
# char	*ft_strpbrk(const char *s1, const char *s2);

# Compile the C program along with the test program
gcc -o test_ft_strpbrk ft_strpbrk.c test_ft_strpbrk.c

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
    result=$(./test_ft_strpbrk "$s1" "$s2")

    # Check if the result matches the expected output
    if [ "$result" == "$expected" ]; then
        echo -e "${GREEN}PASS: s1='$s1', s2='$s2' -> Expected '$expected', got '$result'${NC}"
    else
        echo -e "${RED}FAIL: s1='$s1', s2='$s2' -> Expected '$expected', but got '$result'${NC}"
    fi
}

# Test cases
run_test "hello world" "abcdef" "ello world" # correct input
run_test " teststring " "e" "eststring " # leading spaces
run_test "abcdef" "zyx" "NULL" # no characters in charset
run_test "123456" "34" "3456" # test digits
