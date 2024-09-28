"""Test the slicing of lists and 2D arrays."""
# Basic slicing
my_list = [1, 2, 3, 4, 5]
slice_result = my_list[1:4]  # Get the second to fourth elements
print(slice_result)


# Omitting start and stop
my_list = [1, 2, 3, 4, 5]
slice_result = my_list[:3]  # Get the first three elements
print(slice_result)

# Using negative indices
my_list = [1, 2, 3, 4, 5]
slice_result = my_list[-4:-1]  # Get the first three elements
print(slice_result)

# Omitting start and stop with negative indices
my_list = [1, 2, 3, 4, 5]
slice_result = my_list[-3:]  # Get the last three elements
print(slice_result)

# Using step
my_list = [1, 2, 3, 4, 5]
slice_result = my_list[::2]  # Get every second element

# Using negative step
my_list = [1, 2, 3, 4, 5]
slice_result = my_list[::-1]  # Reverse the list
print(slice_result)

# Slicing a 2D array
my_2d_list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
slice_result = my_2d_list[1][1:]  # Get the second row, from the second element
print(slice_result)

# Slicing a 2D array with negative indices
my_2d_list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
slice_result = my_2d_list[-1][:2]  # Get the last row, up to the second element
print(slice_result)

# Slicing a 2D array with negative indices
my_2d_list = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
slice_result = my_2d_list[-1][:2]  # Get the last row, up to the second element
print(slice_result)

matrix = [
    [2, 3, 4],
    [5, 6, 7],
    [8, 9, 10]
]

print(matrix[0][0])

print(matrix[1])  # Extract single row
print([row[1] for row in matrix])  # Extract single column
print([row[::2] for row in matrix[::2]])

for i in range(len(matrix)):
    print(matrix[i][i])

print([[matrix[i][i]] for i in range(len(matrix))])
