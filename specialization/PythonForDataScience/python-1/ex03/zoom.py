"""Zoom the image."""
from load_image import ft_load
import numpy as np
import matplotlib.pyplot as plt


def main():
    """Zoom the image."""
    img = ft_load("animal.jpeg")
    img_array = np.asarray(img)
    print("The shape of image is: ", img_array.shape)
    print(img_array)

    gray_img = img.convert('L')
    gray_array = np.asarray(gray_img)
    zoom_img = gray_array[100:500, 400:800]
    print("TNew shape after slicing: ", zoom_img.shape)
    print(zoom_img)

    plt.imshow(zoom_img, cmap='gray')
    plt.axis('off')
    plt.show()


if __name__ == "__main__":
    try:
        main()
    except Exception as msg:
        print(msg)
        exit(1)
