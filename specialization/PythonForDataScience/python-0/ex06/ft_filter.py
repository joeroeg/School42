"""Filter function."""


def ft_filter(func, lst):
    """Filter function."""
    return [x for x in lst if func(x)]

# ages = [5, 12, 17, 18, 24, 32]

# def myFunc(x):
#     """Function to filter adults."""
#     return x >= 18

# adults = ft_filter(myFunc, ages)
# for x in adults:
#     print(x)
