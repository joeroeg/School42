language = 'Python'

if language == 'Python':
    print('Language is Python')
elif language == 'Java':
    print('Language is Java')
else:
    print('No match')

# and
user = 'Admin'
logged_in = True

if user == 'Admin' and logged_in:
    print('Admin Page')

# or
if user == 'Admin' or logged_in:
    print('Admin Page')

# not
if not logged_in:
    print('Please log in')
else:
    print('Welcome')

# is
a = [1, 2, 3]
b = [1, 2, 3]

print(id(a))
print(id(b))

print(a == b) # True
print(a is b) # False (because they are stored in different memory locations)

b = a
print(a is b) # True (because they are stored in the same memory location)

print(id(a))
print(id(b))

print(id(a) == id(b))

# False Values:
# False
# None
# Zero of any numeric type
# Any empty sequence. For example, '', (), [].
# Any empty mapping. For example, {}.
# In general, any object which is considered empty.

