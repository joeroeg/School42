from load_image import ft_load
from pimp_image import ft_invert, ft_red, ft_green, ft_blue, ft_grey
import matplotlib.pyplot as plt

array = ft_load("landscape.jpeg")
print("The shape of the image is:", array.shape)
print(array)
plt.imshow(array)
plt.show()

print(ft_invert.__doc__)
print(ft_invert(array))
print("The shape of the image is:", ft_invert(array).shape)
plt.imshow(ft_invert(array))
plt.show()

print(ft_red.__doc__)
print(ft_red(array))
print("The shape of the image is:", ft_red(array).shape)
plt.imshow(ft_red(array))
plt.show()

print(ft_green.__doc__)
print(ft_green(array))
print("The shape of the image is:", ft_green(array).shape)
plt.imshow(ft_green(array))
plt.show()

print(ft_blue.__doc__)
print(ft_blue(array))
print("The shape of the image is:", ft_blue(array).shape)
plt.imshow(ft_blue(array))
plt.show()


print(ft_grey.__doc__)
print(ft_grey(array))
print("The shape of the image is:", ft_grey(array).shape)
plt.imshow(ft_grey(array), cmap="gray")
plt.show()
