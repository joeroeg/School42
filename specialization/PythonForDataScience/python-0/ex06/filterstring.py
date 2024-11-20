"""Takes str and an int and returns words that are longer than the int."""

import sys
from ft_filter import ft_filter


def main():
    """Takes str and an int and returns words that are longer than the int."""
    try:
        assert len(sys.argv) == 3, "the arguments are bad"
        n = int(sys.argv[2])
        words = sys.argv[1].split(" ")
        print(ft_filter(lambda word: len(word) > n, words))

    except (AssertionError, ValueError) as e:
        print(f"AssertionError: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()
