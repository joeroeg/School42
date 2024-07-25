fruits = []
fruits.append('orange')
fruits.append('apple')
fruits.append('pear')
fruits.append('banana')
fruits.append('kiwi')
fruits.append('apple')
fruits.append('banana')
fruits.extend(['grape', 'peach', 'mango'])
# print(fruits)

fruits.remove('banana')
fruits.remove('banana')
# print(fruits)

fruits.insert(3, 'banana')
fruits.insert(6, 'banana')
# print(fruits)

fruits.pop()
fruits.pop()
fruits.pop()
fruits = fruits + ['grape', 'peach', 'mango']
# print(fruits)

fruits.sort()
# print(fruits)

fruits.reverse()
# print(fruits)

# fruits = list(set(fruits)) # remove duplicates and does not maintain order
# print(fruits)

fruits = [x for i, x in enumerate(fruits) if x not in fruits[:i]] # remove duplicates and maintain order
# print(fruits)

fruits = list(dict.fromkeys(fruits)) # remove duplicates and maintain order
# print(fruits)

# remove duplicates and maintain order using a loop

fruits = ['orange', 'apple', 'pear', 'banana', 'kiwi', 'apple', 'banana', 'grape', 'peach', 'mango', 'banana', 'banana', 'grape', 'peach',]
unique_fruits = []
for fruit in fruits:
    if fruit not in unique_fruits:
        unique_fruits.append(fruit)

print(fruits)
print(unique_fruits)
