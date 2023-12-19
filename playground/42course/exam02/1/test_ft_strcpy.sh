#!/bin/bash

# Compile the C program
gcc ft_strcpy.c

# Function to run a test case
ft_strcpy() {
    input="$1"
    expected_output="$2"
    actual_output=$(./a.out "dummy" "$input")

    # Check if the actual output matches the expected output
    if [ "$actual_output" == "$expected_output" ]; then
        echo "✅ '$input'"
    else
        echo "❌ '$input'"
        return
    fi

    # Check for null termination by looking at the length
    if [ ${#actual_output} -eq ${#input} ]; then
        echo "✅ (Null-Terminated)"
    else
        echo "❌ (Not Null-Terminated)"
    fi
}

# Test cases
ft_strcpy "Hello, World!" "Hello, World!"
ft_strcpy "123456" "123456"
ft_strcpy "" ""
ft_strcpy "Test with spaces" "Test with spaces"
ft_strcpy "SpecialChars@#$$%^&*()" "SpecialChars@#$$%^&*()"

# Add more test cases as needed
