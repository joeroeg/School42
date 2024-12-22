from PIL import Image
import numpy as np


def ft_load(path: str):
    """Load an image from a file and return it as a numpy array."""
    try:
        img = Image.open(path)
        return np.array(img)
    except Exception as e:
        print(f"Error: {e}")
        exit(1)

    return None
