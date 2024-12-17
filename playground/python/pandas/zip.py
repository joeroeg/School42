import pandas as pd

rows = [
    (1, "Alice", 25),
    (2, "Bob", 30),
    (3, "Charlie", 28)
]

columns = ["id", "name", "age"]

# Convert each row into a dictionary
chunk_dicts = [dict(zip(columns, row)) for row in rows]
print(chunk_dicts)

# Convert the list of dictionaries into a DataFrame
df = pd.DataFrame(chunk_dicts)
print(df)
