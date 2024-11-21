"""Tester."""


from load_image import ft_load

try:
    print("The shape of image is: ", ft_load("landscape.jpeg").shape)
    print(ft_load("landscape.jpeg"))
except Exception as e:
    print(f"Error: {e}")
    exit(1)
