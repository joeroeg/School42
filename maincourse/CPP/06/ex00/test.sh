#!/bin/bash

inputs=(
        "0"
        "42"
        "-42"
        "0.1"
        "255"
        "-255"
        "32767"
        "-32768"
        "2147483647"
        "-2147483648"
        "2147483648"
        "-2147483649"
        "-inf"
        "+inf"
        "nan"
        "-inff"
        "+inff"
        "nanf"

)

for input in "${inputs[@]}"; do
    echo " Input: $input"
    output=$(./a.out "$input")
    echo "$output"
    echo
done
