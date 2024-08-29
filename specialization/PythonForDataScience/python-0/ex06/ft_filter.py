"""Filter function."""


def ft_filter(func, lst):
    """Filter function."""
    return [x for x in lst if func(x)]  # list comprehension


"""
**List Comprehension Summary**

List comprehension is a concise way to create lists in Python. It consists of:

1. Brackets `[]`
2. An expression
3. A `for` clause
4. Optional `for` or `if` clauses

**Key Features:**

* Can create lists with any type of object
* Always returns a new list
* Compact way to process all elements of a list
* Can replace `lambda`, `map()`, `filter()`, and `reduce()` functions

**Example:**

numbers = [1, 2, 3, 4, 5]
double_numbers = [x * 2 for x in numbers]
print(double_numbers)  # [2, 4, 6, 8, 10]
"""

# ages = [5, 12, 17, 18, 24, 32]

# def myFunc(x):
#     """Function to filter adults."""
#     return x >= 18

# adults = ft_filter(myFunc, ages)
# for x in adults:
#     print(x)
