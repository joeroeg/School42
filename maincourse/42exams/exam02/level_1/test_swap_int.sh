#!/bin/bash

# Compile the C program
gcc ft_swap.c -o test_swap_int

# Function to run a test case
test_swap_int() {
    input_a="$1"
    input_b="$2"
    expected_output="$3 $4"  # Ensure no extra space after the second number
    actual_output=$(./test_swap_int "$input_a" "$input_b")

    if [ "$actual_output" == "$expected_output" ]; then
        echo "Test with input ($input_a, $input_b): ✅ Passed"
    else
        echo "Test with input ($input_a, $input_b): ❌ Failed (Expected: '$expected_output', Got: '$actual_output')"
    fi
}

# Test cases
test_swap_int 10 20 "20 10"
test_swap_int -5 3 "3 -5"
test_swap_int 0 0 "0 0"
test_swap_int 123 456 "456 123"

# Add more test cases as needed
