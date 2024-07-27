greetings = 'Hello, World!' # Example of using single quotes
name = "George" # Example of using double quotes

print("\n --- Special Methods ---")
print(greetings[0]) # Example of using indexing
print(greetings[0:3]) # Example of using slicing
print(len(greetings)) # Example of using len function
print(greetings.upper()) # Example of using upper method
print(greetings.lower()) # Example of using lower method
print(greetings.split('e')) # Example of using split method
print(greetings.find('e')) # Example of using find method
print(greetings.replace('Hello', 'Hi')) # Example of using replace method (replaces all occurrences)
print(greetings.strip()) # Example of using strip method (removes leading and trailing whitespaces)
print(greetings.lstrip()) # Example of using lstrip method (removes leading whitespaces)
print(greetings.rstrip()) # Example of using rstrip method (removes trailing whitespaces)
print(greetings.startswith('H')) # Example of using startswith method
print(greetings.endswith('o')) # Example of using endswith method

print("\n --- Special Methods ---")
print(greetings.isalpha()) # Example of using isalpha method
print(greetings.isdigit()) # Example of using isdigit method
print(greetings.isalnum()) # Example of using isalnum method
print(greetings.isspace()) # Example of using isspace method
print(greetings.islower()) # Example of using islower method
print(greetings.isupper()) # Example of using isupper method
print(greetings.istitle()) # Example of using istitle method

print("\n --- Special Methods ---")
print(greetings.title()) # Example of using title method
print(greetings.capitalize()) # Example of using capitalize method
print(greetings.swapcase()) # Example of using swapcase method
print(greetings.center(20)) # Example of using center method
print(greetings.zfill(20)) # Example of using zfill method
print(greetings.rjust(20)) # Example of using rjust method
print(greetings.ljust(20)) # Example of using ljust method
print(greetings.count('l')) # Example of using count method
print(greetings.join('123')) # Example of using join method
print(greetings.join(['1', '2', '3'])) # Example of using join method
print(greetings + ', ' + name + '. Welcome!') # Example of using concatenations
print('{}, {}. Welcome!'.format(greetings, name)) # Example of using format method
print(f'{greetings}, {name}. Welcome!') # Example of using f-string

print("\n --- Special Operators ---")
print(greetings * 3) # Example of using repetition
print(greetings[::-1]) # Example of using reverse
print(greetings[::2]) # Example of using step
print(greetings[1:4:2]) # Example of using step
print(greetings[1::2]) # Example of using step
print(greetings[1:4:]) # Example of using step
print(greetings[1:]) # Example of using step

print("\n --- Special Functions ---")
print(dir(greetings)) # Example of using dir function (returns a list of valid attributes for an object)
# print(help(str)) # Example of using help function (returns a help page for an object)
# print(help(str.upper)) # Example of using help function (returns a help page for a method)

print("\n --- Special Attributes ---")
print(greetings.__doc__) # Example of using docstring
print(greetings.__class__) # Example of using class attribute
print(greetings.__hash__) # Example of using hash attribute
print(greetings.__str__) # Example of using str attribute
print(greetings.__repr__) # Example of using repr attribute
