import pandas as pd

# Load a CSV file into a DataFrame
# df = pd.read_csv('path/to/your/file.csv')

# Load an Excel file into a DataFrame
df = pd.read_excel('./SuperStore.xlsx')


# Print the first 5 rows of the DataFrame
# print(df.head())

# Print the last 5 rows of the DataFrame
# print(df.tail())

# Print the shape of the DataFrame
# print(df.shape)

# Print the columns of the DataFrame
# print(df.columns)

# Print the data types of the DataFrame
# print(df.dtypes)

# Print the summary statistics of the DataFrame
# print(df.describe())

# Print the number of missing values in the DataFrame
# print(df.isnull().sum())

# Print the number of unique values in the DataFrame
# print(df.nunique())

# Print the value counts of a column in the DataFrame
# print(df['City'].value_counts())

# Print the value counts of a column in the DataFrame as a percentage
# print(df['City'].value_counts(normalize=True) * 100)

# Print the value counts of a column in the DataFrame as a percentage with 2 decimal places
# print(df['City'].value_counts(normalize=True).mul(100).round(2))

# Print the value counts of a column in the DataFrame as a percentage with 2 decimal places and a dollar sign
# print(df['City'].value_counts(normalize=True).mul(100).round(2).astype(str) + '%')

# Print the value counts of a column in the DataFrame as a percentage with 2 decimal places and a dollar sign
# print(df['City'].value_counts(normalize=True).mul(100).round(2).astype(str) + '%')

# Print the value counts of a column in the DataFrame as a percentage with 2 decimal places and a dollar sign
# print(df['City'].value_counts(normalize=True).mul(100).round(2).astype(str) + '%')
