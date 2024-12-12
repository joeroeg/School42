import pandas as pd

# Create a MultiIndex
arrays = [
    ['A', 'A', 'B', 'B'],
    [1, 2, 1, 2]
]

multi_index = pd.MultiIndex.from_arrays(arrays, names=('letter', 'number'))

# Create a DataFrame with MultiIndex
df = pd.DataFrame({
    'value': [10, 20, 30, 40]
}, index=multi_index)

print(df)

# Accessing data using the MultiIndex
print("\nAccessing data using the MultiIndex:")
print(df.loc['A'])

# Concatenating DataFrames with MultiIndex
df1 = df.loc['A']
df2 = df.loc['B']

result = pd.concat([df1, df2], keys=['A', 'B'])
print("\nConcatenated DataFrame:")
print(result)
