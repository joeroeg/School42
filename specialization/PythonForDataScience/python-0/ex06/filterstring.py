"""Takes str and an int and returns words that are longer than the int."""

import sys
from ft_filter import ft_filter


def main():
    """Takes str and an int and returns words that are longer than the int."""
    try:
        assert len(sys.argv) == 3
    except AssertionError:
        print("AssertionError: the arguments are bad")
        sys.exit(1)

    try:
        int(sys.argv[2])
    except ValueError:
        print("AssertionError: the arguments are bad")
        sys.exit(1)

    n = int(sys.argv[2])
    words = sys.argv[1].split(" ")
    print(ft_filter(lambda word: len(word) > n, words))


if __name__ == "__main__":
    main()
