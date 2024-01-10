#!/bin/bash

# Executing the command
# ./pipex infile "cat -e" "sort" outfile | cat outfile
./pipex infile "cat -e" "sort -r" outfile | cat outfile
