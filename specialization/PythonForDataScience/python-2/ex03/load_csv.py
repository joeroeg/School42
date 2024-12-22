import pandas as pd


def load_csv(path: str) -> pd.DataFrame:
    """Load a CSV file from a given path and return a pandas DataFrame."""
    try:
        dataset = pd.read_csv(path)
        if dataset.empty:
            print("Warning: The dataset is empty.")
        print(f"Loading dataset of dimensions {dataset.shape}")
        return dataset
    except FileNotFoundError as e:
        print(f"FileNotFoundError: {e}")
    except pd.errors.EmptyDataError as e:
        print(f"EmptyDataError: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")
    return None
