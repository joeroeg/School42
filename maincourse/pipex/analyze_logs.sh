#!/bin/bash

LOG_DIR="logs"
OUTPUT_FILE="memory_leak_summary.txt"

# Get current date/time
current_date=$(date "+%Y-%m-%d %H:%M:%S")

# Prompt for user input regarding changes
read -p "Enter description of changes made: " changes

# Initialize output file with table headers if file doesn't exist
if [ ! -f $OUTPUT_FILE ]; then
    echo "Date/Time | Changes | LogFile | Definitely Lost | Indirectly Lost | Still Reachable" > $OUTPUT_FILE
fi

# Function to analyze a single log file
analyze_log_file() {
    local file=$1

    # Extract information about memory leaks
    local leaks=$(grep -E 'definitely lost|indirectly lost' $file | grep -v '0 bytes in 0 blocks')
    local still_reachable=$(grep 'still reachable' $file | grep -v '0 bytes in 0 blocks')

    # Prepare table row
    if [ -z "$leaks" ] && [ -z "$still_reachable" ]; then
        echo "$current_date | $changes | $file | No leaks | No leaks | No leaks" >> $OUTPUT_FILE
    else
        local dl=$(echo "$leaks" | grep 'definitely lost' | cut -d: -f2 | xargs || echo "No leaks")
        local il=$(echo "$leaks" | grep 'indirectly lost' | cut -d: -f2 | xargs || echo "No leaks")
        local sr=$(echo "$still_reachable" | cut -d: -f2 | xargs || echo "No leaks")
        echo "$current_date | $changes | $file | $dl | $il | $sr" >> $OUTPUT_FILE
    fi
}

# Process each log file
for file in $LOG_DIR/*.log; do
    analyze_log_file $file
done

echo "Log analysis completed. Summary saved in $OUTPUT_FILE."
