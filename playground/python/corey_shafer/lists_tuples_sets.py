
# Lists
# Lists are mutable
# Lists are ordered
# Lists can contain duplicates
# Lists can contain different data types
# Lists are indexed

print('Lists')
# Create a list
courses = ['History', 'Math', 'Physics', 'CompSci']
print(courses)

# List Methods
# Append
courses.append('Art')
print(courses)

# Insert
courses.insert(0, 'Art')
print(courses)

# Extend
courses_2 = ['Art', 'Education']

courses.extend(courses_2)
print(courses)

# Remove
courses.remove('Math')
print(courses)

# Pop
popped = courses.pop()
print(popped)
print(courses)

# Reverse
courses.reverse()
print(courses)

# Sort
courses.sort()
print(courses)

# Sort in reverse
courses.sort(reverse=True)
print(courses)

# Sorted
sorted_courses = sorted(courses)
print(sorted_courses)

# Min (alphabetically)
print(min(courses))

# Max (alphabetically)
print(max(courses))

# Index (returns index of item)
print(courses.index('CompSci'))

# Check if item is in list
print('Art' in courses)

# Count (number of times item appears in list)
for i in courses:
    print(i)

# Enumerate
for index, course in enumerate(courses):
    print(index, course)

# Enumerate with start
for index, course in enumerate(courses, start=1):
    print(index, course)

# Join list items (convert list to string)
course_str = ', '.join(courses)
print(course_str)

# Split string into list (convert string to list)
new_list = course_str.split(', ')
print(new_list)

# Tuples
# Tuples are immutable
# Tuples are faster than lists
# Tuples are used when data should not be changed
# Tuples are used for fixed data
# Tuples are used for performance

print('\nTuples')
# Create a tuple
tuple_1 = ('History', 'Math', 'Physics', 'CompSci')
tuple_2 = tuple_1

print(tuple_1)
print(tuple_2)

# Loop through tuple
for i in tuple_1:
    print(i)

# Sets
# Sets are unordered
# Sets are unindexed
# Sets do not allow duplicates
# Sets are mutable
# Sets are used for membership testing and eliminating duplicates

print('\nSets')
# Create a set
courses_set = {'History', 'Math', 'Physics', 'CompSci'}
print(courses_set)

# Check if item is in set (faster than list or tuple)
print('Math' in courses_set)

# Add item to set
courses_set.add('Art')
print(courses_set)

# Remove item from set
courses_set.remove('Math')
print(courses_set)

# Remove item from set (if item does not exist, does not throw error)
courses_set.discard('Math')
print(courses_set)

# Remove last item from set
popped = courses_set.pop()
print(popped)
print(courses_set)

# Clear set
courses_set.clear()
print(courses_set)

# Set operations
cs_courses = {'History', 'Math', 'Physics', 'CompSci'}
art_courses = {'History', 'Math', 'Art', 'Design'}

# Intersection
print(cs_courses.intersection(art_courses))

# Difference
print(cs_courses.difference(art_courses))

# Union
print(cs_courses.union(art_courses))

# Empty set (cannot use {} to create empty set)
empty_set = set()

# Empty list
empty_list = []
empty_list = list()

# Empty tuple
empty_tuple = ()
empty_tuple = tuple()

# Empty dictionary
empty_dict = {}
empty_dict = dict()
