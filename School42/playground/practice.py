def strjoin(delimiter, string_array):
    return delimiter.join(string_array)

# Example usage
input_array = ["apple", "banana", "cherry"]
delimiter = ", "
result = strjoin(delimiter, input_array)
for x in input_array:
    print(result)  # Output: "apple, banana, cherry"
