#!/bin/bash

# Compile the C program
gcc ft_strlen.c

# Function to run a test case
ft_strlen() {
    input="$1"
    expected_length="$2"
    actual_length=$(./a.out "$input")

    if [ -z "$actual_length" ]; then
        echo "Test with input '$input': ❌ Failed (No output received)"
    elif [ "$actual_length" -eq "$expected_length" ]; then
        echo "Test with input '$input': ✅ Passed (Length: $actual_length)"
    else
        echo "Test with input '$input': ❌ Failed (Expected: $expected_length, Got: $actual_length)"
    fi
}

# Test cases
ft_strlen "Hello, World!" 13
ft_strlen "123456" 6
ft_strlen "" 0
ft_strlen "Test with spaces" 16
ft_strlen "SpecialChars@#31343\%^&*()" 26  # Escape special characters

# Add more test cases as needed
