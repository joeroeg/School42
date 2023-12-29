#!/bin/bash

# Options for the cat and sort commands
cat_options=("-b" "-e" "-n" "-s" "-t" "-u" "-v")
sort_options=("-b" "-d" "-f" "-n" "-r" "-u")

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

    echo "$cmd"
}

# Directory for script and temporary outputs
script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
temp_dir="$script_dir/temp_commands"
mkdir -p "$temp_dir"
echo "Temporary directory for commands: $temp_dir"

# Number of options to test with each command
num_cat_options=2
num_sort_options=2

# Generate and execute random commands
for i in {1..5}; do  # Adjust the count as needed
    cat_cmd=$(generate_random_command cat_options[@] "$num_cat_options" "cat")
    sort_cmd=$(generate_random_command sort_options[@] "$num_sort_options" "sort")
    full_cmd="$cat_cmd infile | $sort_cmd"
    output_file="$temp_dir/output_$i.txt"
    echo "Executing: $full_cmd"
    eval "$full_cmd" > "$output_file" 2>&1  # Assuming 'infile' is the input file
    echo "Output saved in: $output_file"
done

echo "Random cat and sort commands executed. Check $temp_dir for outputs."
