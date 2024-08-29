"""Module for encoding a string to Morse code."""
import sys


def string_to_morse(string):
    """Converts a string to Morse code."""
    NESTED_MORSE = {
        'A': '.-',
        'B': '-...',
        'C': '-.-.',
        'D': '-..',
        'E': '.',
        'F': '..-.',
        'G': '--.',
        'H': '....',
        'I': '..',
        'J': '.---',
        'K': '-.-',
        'L': '.-..',
        'M': '--',
        'N': '-.',
        'O': '---',
        'P': '.--.',
        'Q': '--.-',
        'R': '.-.',
        'S': '...',
        'T': '-',
        'U': '..-',
        'V': '...-',
        'W': '.--',
        'X': '-..-',
        'Y': '-.--',
        'Z': '--..',
        '1': '.----',
        '2': '..---',
        '3': '...--',
        '4': '....-',
        '5': '.....',
        '6': '-....',
        '7': '--...',
        '8': '---..',
        '9': '----.',
        '0': '-----',
        ' ': '/'
    }

    morse = ""

    for char in string.upper():
        if char not in NESTED_MORSE:
            raise ValueError(f"Invalid character in the string: '{char}'")

    for char in string.upper():
        morse += NESTED_MORSE[char] + " "

    morse = morse.strip()
    return morse


def main():
    """Main function for the module."""
    try:
        assert len(sys.argv) == 2, "Usage: python sos.py <string>"
    except AssertionError as e:
        print(e)
        sys.exit(1)

    input_string = sys.argv[1]

    try:
        result = string_to_morse(input_string)
        print(result)
        sys.exit(0)
    except ValueError as e:
        print(e)
        sys.exit(1)


if __name__ == "__main__":
    main()
