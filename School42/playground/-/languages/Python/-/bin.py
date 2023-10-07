# How to convert a decimal number to its binary representation in Python
# We pass the decimal number to the bin() function, which returns a string containing the binary representation of the number.
# The string starts with the prefix 0b, which indicates that the number is in binary format.
# Then, we use the print() function to display the binary representation of the number to the console.
# The output of this code will be:
# The binary representation of 10 is 0b1010
# To summrize the above:
# The bin() function is used to convert a decimal number to its binary representation.
# The bin() function returns a string containing the binary representation of the number.
# The string starts with the prefix 0b, which indicates that the number is in binary format.


decimal_number = 10
binary_number = bin(decimal_number)

print(f"The binary representation of {decimal_number} is {binary_number}")
