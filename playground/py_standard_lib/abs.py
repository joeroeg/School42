import math

def ft_abs(x):
    if x >= 0:
        return x
    else:
        return -x


def abs_value(x):
    if  isinstance(x, (int, float)):
        return x if x >= 0 else -x
    elif isinstance(x, complex):
        return math.sqrt(x.real**2 + x.imag**2)

# Examples
print(abs_value(-5))          # Output: 5
print(abs_value(3.14))        # Output: 3.14
print(abs_value(3 + 4j))      # Output: 5.0
print(abs_value("hello"))     # Output: Unsupported type for abs(): <class 'str'>



