
def hello_func():
    pass

print(hello_func) # <function hello_func at 0x7f8b1c3b7d08>
print(hello_func()) # None

def hello_func():
    print('Hello Function!')

hello_func() # Hello Function!

def hello_func():
    return 'Hello Function!'

print(hello_func()) # Hello Function!

def hello_func(greeting):
    return '{} Function.'.format(greeting)

print(hello_func('Hi')) # Hi Function.

def hello_func(greeting, name = 'You'):
    return '{} {}.'.format(greeting, name)

print(hello_func('Hi')) # Hi You.
print(hello_func('Hi', name = 'Corey')) # Hi Corey.

# *args and **kwargs are used to pass a variable number of arguments to a function.
def student_info(*args, **kwargs):
    print(args)
    print(kwargs)

student_info('Math', 'Art', name = 'John', age = 22) # ('Math', 'Art') {'name': 'John', 'age': 22}

courses = ['Math', 'Art']
info = {'name': 'John', 'age': 22}

student_info(courses, info) # (['Math', 'Art'], {'name': 'John', 'age': 22}) {}
