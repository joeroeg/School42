#!/bin/bash

# For compilation with Makefile: ./valgrind_check.sh make /path/to/project target_name
# For using an existing executable: ./valgrind_check.sh exec /path/to/project executable_name

# Check if sufficient arguments are provided
if [ $# -lt 3 ]; then
    echo "Usage: $0 <mode: make|exec> <path_to_project> <makefile_or_executable_name>"
    exit 1
fi

MODE=$1
PROJECT_PATH=$2
NAME=$3
LOG_DIR="$PROJECT_PATH/valgrind_logs"

# Valgrind flags - Set these to 1 to enable, 0 to disable
LEAK_CHECK=1  # check for memory leaks
SHOW_LEAK_KINDS=1 # show the kinds of leaks
TRACK_ORIGINS=1 # track origins of uninitialised values
VERBOSE=1 # show extra information
LOG_TO_FILE=1 # save Valgrind output to a log file
USE_GREP=0  # to enable grep filtering

# Building the Valgrind command
VALGRIND_CMD="valgrind"

if [ $LEAK_CHECK -eq 1 ]; then
    VALGRIND_CMD+=" --leak-check=full"
fi

if [ $SHOW_LEAK_KINDS -eq 1 ]; then
    VALGRIND_CMD+=" --show-leak-kinds=all"
fi

if [ $TRACK_ORIGINS -eq 1 ]; then
    VALGRIND_CMD+=" --track-origins=yes"
fi

if [ $VERBOSE -eq 1 ]; then
    VALGRIND_CMD+=" --verbose"
fi

# Create the log directory if it doesn't exist
if [ ! -d "$LOG_DIR" ]; then
    mkdir -p "$LOG_DIR"
fi

# Navigate to project directory
cd "$PROJECT_PATH"
if [ $? -ne 0 ]; then
    echo "Failed to navigate to project directory: $PROJECT_PATH"
    exit 1
fi

# Compile with Makefile or use provided executable
if [ "$MODE" == "make" ]; then
    echo "Compiling with Makefile in $PROJECT_PATH..."
    make run
    if [ $? -ne 0 ]; then
        echo "Compilation failed."
        exit 1
    fi
    EXECUTABLE_PATH="./$NAME"  # Assuming executable name is provided
elif [ "$MODE" == "exec" ]; then
    EXECUTABLE_PATH="./$NAME"
else
    echo "Invalid mode. Use 'make' or 'exec'."
    exit 1
fi

# Run Valgrind and handle output
LOG_FILE="$LOG_DIR/valgrind_log_$(date +%Y%m%d_%H%M%S).txt"
echo "Running Valgrind on $EXECUTABLE_PATH..."

if [ $LOG_TO_FILE -eq 1 ]; then
    VALGRIND_CMD+=" --log-file=$LOG_FILE"
    $VALGRIND_CMD $EXECUTABLE_PATH

    if [ $USE_GREP -eq 1 ]; then
        grep -E "ERROR SUMMARY|definitely lost|indirectly lost|possibly lost|still reachable|Invalid read|Invalid write|uninitialised" "$LOG_FILE"
    fi
else
    $VALGRIND_CMD $EXECUTABLE_PATH
fi

if [ $? -ne 0 ]; then
    echo "Valgrind encountered an error."
    exit 1
fi

echo "Valgrind check completed successfully."
if [ $LOG_TO_FILE -eq 1 ]; then
    echo "Valgrind output saved to $LOG_FILE"
fi
