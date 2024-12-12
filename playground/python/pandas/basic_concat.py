"""
objs
a sequence or mapping of Series or DataFrame objects
If a mapping is passed, the sorted keys will be used as the keys argument, unless it is passed, in which case the values will be selected (see below).
Any None objects will be dropped silently unless they are all None in which case a ValueError will be raised.
"""

# Example 1: Concatenating two DataFrames
# Let's create two DataFrames and concatenate them using the pd.concat() function:
import pandas as pd

# Create the first DataFrame
data1 = {
    "A": [1, 2, 3],
    "B": [4, 5, 6],
    "C": [7, 8, 9]
}


df1 = pd.DataFrame(data1)

# Create the second DataFrame
data2 = {
    "A": [10, 11, 12],
    "B": [13, 14, 15],
    "C": [16, 17, 18]
}


df2 = pd.DataFrame(data2)

# Concatenate the two DataFrames
result = pd.concat([df1, df2], keys=["data1", "data2"])
print("\nConcatenated DataFrame:")
print(result)


# Print index of the concatenated DataFrame
print("\nIndex of the concatenated DataFrame:", result.index)
