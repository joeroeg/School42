#!/bin/bash

# Test mandatory part
# ./pipex infile "cat -e" "wc -l" outfile
# valgrind --leak-check=full ./pipex infile "cat -e" "grep "l"" outfile
# valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./pipex infile "cat -e" "grep "l"" outfile

# Test bonus part
# ./pipex_bonus infile "cat -e" "grep "r"" "sort -r" outfile
# valgrind --leak-check=full  ./pipex_bonus infile "cat -e" "grep "r"" "sort -r" outfile

# here_doc test case
# ./pipex_bonus here_doc EOF "cat -e" "sort -r" outfile
# valgrind --leak-check=full --show-leak-kinds=all ./pipex_bonus here_doc EOF "cat -e" "grep "l"" outfile

# error case
# valgrind --leak-check=full ./pipex infile "ca " "gre "l"" outfile
# valgrind --leak-check=full ./pipex_bonus infile "ca " "gre "r"" "sor -r" outfile
# valgrind --leak-check=full ./pipex_bonus here_doc EOF "cat -e" "gre "l"" outfile
# valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./pipex_bonus here_doc EOF "cat -e" "gre "l"" outfile
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./pipex_bonus here_doc EOF "" "" outfile

