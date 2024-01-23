#!/bin/bash

# Path to your file with permutations
FILE="./permutations_of_5_numbers.txt"

# Path to your push_swap script
PUSH_SWAP="./push_swap"

# Loop through each line in the file
while IFS= read -r line
do
    # Pass the permutation to your script and count lines
    echo "Testing permutation: $line"
    $PUSH_SWAP $line | wc -l
done < "$FILE"
