"""Load an image from a file and return it as a numpy array."""

from PIL import Image
import numpy as np
import sys


def ft_load(path: str) -> np.ndarray:
    """Load an image from a file and return it as a numpy array."""

    # Load the image
    img = np.asarray(Image.open(path))

    return img
