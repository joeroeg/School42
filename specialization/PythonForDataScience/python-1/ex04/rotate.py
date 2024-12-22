"""Rotate the image."""
from load_image import ft_load
import numpy as np
import matplotlib.pyplot as plt


def transpose_image(img):
    """Transpose the array."""
    transposed = np.zeros((img.shape[1], img.shape[0]), dtype=img.dtype)
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            transposed[j][i] = img[i][j]
    return transposed


def main():
    """Rotate the image."""
    img = ft_load("animal.jpeg")
    img_array = np.asarray(img)
    print("The shape of image is:", img_array.shape)
    print(img_array)

    gray_img = img.convert('L')
    gray_array = np.asarray(gray_img)
    zoom_img = gray_array[100:500, 400:800]
    rotated_img = transpose_image(zoom_img)
    print("New shape after Transpose:", rotated_img.shape)
    print(rotated_img)

    plt.imshow(rotated_img, cmap='gray')
    plt.axis('off')
    plt.show()


if __name__ == "__main__":
    try:
        main()
    except Exception as msg:
        print(msg)
        exit(1)
