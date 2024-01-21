#!/bin/bash

# Test mandatory part
# ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
# ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG

# ARG="4" "67" "3" "87" "23"; ./push_swap $ARG | wc -l
# ARG="4" "67" "3" "87" "23"; ./push_swap $ARG | ./checker_Mac $ARG

# Memory leak test
# valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --trace-children=yes ./push_swap 4 67 3 87 23 | ./checker_Mac 4 67 3 87 23

# error case
