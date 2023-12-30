#!/bin/bash

# Compile your C program and name the output as 'your_program'
gcc -o your_program pipex.c

# Check if compilation was successful
if [ ! -f "./your_program" ]; then
    echo "Compilation failed or your_program is not found."
    exit 1
fi

# Create a temporary directory and move the compiled program there
temp_dir=$(mktemp -d)
cp ./your_program "$temp_dir/your_program"
cd $temp_dir

# Function to test a command sequence
test_command_sequence() {
    sequence=("$@")
    echo "Testing command sequence: ${sequence[@]}"

    # Create empty output files before running commands
    touch output_your_program.txt output_shell.txt

    # Run the sequence with your program
    ./your_program "${sequence[@]}" > output_your_program.txt

    # Create the pipeline command
    pipeline_command=""
    for arg in "${sequence[@]}"; do
        pipeline_command+="$arg "
    done

    # Run the pipeline command with eval
    eval $pipeline_command > output_shell.txt

    # Display the outputs for manual comparison
    echo "---- Your Program Output ----"
    cat output_your_program.txt
    echo "---- Shell Output ----"
    cat output_shell.txt

    # Compare the outputs
    if diff output_your_program.txt output_shell.txt > /dev/null; then
        echo "Success: Output matches."
    else
        echo "Failure: Output differs."
    fi
    echo ""
}

# Test sequences
test_command_sequence infile cat sort outfile
# Additional test sequences can be uncommented as needed

# Clean up
cd ..
rm -r $temp_dir
