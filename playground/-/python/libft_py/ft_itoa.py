# Function to count the number of digits in an integer n
def count_digits(n):
    i = 1  # Initialize counter to 1
    n = abs(n)  # Take the absolute value of n to handle negative numbers
    while n // 10:  # Continue as long as n has more than one digit
        i += 1  # Increment counter
        n //= 10  # Remove the last digit from n
    return i  # Return the number of digits

# Function to convert an integer n to a string
def ft_itoa(n):
    input_number = abs(n)  # Take the absolute value of n
    number_length = count_digits(n)  # Get the number of digits in n

    # If n is negative, increase the length by 1 to account for the '-' sign
    if n < 0:
        number_length += 1  

    # Create a list of '0's with length equal to number_length
    output_string = ['0'] * number_length

    # Initialize index to the last position in output_string
    idx = number_length - 1

    # Populate output_string with digits from input_number
    while idx >= 0:
        output_string[idx] = str(input_number % 10)  # Take the last digit of input_number
        input_number //= 10  # Remove the last digit from input_number
        idx -= 1  # Move index one position to the left

    # If n is negative, place a '-' at the first position
    if n < 0:
        output_string[0] = '-'

    # Join the list into a string and return
    return ''.join(output_string)

# Test the code
print(ft_itoa(123))  # Output should be "123"
print(ft_itoa(-123))  # Output should be "-123"
print(ft_itoa(0))  # Output should be "0"
