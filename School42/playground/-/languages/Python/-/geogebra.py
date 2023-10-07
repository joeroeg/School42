import numpy as np
from scipy.linalg import solve

# Coefficient matrices and right-hand side vectors
A = np.array([[3.54, -1], [-2, -1]])
b = np.array([-7.88, -10])

intersection_point = solve(A, b)
print("Intersection Point:", intersection_point)
