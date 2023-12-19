#!/bin/bash

# Compile your C program (replace 'your_program.c' with your actual C file)
gcc ft_putstr.c

# Define a function to run a test case
run_test() {
    input="$1"
    expected_output="$input"  # Set the expected output to the input string

    # Run the C program and capture the actual output
    actual_output=$(./a.out "$input")

    # Compare the actual output with the expected output using diff
    if [ "$actual_output" == "$expected_output" ]; then
        echo "Test with input '$input': ✅ Passed"
    else
        echo "Test with input '$input': ❌ Failed (Expected: '$expected_output', Got: '$actual_output')"
    fi
}

# Test cases
run_test "Hello, World!"
run_test "123456"
run_test ""
run_test "Test with spaces"

# Add more test cases as needed

# Clean up (optional)
rm -f a.out
