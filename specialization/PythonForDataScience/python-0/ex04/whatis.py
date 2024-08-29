"""Check if the argument is an integer and print if it is even or odd.

ValueError
Raised when a function receives correct type but an wrong value.

AssertionError
Raised when an assert statement fails.
"""

import sys

if len(sys.argv) == 1:
    sys.exit(1)

try:
    assert len(sys.argv) == 2
except AssertionError:
    print("AssertionError: more than one argument is provided")
    sys.exit(1)

try:
    int(sys.argv[1])
except ValueError:
    print("AssertionError: argument is not an integer")
    sys.exit(1)

n = int(sys.argv[1])

if n % 2 == 0:
    print("I'm Even.")
else:
    print("I'm Odd.")
