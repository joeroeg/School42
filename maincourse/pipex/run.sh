#!/bin/bash

# Test mandatory part
# ./pipex infile "cat -e" "wc -l" outfile
# valgrind --leak-check=full ./pipex infile "cat -e" "grep "l"" outfile

# Test bonus part
# ./pipex_bonus infile "cat -e" "grep "r"" "sort -r" outfile
# valgrind --leak-check=full  ./pipex_bonus infile "cat -e" "grep "r"" "sort -r" outfile

# here_doc test case
# ./pipex_bonus here_doc EOF "cat -e" "sort -r" outfile
valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus here_doc EOF "cat -e" "grep "l"" outfile

