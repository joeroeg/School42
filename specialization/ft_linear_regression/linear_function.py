import matplotlib.pyplot as plt
import numpy as np

# Define the linear functions
def linear_function_1(x):
    return 2 * x + 1

# def linear_function_2(x):
    # return -0.5 * x + 3

# def linear_function_3(x):
#     return x - 4

# Generate x values
x = np.linspace(-10, 10, 400)

# Generate y values
y1 = linear_function_1(x)
# y2 = linear_function_2(x)
# y3 = linear_function_3(x)

# Plot the functions
plt.figure(figsize=(10, 6))
plt.plot(x, y1, label='y = 2x + 1')
# plt.plot(x, y2, label='y = -0.5x + 3')
# plt.plot(x, y3, label='y = x - 4')

# Add labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title('Graph of Linear Functions')
plt.axhline(0, color='black',linewidth=0.5)
plt.axvline(0, color='black',linewidth=0.5)
plt.grid(color = 'gray', linestyle = '--', linewidth = 0.5)
plt.legend()

# Show the plot
plt.show()
