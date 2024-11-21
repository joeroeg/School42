"""Load an image from a file and return it as a numpy array."""

from PIL import Image
import numpy as np


def ft_load(path: str) -> np.ndarray:
    """Load an image from a file and return it as a numpy array."""
    try:
        img = Image.open(path)
        return np.asarray(img)
    except Exception as e:
        print(f"Error: {e}")

    return None
