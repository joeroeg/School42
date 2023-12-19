#!/bin/bash

# Compile your C program (replace 'search_and_replace.c' with your actual C file)
gcc search_and_replace.c

# Define a function to run a test case
run_test() {
    input="$1"
    search="$2"
    replace="$3"
    expected_output="$4"

    # Run the C program and capture the actual output
    actual_output=$(./a.out "$input" "$search" "$replace" | cat -e)

    # Append a $ to the end of the expected output if the argument count is not 4
    if [ $# -ne 4 ]; then
        expected_output="$expected_output$"
    fi

    # Compare the actual output with the expected output using diff
    if [ "$actual_output" == "$expected_output" ]; then
        echo "Test with input '$input': ✅ Passed"
    else
        echo "Test with input '$input': ❌ Failed (Expected: '$expected_output', Got: '$actual_output')"
    fi
}

# Run test cases
run_test "hello world" "o" "0" "hell0 w0rld$"
run_test "abcde" "c" "C" "abCde$"
run_test "12345" "6" "7" "12345$"
run_test "Testing" "t" "T" "TesTing$"
run_test "" "" "" "$"

# Additional test case for argc not equal to 4
run_test "hello" "o" "" "$" # Should expect a newline at the end

# Clean up (optional)
rm -f a.out
