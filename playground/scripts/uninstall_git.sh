#!/bin/bash

# Replace "./" with the actual path to your target directory.
TARGET_DIR="./"

# Find and delete all .git directories and their contents
find "$TARGET_DIR" -type d -name ".git" -exec rm -rf {} +

# Optionally, find and delete all .gitignore files if needed
# find "$TARGET_DIR" -type f -name ".gitignore" -exec rm -f {} +

# Optionally, find and delete all .gitattributes files if needed
# find "$TARGET_DIR" -type f -name ".gitattributes" -exec rm -f {} +
