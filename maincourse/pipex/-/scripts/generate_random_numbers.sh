#!/bin/bash

# File name for the generated file
output_file="random_numbers.txt"

# Number of random numbers to generate
number_count=100  # Adjust this number as needed

# Generate and write random numbers to the file
for i in $(seq 1 $number_count); do
    echo $((RANDOM)) >> "$output_file"
done

echo "File $output_file created with $number_count random numbers."
