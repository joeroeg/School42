import pandas as pd


def load_csv(path: str) -> pd.DataFrame:
    if path is None:
        raise ValueError("Path is None")
        exit(1)
    pd.read_csv(path)
    if pd.read_csv(path) is None:
        raise ValueError("Path is None")
        exit(1)
    print("Loading dataset dimensions", pd.read_csv(path).shape)
    return pd.read_csv(path)
