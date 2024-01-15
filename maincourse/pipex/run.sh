#!/bin/bash

# Executing the command

# bonus test case
    # test with 2 cmd
# ./pipex_bonus infile "cat" "sort" outfile # test with no options
# ./pipex_bonus infile "cat -e" "sort -r" outfile # test with no options


    # test with 3 cmd
./pipex_bonus infile "cat -e" "grep "line"" "sort -r" outfile# ./pipex_bonus infile "cat -e" "sort -r" outfile


# here_doc test case
# ./pipex_bonus here_doc EOF "cat -e" "grep "line"" "sort -r" outfile

