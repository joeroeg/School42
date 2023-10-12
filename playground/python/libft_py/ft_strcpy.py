def strncpy(dest, src, n):
    dest[:n] = src[:n]
    return dest

source = "Hello, world!"
destination = bytearray(13)  # A bytearray to hold the destination

print("Before")
print("     Source:", source)
print("Destination:", destination)
# Copy at most 11 characters from source to destination
n = min(len(source), len(destination))
result = strncpy(destination, source.encode(), n)

# Convert the result back to a string for printing
result_str = result.decode()
print("\nAfter")
print("     Source:", source)
print("Destination:", result_str)
