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
