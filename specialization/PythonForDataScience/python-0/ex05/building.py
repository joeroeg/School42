import sys


def main():
    """ Count the number of characters in a text and display statistics.

    Raises:
        AssertionError: If too many arguments are provided.
    """
    try:
        if len(sys.argv) > 2:
            raise AssertionError("Too many arguments provided.")

        if len(sys.argv) == 1:
            print("What is the text to count?")
            text = sys.stdin.readline()
            if not text:
                text = sys.stdin.read()
        else:
            text = sys.argv[1]

        print("The text contains", len(text), "characters:")

        upper = 0
        lower = 0
        digit = 0
        space = 0
        punctuation = 0

        for char in text:
            if char.isalpha():
                if char.isupper():
                    upper += 1
                else:
                    lower += 1
            elif char.isdigit():
                digit += 1
            elif char.isspace() or char == '\n':
                space += 1
            elif not char.isalnum():
                punctuation += 1

        print(upper, "upper letters")
        print(lower, "lower letters")
        print(punctuation, "punctuation marks")
        print(space, "spaces")
        print(digit, "digits")

    except AssertionError as e:
        print(f"AssertionError: {e}")
        sys.exit(1)


if __name__ == "__main__":
    main()
    # help(main)
