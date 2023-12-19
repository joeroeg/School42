#!/bin/bash

# Compile your C program (replace 'your_program.c' with your actual C file)
gcc rotone.c -o a.out

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
run_test "abc" "bcd"
run_test "Hello, World!" "Ifmmp, Xpsme!"
run_test "123" "123"
run_test "Test!" "Uftu!"
run_test "aA" "bB"

# Clean up (optional)
rm -f your_program
