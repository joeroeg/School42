#!/bin/bash

# Usage: ./exact_fuzzy_help.sh <module> <object>
MODULE=$1
OBJECT=$2

if [ -z "$MODULE" ] || [ -z "$OBJECT" ]; then
    echo "Usage: $0 <module> <object>"
    exit 1
fi

# Extract help() and pipe to fzf with exact search
python3 - <<EOF | fzf --ansi --exact
import $MODULE
from io import StringIO
import sys

# Capture help() output
obj = getattr($MODULE, "$OBJECT")
help_output = StringIO()
sys.stdout = help_output
help(obj)
sys.stdout = sys.__stdout__

# Print for fzf
print(help_output.getvalue())
EOF
