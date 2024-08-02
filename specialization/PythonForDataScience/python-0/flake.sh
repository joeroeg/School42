#!/bin/bash

find . -type f -name "*.py" | while read -r file; do
    flake8 "$file"
    if [ $? -ne 0 ]; then
        echo "❌ flake8 failed on $file"
        exit 1
    fi
    echo "✅ flake8 passed on $file"
done
