#!/bin/bash

# Loop through each formula
for formula in $(brew list --formula); do
    formula_path="/Users/hezhukov/.brew/Cellar/${formula}"
    if [ -d "$formula_path" ]; then
        # Get the size of the directory and print it alongside the formula name
        du -sh "$formula_path" 2>/dev/null | awk '{print $2 ": " $1}'
    else
        echo "${formula}: Not found in Cellar"
    fi
done | sort -k2,2 -h -r
