#!/bin/bash

# Assignment name  : reverse_bits
# Expected files   : reverse_bits.c
# Allowed functions:
# --------------------------------------------------------------------------------

# Write a function that takes a byte, reverses it, bit by bit (like the
# example) and returns the result.

# Your function must be declared as follows:

# unsigned char	reverse_bits(unsigned char octet);

# Example:

#   1 byte
# _____________
#  0010  0110
# 	 ||
# 	 \/
#  0110  0100


# Compile the C program along with the test program
gcc -o test_reverse_bits reverse_bits.c test_reverse_bits.c

# Function to run a test case
run_test() {
    input=$1
    expected=$2

    # Run the program and capture the output
    result=$(./test_reverse_bits "$input" | grep -o '[0-9]*$')

    # Check if the result matches the expected output
    if [ "$result" -eq "$expected" ]; then
        echo "PASS: Input $input -> Expected $expected, got $result"
    else
        echo "FAIL: Input $input -> Expected $expected, but got $result"
    fi
}

# Convert binary string to decimal
bin_to_dec() {
    echo $((2#$1))
}

# Test cases
# Format: run_test <decimal representation of input byte> <decimal representation of expected reversed byte>
run_test $(bin_to_dec 00100110) $(bin_to_dec 01100100) # Example from the assignment
run_test $(bin_to_dec 00000001) $(bin_to_dec 10000000)
run_test $(bin_to_dec 11111111) $(bin_to_dec 11111111)
run_test $(bin_to_dec 10101010) $(bin_to_dec 01010101)

# Add more test cases as needed
