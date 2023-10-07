equations = [
    "-3.01x + -16.83",
    "-4.24x + 4.36",
    "-9.37x + 5.68",
    "4.88x + -2.29",
    "1.82x + 9.52"
]

def parse_equation(equation):
    parts = equation.split('x')
    m = float(parts[0])
    b = float(parts[1].split('+')[1])
    return m, b

def evaluate_equation(equation, x_value):
    m, b = parse_equation(equation)
    y = m * x_value + b
    return y

x_value = 2.0  # Example x value

for equation in equations:
    y_value = evaluate_equation(equation, x_value)
    print(f"For equation '{equation}', when x = {x_value}, y = {y_value:.2f}")
