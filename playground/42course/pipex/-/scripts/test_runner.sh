#!/bin/bash

# Define the shells to test in
shells=("bash" "zsh" "ksh" /* other shells you want to test */)

# Define the script to test
test_script="./random_command_test.sh"

# Define a directory to store logs
log_dir="./test_logs"
mkdir -p "$log_dir"

# Function to run test in a specific shell
run_test_in_shell() {
    local shell=$1
    local timestamp=$(date +%Y%m%d_%H%M%S)
    local log_file="$log_dir/${shell}_log_$timestamp.txt"

    echo "Running test in $shell..."
    $shell $test_script > "$log_file" 2>&1
}

# Run the test script in each shell
for shell in "${shells[@]}"; do
    run_test_in_shell "$shell"
done

echo "Tests completed. Logs are in $log_dir."
