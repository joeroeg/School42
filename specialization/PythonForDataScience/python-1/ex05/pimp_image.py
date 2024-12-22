import numpy as np


def ft_invert(array) -> np.array:
    """Inverts the color of the image received."""
    return 255 - array


def ft_red(array) -> np.array:
    """Keeps only the red color of the image received."""
    red_mask = np.zeros_like(array)
    red_mask[:, :, 0] = array[:, :, 0]
    return red_mask


def ft_green(array) -> np.array:
    """Keeps only the green color of the image received."""
    green_mask = np.zeros_like(array)
    green_mask[:, :, 1] = array[:, :, 1]
    return green_mask


def ft_blue(array) -> np.array:
    """Keeps only the blue color of the image received."""
    blue_mask = np.zeros_like(array)
    blue_mask[:, :, 2] = array[:, :, 2]
    return blue_mask


def ft_grey(array) -> np.array:
    """Converts the image received to greyscale."""
    return array[:, :, 0] / 1
