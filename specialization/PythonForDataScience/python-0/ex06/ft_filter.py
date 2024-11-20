"""Filter function."""


def ft_filter(func, lst):
    """Filter function."""
    return [x for x in lst if func(x)]


"""
**List Comprehension Summary**

It takes two arguments:
    func: A function (in this case, a lambda).
    lst: A list of elements to filter.

It iterates over each element (x) in lst.
For each element, it applies func(x).
If func(x) evaluates to True, x is included in the result.
If func(x) evaluates to False, x is excluded.
The result is a new list with only the elements for which func(x) is True.
"""

# ages = [5, 12, 17, 18, 24, 32]

# def myFunc(x):
#     """Function to filter adults."""
#     return x >= 18

# adults = ft_filter(myFunc, ages)
# for x in adults:
#     print(x)
