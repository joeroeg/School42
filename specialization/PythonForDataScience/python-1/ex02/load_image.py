"""Load an image from a file and return it as a numpy array."""


import numpy as np


def ft_load(path: str) -> np.ndarray:
    """Load an image from a file and return it as a numpy array."""
    return np.load(path)
