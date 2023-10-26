# Define the strncpy function to copy up to n characters from src to dest
def strncpy(dest, src, n):
    dest[:n] = src[:n]  # Copy the first n characters from src to dest
    return dest  # Return the modified dest

# Initialize the source string and destination bytearray
source = "Hello, world!"
destination = bytearray(13)  # A bytearray of length 13 to hold the destination

# Print the source and destination before the copy operation
print("Before")
print("     Source:", source)
print("Destination:", destination)

# Determine the minimum length to copy (lesser of source and destination lengths)
n = min(len(source), len(destination))

# Perform the copy operation
result = strncpy(destination, source.encode(), n)

# Decode the result back to a string and print it
result_str = result.decode()
print("\nAfter")
print("     Source:", source)
print("Destination:", result_str)
