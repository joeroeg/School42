import pandas as pd

# Step 1: Read the CSV files into DataFrames
file1 = "file1.csv"
file2 = "file2.csv"

df1 = pd.read_csv(file1)
df2 = pd.read_csv(file2)

# Step 2: Merge the DataFrames based on the 'id' column
merged_df = pd.merge(df1, df2, on="id", how="outer")

# Step 3: Handle missing data or duplicates if needed
# Example: Filling NaN values with empty strings or dropping duplicates
merged_df = merged_df.fillna("")
merged_df = merged_df.drop_duplicates(subset="id")

# Step 4: Save the merged data to a new CSV file
merged_df.to_csv("merged_data.csv", index=False)
