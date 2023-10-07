def add(a, b):
    return a + b

result = add(2, 3)
print("Result:", result)

def multiply_by_two(func):
    def wrapper(a, b):
        return func(a, b) * 2
    return wrapper

@multiply_by_two
def add(a, b):
    return a + b

result = add(2, 3)
print("Result:", result)

