import sys

def main():
    if len(sys.argv) == 1:
        print("What is the text to count?")
        text = input()
    text = sys.argv[1]
    print("The text contains", len(text), "characters:")

    upper = 0
    lower = 0
    digit = 0
    space = 0
    punctuation = 0

    for i in range(len(text)):
        if text[i].isalpha():
            if text[i].isupper():
                upper = upper + 1
            else:
                lower = lower + 1
        elif text[i].isdigit():
            digit = digit + 1
        elif text[i].isspace():
            space = space + 1
        elif text[i] != text[i].isalnum():
            punctuation = punctuation + 1

    print(upper, "upper letters")
    print(lower, "lower letters")
    print(punctuation, "punctuation marks")
    print(space, "spaces")
    print(digit, "digits")

if __name__ == "__main__":
    main()
