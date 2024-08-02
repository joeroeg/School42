num = [1, 2, 3, 4, 5]

print('')
for i in num:
    if i == 3:
        print('Found!')
        break
    print(i)

print('')
for i in num:
    if i == 3:
        print('Found!')
        continue
    print(i)

print('')
for i in num:
    for letter in 'abc':
        print(i, letter)

print('')
for i in range(10):
    print(i)

print('')
for i in range(1, 10):
    print(i)

print('')
for i in range(1, 10, 2):
    print(i)

print('')
for i in range(10, 0, -1):
    print(i)

print('')
x = 0
while x < 10:
    print(x)
    x += 1

print('')
x = 0
while x < 10:
    if x == 5:
        break
    print(x)
    x += 1

print('')
x = 0
while x < 10:
    x += 1
    if x == 5:
        continue
    print(x)

print('')
x = 0
while x < 10:
    x += 1
    if x == 5:
        break
    print(x)
else:
    print('Done!')

print('')

# loop through dictionary
user = {
    'name': 'John',
    'age': 25,
    'email': 'jhon@mail.com'
}

for key, value in user.items():
    print(key, value)

print('')

for key in user.keys():
    print(key)

print('')

for value in user.values():
    print(value)

print('')

# loop through string
for letter in 'hello':
    print(letter)

print('')

# loop through list
for i in [1, 2, 3, 4, 5]:
    print(i)

print('')

# loop through tuple
for i in (1, 2, 3, 4, 5):
    print(i)

print('')

# loop through set
for i in {1, 2, 3, 4, 5}:
    print(i)

print('')

# loop through range
for i in range(5):
    print(i)

print('')

# loop through enumerate

for i, letter in enumerate('hello'):
    print(i, letter)

print('')

# loop through zip
names = ['John', 'Doe', 'Jane']

for i, j in zip(range(1, 4), names):
    print(i, j)
