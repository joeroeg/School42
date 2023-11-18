#!/bin/bash

# Check if sufficient arguments are provided
if [ $# -lt 2 ]; then
    echo "Usage: $0 <path_to_project> <executable_name>"
    exit 1
fi

PROJECT_PATH=$1
EXECUTABLE_NAME=$2
EXECUTABLE_PATH="$PROJECT_PATH/$EXECUTABLE_NAME"
LOG_DIR="$PROJECT_PATH/valgrind_logs"

# Create the log directory if it doesn't exist
if [ ! -d "$LOG_DIR" ]; then
    mkdir -p "$LOG_DIR"
fi

# Navigate to project directory
cd $PROJECT_PATH
if [ $? -ne 0 ]; then
    echo "Failed to navigate to project directory: $PROJECT_PATH"
    exit 1
fi

# Compile the program using Makefile
echo "Compiling the program in $PROJECT_PATH..."
make
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run Valgrind and save the output to a log file
LOG_FILE="$LOG_DIR/valgrind_log_$(date +%Y%m%d_%H%M%S).txt"
echo "Running Valgrind on $EXECUTABLE_PATH..."
valgrind --leak-check=full $EXECUTABLE_PATH 2>&1 | tee "$LOG_FILE" | grep -E "ERROR SUMMARY|definitely lost|indirectly lost|possibly lost|still reachable|Invalid read|Invalid write|uninitialised"

if [ ${PIPESTATUS[0]} -ne 0 ]; then
    echo "Valgrind encountered an error."
    exit 1
fi

echo "Valgrind output saved to $LOG_FILE"
echo "Valgrind check completed successfully."
