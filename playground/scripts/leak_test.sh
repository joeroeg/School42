#!/bin/bash

# Array of test commands
declare -a commands=(
    # Basic tests
    "./pipex infile \"cat\" \"sort\" outfile"
    "./pipex infile \"cat -e\" \"sort -r\" outfile"

    # Commands as NULL or Empty Strings
    "./pipex infile \"cat\" \"\" outfile" # empty 2nd command
    "./pipex infile \"\" \"sort\" outfile" # empty 1st command
    "./pipex infile \"NULL\" \"\" outfile" # invalid 1st command
    "./pipex infile \"\" \"\" outfile" # empty commands
    # Still reachable
    "./pipex infile \"NULL\" \"NULL\" outfile" # invalid 1st and 2nd command
    "./pipex infile \"NULL\" \"sort\" outfile" # invalid 1st command
    "./pipex infile \"cat\" \"NULL\" outfile" # invalid 2nd command

    # Invalid Options or Commands
    "./pipex infile \"cat -e\" \"sort -invalid\" outfile" # invalid option for sort
    "./pipex infile \"cat -invalid\" \"sort -r\" outfile" # invalid option for cat
    # Still reachable
    "./pipex infile \"cat -e\" \"error -r\" outfile" # invalid command for 2nd command
    "./pipex infile \"error -e\" \"sort -r\" outfile" # invalid command for 1st command


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

echo "Testing complete. Starting log analysis."

# Valgrind log analysis script

LOG_DIR="logs"
OUTPUT_FILE="memory_leak_summary.txt"
verbose=0

# Process command-line arguments
while getopts "v" opt; do
  case $opt in
    v) verbose=1 ;;
    *) echo "Usage: $0 [-v]" >&2
       exit 1 ;;
  esac
done

# Get current date/time
current_date=$(date "+%Y-%m-%d %H:%M:%S")

# Prompt for user input regarding changes
read -p "Enter description of changes made: " changes

# Initialize output file with table headers if file doesn't exist
if [ ! -f $OUTPUT_FILE ]; then
    echo "Date/Time | Changes | Definitely Lost | Indirectly Lost | Still Reachable | LogFile" > $OUTPUT_FILE
    # Echo the headers to terminal as well
    echo "Date/Time | Changes | Definitely Lost | Indirectly Lost | Still Reachable | LogFile"
fi

# Function to analyze a single log file
analyze_log_file() {
    local file=$1

    # Extract information about memory leaks
    local leaks=$(grep -E 'definitely lost|indirectly lost' $file | grep -v '0 bytes in 0 blocks')
    local still_reachable=$(grep 'still reachable' $file | grep -v '0 bytes in 0 blocks')

    # Check if verbose is off and there are no leaks
    if [ $verbose -eq 0 ] && [ -z "$leaks" ] && [ -z "$still_reachable" ]; then
        return
    fi

    # Prepare table row
    local dl=$(echo "$leaks" | grep 'definitely lost' | cut -d: -f2 | xargs || echo "No leaks")
    local il=$(echo "$leaks" | grep 'indirectly lost' | cut -d: -f2 | xargs || echo "No leaks")
    local sr=$(echo "$still_reachable" | cut -d: -f2 | xargs || echo "No leaks")
    local row="$current_date | $changes | $dl | $il | $sr | $file"

    # Echo to terminal and append to file
    echo $row
    echo $row >> $OUTPUT_FILE
}

# Process each log file
for file in $LOG_DIR/*.log; do
    analyze_log_file $file
done

echo "Log analysis completed. Summary saved in $OUTPUT_FILE."

