#!/bin/zsh

# Find the most recently modified a.out file
AOUT=$(find . -name "a.out" -type f -print0 | xargs -0 stat -f "%m %N" | sort -rn | head -1 | cut -d' ' -f2-)

# Check if the file was found
if [ -z "$AOUT" ]; then
    echo "No a.out file found."
    exit 1
fi

# Now copy it to a common location (modify the destination path as needed)
cp "$AOUT" /Users/hezhukov/Desktop/42
