#!/bin/bash

# Compile your C program (replace 'your_program.c' with your actual C file)
gcc first_word.c

# Define a function to run a test case
run_test() {
    input="$1"
    expected_output="$2"

    # Run the C program and capture the actual output
    actual_output=$(./a.out "$input")

    # Check if there is a newline character at the end of the actual output
    if [ "${actual_output: -1}" == $'\n' ]; then
        actual_output="${actual_output::-1}" # Remove the trailing newline for comparison
    fi

    # Compare the actual output with the expected output
    if [ "$actual_output" == "$expected_output" ]; then
        echo "Test with input '$input': ✅ Passed"
    else
        echo "Test with input '$input': ❌ Failed (Expected: '$expected_output', Got: '$actual_output')"
    fi
}

# Test cases
run_test "FOR PONY" "FOR"
run_test "this        ...       is sparta, then again, maybe    not" "this"
run_test "   " ""
run_test "a b" "a"
run_test "  lorem,ipsum  " "lorem,ipsum"
run_test "" ""

# Clean up (optional)
rm -f a.out
