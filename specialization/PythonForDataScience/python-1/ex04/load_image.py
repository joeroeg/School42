"""Load an image from a file and return it as a numpy array."""

from PIL import Image


def ft_load(path: str):
    """Load an image from a file and return it as a numpy array."""
    try:
        img = Image.open(path)
        return img
    except Exception as e:
        print(f"Error: {e}")
        exit(1)

    return None
