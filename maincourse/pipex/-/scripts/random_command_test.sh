#!/bin/bash

# Options for the cat, sort, and grep commands
cat_options=("-b" "-e" "-n" "-s" "-t" "-u" "-v")
sort_options=("-b" "-d" "-f" "-n" "-r" "-u")
grep_options=("-i" "-v" "-c" "-n")  # Updated grep options

# Filename for the random numbers file
random_numbers_file="random_numbers.txt"

# Function to generate a file with random numbers
generate_random_numbers_file() {
    local number_count=100  # Number of random numbers to generate
    echo "Generating $number_count random numbers in $random_numbers_file..."
    > "$random_numbers_file"  # Clear the file content if it already exists
    for i in $(seq 1 $number_count); do
        echo $((RANDOM)) >> "$random_numbers_file"
    done
}

# Function to generate a random command with a specified number of options
generate_random_command() {
    local options=("${!1}")
    local number_of_options=${#options[@]}
    local option_count=$2
    local cmd=$3
    local used_indexes=()

    for (( i=0; i<option_count; i++ )); do
        local random_index
        repeat=true

        # Ensure unique option selection
        while $repeat; do
            repeat=false
            random_index=$((RANDOM % number_of_options))

            for j in "${used_indexes[@]}"; do
                if [ "$j" -eq "$random_index" ]; then
                    repeat=true
                    break
                fi
            done
        done

        used_indexes+=("$random_index")
        cmd+=" ${options[$random_index]}"
    done

    # Append the filename to the cat command
    if [[ "$cmd" =~ ^cat ]]; then
        cmd+=" $random_numbers_file"
    fi

    # Generate a random number pattern for grep command
    if [[ "$cmd" =~ ^grep ]]; then
        local grep_pattern=$((RANDOM % 10000))  # Random number as pattern
        cmd+=" \"$grep_pattern\""
    fi

    echo "$cmd"
}

# Generate the random numbers file
generate_random_numbers_file

# Directory for script and temporary outputs
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
temp_dir="$script_dir/temp_commands"
mkdir -p "$temp_dir"
echo "Temporary directory for commands: $temp_dir"

# Number of options to test with each command
num_cat_options=1
num_sort_options=1
num_grep_options=1

# Generate and execute random commands
for i in {1..5}; do  # Adjust the count as needed
    cat_cmd=$(generate_random_command cat_options[@] "$num_cat_options" "cat")
    sort_cmd=$(generate_random_command sort_options[@] "$num_sort_options" "sort")
    grep_cmd=$(generate_random_command grep_options[@] "$num_grep_options" "grep")
    full_cmd="$cat_cmd | $sort_cmd | $grep_cmd"
    output_file="$temp_dir/output_$i.txt"
    echo "Executing: $full_cmd"
    eval "$full_cmd" > "$output_file" 2>&1
    echo "Output saved in: $output_file"
done

echo "Random cat, sort, and grep commands executed. Check $temp_dir for outputs."
