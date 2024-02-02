import numpy as np
import matplotlib.pyplot as plt

def newton_fractal(f, df, roots, xlim=(-2, 2), ylim=(-2, 2), width=800, height=600, max_iter=30, tol=1e-6):
    # Create a grid of complex numbers
    x = np.linspace(xlim[0], xlim[1], width)
    y = np.linspace(ylim[0], ylim[1], height)
    X, Y = np.meshgrid(x, y)
    Z = X + 1j * Y

    # Initialize the image
    image = np.zeros(Z.shape, dtype=np.uint8)

    # Iterate over each point in the grid
    for i in range(max_iter):
        # Avoid division by zero
        nonzero = df(Z) != 0
        # Apply Newton's method
        Z[nonzero] -= f(Z[nonzero]) / df(Z[nonzero])

        # Check for convergence to any of the roots
        for root_idx, root in enumerate(roots):
            close_to_root = np.isclose(Z, root, atol=tol)
            image[close_to_root] = (root_idx + 1) * 255 // len(roots)

    return image

# Define the function and its derivative
f = lambda z: z**3 - 1
df = lambda z: 3*z**2

# Define the roots of the function
roots = [1, -0.5 + np.sqrt(3)/2j, -0.5 - np.sqrt(3)/2j]

# Generate the Newton fractal
fractal_image = newton_fractal(f, df, roots)

# Display the fractal
plt.figure(figsize=(10, 8))
plt.imshow(fractal_image, extent=(-2, 2, -2, 2))
plt.colorbar()
plt.title('Newton Fractal for $f(z) = z^3 - 1$')
plt.xlabel('Re(z)')
plt.ylabel('Im(z)')
plt.show()
cd
