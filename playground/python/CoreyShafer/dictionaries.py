
# Dictionaries are unordered mappings for storing objects. Previously we saw how lists store objects in an ordered sequence, dictionaries use a key-value pairing instead.
# This key-value pair allows users to quickly grab objects without needing to know an index location.
# Dictionaries use curly braces and colons to signify the keys and their associated values.
# {'key1':'value1','key2':'value2'}
# So when to choose a list and when to choose a dictionary?
# Dictionaries: Objects retrieved by key name. Unordered and can not be sorted.
# Lists: Objects retrieved by location. Ordered sequence can be indexed or sliced.

student = {'name': 'John', 'age': 25, 'courses': ['Math', 'CompSci']}
print(student)
print(student['name'])
print(student['courses'])
print(student['age'])

# print(student['phone']) # This will throw an error
print(student.get('phone')) # This will return None
print(student.get('phone', 'Not Found')) # This will return 'Not Found'

student['phone'] = '555-5555'
print(student.get('phone', 'Not Found'))

student['name'] = 'Jane'
print(student)

student.update({'name': 'Jane', 'age': 26, 'phone': '555-5555'})
print(student)

del student['age']
print(student)

student['age'] = 25
print(student)

age = student.pop('age')
print(age)

print(len(student))
print(student.keys())
print(student.values())
print(student.items())

for key in student:
    print(key)

