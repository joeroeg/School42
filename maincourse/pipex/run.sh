#!/bin/bash

# Executing the command
# ./pipex_bonus infile "cat -e" "echo cmd2 test" outfile
# ./pipex_bonus infile "cat -e" "sort -r" outfile
./pipex_bonus infile "cat -e" "grep "row"" "sort -r" outfile
# ./pipex_bonus infile "ls" "ls" outfile
# ./pipex_bonus infile "cat -e" "sort -r" outfile
# ./pipex_bonus infile "sort" "cat -e" outfile
# ./pipex_bonus here_doc 5 "cat" "sort" outfile
# ./pipex_bonus "ls -l" "cat -e" "grep "p"" "sort -r"


