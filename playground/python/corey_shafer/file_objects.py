# File Objects


print("Reading the entire file")
f = open('test.txt', 'r')
print(f.name)
print(f.mode)
f.close()

print("\nUsing the context manager")
with open('test.txt', 'r') as f:
    pass
print(f.closed) # the file is closed after the with blocks ends automatically by the context manager

print("\nReading the entire file")
with open('test.txt', 'r') as f:
    f_contents = f.read()
    print(f_contents)


print("\nReading the entire file")
with open('test.txt', 'r') as f:
    f_contents = f.readlines()
    print(f_contents)

print("\nReading line by line")
with open('test.txt', 'r') as f:
    f_contents = f.readline()
    print(f_contents, end='')
    f_contents = f.readline()
    print(f_contents, end='')
    f_contents = f.readline()
    print(f_contents, end='')

print("\nIterating through the file")
with open('test.txt', 'r') as f:
    for line in f:
        print(line, end='')

print("\nReading a certain amount of characters at a time")
with open('test.txt', 'r') as f:
    size_to_read = 1
    f_contents = f.read(size_to_read)
    print(f_contents, end='')
    f_contents = f.read(size_to_read)
    print(f_contents, end='')
    f_contents = f.read(size_to_read)
    print(f_contents, end='')
    f_contents = f.read(size_to_read)
    print(f_contents, end='')
    f_contents = f.read(size_to_read)
    print(f_contents, end='')
    f_contents = f.read(size_to_read)
    print(f_contents, end='')
    f_contents = f.read(size_to_read)
    print(f_contents, end='')
