#!/bin/bash

# Assignment name  : wdmatch
# Expected files   : wdmatch.c
# Allowed functions: write
# --------------------------------------------------------------------------------

# Write a program that takes two strings and checks whether it's possible to
# write the first string with characters from the second string, while respecting
# the order in which these characters appear in the second string.

# If it's possible, the program displays the string, followed by a \n, otherwise
# it simply displays a \n.

# If the number of arguments is not 2, the program displays a \n.

# Examples:

# $>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
# faya$
# $>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
# $
# $>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
# quarante deux$
# $>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
# $
# $>./wdmatch | cat -e
# $

# Compile the C program
gcc -o wdmatch_test wdmatch.c

# ANSI color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Function to run a test case
run_test() {
    str1="$1"
    str2="$2"
    expected="$3"
    echo "Testing with inputs: '$str1', '$str2'"

    # Run the program and capture the output
    result=$(./wdmatch_test "$str1" "$str2" | cat -e)

    # Check if the result matches the expected output
    if [ "$result" == "${expected}$" ]; then
        echo -e "${GREEN}PASS: Expected '$expected', got '${result%$}'${NC}"
    else
        echo -e "${RED}FAIL: Expected '$expected', but got '${result%$}'${NC}"
    fi
    echo
}

# Test cases
run_test "faya" "fgvvfdxcacpolhyghbreda" "faya" # all characters of "faya" appear in the same order in the second string.
run_test "faya" "fgvvfdxcacpolhyghbred" "" # the second string lacks the letter 'a' after 'y', so "faya" cannot be formed.
run_test "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " "quarante deux" # all characters of "quarante deux" appear in order in the second string.
run_test "error" "rrerrrfiiljdfxjyuifrrvcoojh" "" # does not contain the sequence of characters in "error" in the correct order.
run_test "" "" "" # No input

# Add more test cases as needed
