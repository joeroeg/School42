import random

def replace_vowels_with_random(string):
    vowels = "aeiou"
    random_vowels = random.sample(vowels, len(vowels))
    vowel_dict = dict(zip(vowels, random_vowels))

    result = []
    for char in string:
        if char in vowel_dict:
            result.append(vowel_dict[char])
        else:
            result.append(char)

    return ''.join(result)

input_string = "Hello, World!"
output_string = replace_vowels_with_random(input_string)
print(output_string)
