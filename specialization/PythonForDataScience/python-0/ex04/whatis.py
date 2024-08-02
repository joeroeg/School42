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

"""
ValueError - Raised when an operation or function receives an argument that has the right type but an inappropriate value, and the situation is not described by a more precise exception such as IndexError.
AssertionError - Raised when an assert statement fails.
"""
