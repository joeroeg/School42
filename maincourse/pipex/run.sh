#!/bin/bash

# Executing the command
./pipex_bonus infile "cat -e" "grep "r"" "sort -r" outfile
./pipex_bonus here_doc 5 "cat -e" "sort -r" outfile

# test with 2 cmd
# ./pipex_bonus infile "cat -e" "sort -r" outfile # test with no options
# valgrind --leak-check=full  ./pipex_bonus infile "cat -e" "sort -r" outfile

# test with 3 cmd
# ./pipex_bonus infile "cat -e" "grep "r"" "sort -r" outfile
# valgrind --leak-check=full  ./pipex_bonus infile "cat -e" "grep "r"" "sort -r" outfile


# here_doc test case
# ./pipex_bonus here_doc EOF "cat -e" "sort -r" outfile
# valgrind ./pipex_bonus here_doc EOF "cat -e" "sort -r" outfile
# valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes ./pipex_bonus here_doc EOF "cat -e" "sort -r" outfile

