import pandas as pd

print('How do you create a pandas Series from a list?')
data = [10, 20, 30, 40, 50]
series = pd.Series(data)
print(series, '\n')


print('How do you create a pandas Series with a custom index?')
data = [10, 20, 30, 40, 50]
index = ['a', 'b', 'c', 'd', 'e']
series = pd.Series(data, index=index)
print(series, '\n')


print('How do you create a pandas DataFrame from a dictionary?')
data = {'A': [1, 2, 3], 'B': [4, 5, 6], 'C': [7, 8, 9]}
df = pd.DataFrame(data)
print(df, '\n')


print('How do you create a pandas DataFrame from a list of lists?')
data = [[1, 4, 7], [2, 5, 8], [3, 6, 9]]
columns = ['A', 'B', 'C']
df = pd.DataFrame(data, columns=columns)
print(df, '\n')


print("How do you create a pandas DataFrame from a list of dictionaries?")
data = [{'A': 1, 'B': 4, 'C': 7},
        {'A': 2, 'B': 5, 'C': 8},
        {'A': 3, 'B': 6, 'C': 9}]
df = pd.DataFrame(data)
print(df, '\n')


# How do you access a column in a pandas DataFrame?
print("How do you access a column in a pandas DataFrame?")
data = {'A': [1, 2, 3], 'B': [4, 5, 6], 'C': [7, 8, 9]}
df = pd.DataFrame(data)
print(df['A'], '\n')


# How do you access a specific row in a pandas DataFrame by index label?
print("How do you access a specific row in a pandas DataFrame by index label?")
data = {'A': [1, 2, 3], 'B': [4, 5, 6], 'C': [7, 8, 9]}
df = pd.DataFrame(data, index=['X', 'Y', 'Z'])
print(df.loc['X'], '\n')
# print(df.loc[0], '\n') # KeyError: 'the label [0] is not in the [index]'
print(df.iloc[0], '\n')

# How do you reset the index of a DataFrame to the default integer index and print the first row
print("How do you reset the index of a DataFrame to the default integer index")
df.reset_index(drop=True, inplace=True)
print(df.loc[0], '\n') # 0 is the default integer index
