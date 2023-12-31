#!/bin/bash

# Array of test commands
declare -a commands=(
    "./pipex infile \"cat\" \"NULL\" outfile"
    "./pipex infile \"NULL\" \"sort\" outfile"
    "./pipex infile \"cat\" \"sort\" outfile"
    "./pipex infile \"cat -e\" \"sort -r\" outfile"
    "./pipex infile \"cat\" \"\" outfile"
    "./pipex infile \"\" \"sort\" outfile"
    "./pipex infile \"cat -e\" \"sort -invalid\" outfile"
    "./pipex infile \"cat -invalid\" \"sort -r\" outfile"
    "./pipex infile \"\" \"\" outfile"
    "./pipex infile \"NULL\" \"\" outfile"
    "./pipex infile \"cat\" \"NULL\" outfile"
    "./pipex infile \"NULL\" \"sort\" outfile"
    "./pipex infile \"NULL\" \"NULL\" outfile"
    "./pipex infile \"cat -e\" \"error -r\" outfile"
    "./pipex infile \"error -e\" \"sort -r\" outfile"

    # Basic tests
    # "./pipex infile \"cat -e\" \"sort -r\" outfile  # Basic test with 'cat -e' and 'sort -r'"
    # "./pipex infile \"cat\" \"sort\" outfile       # Basic test with 'cat' and 'sort'"

    # Edge cases and error handling
    # "./pipex emptyfile \"cat\" \"sort\" outfile    # Test with an empty input file"
    # "./pipex largefile \"cat\" \"sort\" outfile    # Test with a large input file"
    # "./pipex nosuchfile \"cat\" \"sort\" outfile   # Test with a non-existent input file"
    # "./pipex infile \"nonexistentcmd\" \"sort\" outfile # Test with a non-existent command"
    # "./pipex infile \"cat\" \"\" outfile           # Test with an empty command"
    # "./pipex infile \"cat\" \"sort\" nosuchdir/outfile # Test with a non-existent output path"

    # Special characters and options
    # "./pipex infile \"grep 'pattern'\" \"sort\" outfile # Test with a command containing special characters"
    # "./pipex infile \"cat -n\" \"sort -r\" outfile  # Test with commands having various options"

    # Commands that might fail or behave unusually
    # "./pipex infile \"command-needs-interaction\" \"sort\" outfile # Test with a command that requires interaction"
    # "./pipex infile \"cat\" \"sort\" readonlyfile   # Test with a read-only output file"
    # "./pipex symlink-to-infile \"cat\" \"sort\" outfile # Test with a symbolic link as input"

    # Unicode tests
    # "./pipex unicodefile \"cat\" \"sort\" outfile   # Test with a file containing Unicode characters"

    # Stress and prolonged usage
    # "./pipex infile \"cat\" \"sort\" outfile        # Repeated test for stress analysis"

    # Handling interrupts and signals
    # "./pipex infile \"sleep 10\" \"sort\" outfile   # Test with a command that can be interrupted"
)

# Function to run a command with Valgrind and log the output
run_valgrind() {
    local logfile="$1"
    local command="$2"
    eval "valgrind --leak-check=full $command" > "$logfile" 2>&1
}

# Main loop to process each command
for cmd in "${commands[@]}"; do
    echo "Running: $cmd"
    # Generate log filename
    logfilename="logs/$(echo "$cmd" | sed 's/[^a-zA-Z0-9]/_/g').log"
    # Ensure the logs directory exists
    mkdir -p logs
    # Call run_valgrind with the command
    run_valgrind "$logfilename" "$cmd"
done

echo "Tests completed."


