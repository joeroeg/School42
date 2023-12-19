#!/bin/bash

# Compile your C program (replace 'your_program.c' with your actual C file)
gcc ulstr.c

# Define a function to run a test case
run_test() {
    input="$1"
    expected_output="$2"

    # Run the C program and capture the actual output
    actual_output=$(./a.out "$input")

    # Compare the actual output with the expected output using diff
    if [ "$actual_output" == "$expected_output" ]; then
        echo "Test with input '$input': ✅ Passed"
    else
        echo "Test with input '$input': ❌ Failed (Expected: '$expected_output', Got: '$actual_output')"
    fi
}

# Run test cases
run_test "Hello, World!" "hELLO, wORLD!"
run_test "12345" "12345"
run_test "abcDEF" "ABCdef"
run_test "Testing 123" "tESTING 123"

# Clean up (optional)
rm -f a.out
