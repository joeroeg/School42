import random
import numpy as np
from scipy.linalg import solve

def generate_linear_equation():
    m = random.uniform(-10, 10)
    b = random.uniform(-20, 20)
    equation = f"y = {m:.2f}x + {b:.2f}"
    return m, b, equation

num_equations = 5

for _ in range(num_equations):
    m, b, equation = generate_linear_equation()
    print("Generated Equation:", equation)

    A = np.array([[m]])  # Coefficient matrix A
    b = np.array([b])    # Right-hand side vector b

    x = solve(A, b)  # Solve Ax = b for x
    print("Solution:", x)
