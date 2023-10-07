import random

def generate_linear_equation():
    m = random.uniform(-10, 10)  # Random slope between -10 and 10
    b = random.uniform(-20, 20)  # Random y-intercept between -20 and 20
    equation = f"y = {m:.2f}x + {b:.2f}"
    return equation

num_equations = 5  # Number of equations to generate

for _ in range(num_equations):
    equation = generate_linear_equation()
    print(equation)
