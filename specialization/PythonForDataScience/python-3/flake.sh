#!/bin/bash

find . -type f -name "*.py" | while read -r file; do
    flake8 "$file"
    if [ $? -ne 0 ]; then
        echo "❌ $file"
        exit 1
    fi
    echo "✅ $file"
done
