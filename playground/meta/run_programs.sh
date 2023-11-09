#!/bin/bash

# Initial program
program="program1"

# Compile and run loop
while [ -f "${program}.c" ]; do
    # Compile the C program
    gcc -o $program "${program}.c"

    # Check for compile success
    if [ $? -ne 0 ]; then
        echo "Compilation failed for ${program}.c"
        exit 1
    fi

    # Run the compiled program
    ./$program

    # Determine the next program name
    num=$(echo "$program" | sed 's/[^0-9]*//g')
    next_num=$((num + 1))
    program="program${next_num}"

    # Check if the next program file was generated
    if [ ! -f "${program}.c" ]; then
        echo "Next program file ${program}.c not generated."
        exit 1
    fi
done
