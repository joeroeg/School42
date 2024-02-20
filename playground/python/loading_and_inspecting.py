import pandas as pd

# Loading and Inspecting Data
def load_and_inspect():
    # Load an Excel file into a DataFrame
    df = pd.read_excel('./SuperStore.xlsx')

    # Print the first 5 rows of the DataFrame
    print("First 5 rows of the DataFrame:")
    print(df.head())

    # Print the last 5 rows of the DataFrame
    print("\nLast 5 rows of the DataFrame:")
    print(df.tail())
    return df

# Data Cleaning
def data_cleaning(df):
    # Check for missing values
    print("\nChecking for missing values:")
    print(df.isnull().sum())

    # Drop rows with any missing values
    df_cleaned = df.dropna()
    print("\nRows with missing values have been dropped.")

    return df_cleaned

# Data Analysis
def data_analysis(df):
    # Summary statistics for numerical columns
    print("\nSummary statistics for numerical columns:")
    print(df.describe())

    # Unique values in a categorical column, example 'Category'
    print("\nUnique values in 'Category' column:")
    print(df['Region'].unique())

    # Count of unique values in 'Category'
    print("\nCount of unique values in 'Category' column:")
    print(df['Region'].value_counts())

# Main function to run the grouped tasks
def main():
    # Load and inspect data
    df = load_and_inspect()

    # Clean data
    df_cleaned = data_cleaning(df)

    # Analyze data
    data_analysis(df_cleaned)

if __name__ == "__main__":
    main()
