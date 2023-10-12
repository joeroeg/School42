def strncpy(dest, src, n):
    dest[:n] = src[:n]
    return dest

# Example usage
source = "Hello, world!"
destination = bytearray(13)  # A bytearray to hold the destination

# Copy at most 11 characters from source to destination
n = min(len(source), len(destination))
result = strncpy(destination, source.encode(), n)

# Convert the result back to a string for printing
result_str = result.decode()
print("Destination:", result_str)
