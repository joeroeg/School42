#!/bin/bash

# Manual checks
# 1. Run the program
# 2. Add 8 contacts
# 3. Search for a contact with an index that does not exist
# 4. Exit the program
# 5. Use signal to exit the program (Ctrl + C) and check if the program exits correctly

# Search
# 1. The text must be right-aligned.
# 2. If the text is longer than the column, it must be truncated and the last displayable character must be replaced by a dot (’.’).
# 3. Check valid index with multiple 0s  (e.g. Enter the index of the contact: 0000)


PROGRAM="./phonebook"
$PROGRAM << EOF
ADD
1
1
1
1
1
ADD
2
2
2
2
2
ADD
3
3
3
3
3
ADD
4
4
4
4
4
ADD
5
5
5
5
5
ADD
6
6
6
6
6
ADD
7
7
7
7
7
ADD
8
8
8
8
8
ADD
Michaelllll
Jacksonnnnn
MJJJJJJJJJJ
1234567890
Thrillerrrr
SEARCH
0
EOF
