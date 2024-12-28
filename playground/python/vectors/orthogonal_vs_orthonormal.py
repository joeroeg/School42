# import numpy as np
# import matplotlib.pyplot as plt

# # Define two vectors
# vector1 = np.array([1, 2])
# vector2 = np.array([-2, 1])  # Orthogonal to vector1 (dot product = 0)

# # Normalize the vectors (to make them orthonormal)
# vector1_norm = vector1 / np.linalg.norm(vector1)
# vector2_norm = vector2 / np.linalg.norm(vector2)

# # Plot the original vectors
# plt.figure(figsize=(8, 8))
# plt.quiver(0, 0, vector1[0], vector1[1], angles='xy', scale_units='xy', scale=1, color='blue', label='Vector 1')
# plt.quiver(0, 0, vector2[0], vector2[1], angles='xy', scale_units='xy', scale=1, color='red', label='Vector 2')

# # Plot the normalized vectors
# plt.quiver(0, 0, vector1_norm[0], vector1_norm[1], angles='xy', scale_units='xy', scale=1, color='green', linestyle='dotted', label='Vector 1 (normalized)')
# plt.quiver(0, 0, vector2_norm[0], vector2_norm[1], angles='xy', scale_units='xy', scale=1, color='purple', linestyle='dotted', label='Vector 2 (normalized)')

# plt.axhline(0, color='black', linewidth=0.5)
# plt.axvline(0, color='black', linewidth=0.5)
# plt.grid()
# plt.xlim(-3, 3)
# plt.ylim(-3, 3)
# plt.gca().set_aspect('equal', adjustable='box')
# plt.legend()
# plt.title("Orthogonal and Orthonormal Vectors")
# plt.show()


