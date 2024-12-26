def square(x: int | float) -> int | float:
    """Return the square of x."""
    return x * x


def pow(x: int | float) -> int | float:
    """Return x raised to the power of x."""
    return x ** x


def outer(x: int | float, function) -> object:
    """Return the result of calling the function with the argument x."""
    count = 0

    def inner() -> float:
        nonlocal x
        nonlocal count
        count = function(x)
        x = count
        return count
    return inner
