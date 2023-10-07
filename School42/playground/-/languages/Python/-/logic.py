import random

def generate_random_sequence(length, logic_func):
    sequence = []
    for _ in range(length):
        sequence.append(logic_func())
    return sequence

def hide_values(sequence, indexes_to_hide):
    hidden_sequence = sequence.copy()
    for index in indexes_to_hide:
        hidden_sequence[index] = "?"
    return hidden_sequence

def main():
    sequence_length = 10
    random_sequence = generate_random_sequence(sequence_length, random_logic)
    
    # Choose some indexes to hide
    indexes_to_hide = random.sample(range(sequence_length), sequence_length // 3)
    hidden_sequence = hide_values(random_sequence, indexes_to_hide)
    
    print("Guess the hidden values in the sequence:")
    print(hidden_sequence)
    
    guesses = []
    for index in indexes_to_hide:
        guess = int(input(f"Guess the value at position {index}: "))
        guesses.append(guess)
    
    print("Actual Sequence:", random_sequence)
    print("Your Guesses:", guesses)

# Example logic function: generate a random number between 1 and 10
def random_logic():
    return random.randint(1, 10)

if __name__ == "__main__":
    main()
