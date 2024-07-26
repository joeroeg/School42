# Generate example of operations on tuples

# Create a tuple
t = (1, 2, 3, 4, 5)
print(t)

# Access the first element
print(t[0])

# Access the last element
print(t[-1])

# Access the second to last element
print(t[-2])

# Access the first two elements
print(t[0:2])

# Access the last three elements
print(t[-3:])

# Access every second element
print(t[::2])

# Access every second element starting from the second element
print(t[1::2])

# Access every second element starting from the second to last element
print(t[-2::-2])

# Delete the tuple
del t

# Create a tuple
t = (1, 2, 3, 4, 5)
print(t)

# Get the length of the tuple
print(len(t))

# Concatenate the tuple
t = t + (6, 7, 8)
print(t)

# Repeat the tuple
t = t * 2
print(t)

# Check if an element is in the tuple
print(3 in t)

# Check if an element is not in the tuple
print(9 not in t)

# Get the index of an element
print(t.index(3))

# Count the number of occurrences of an element
print(t.count(3))

