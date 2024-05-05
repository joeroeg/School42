import matplotlib.pyplot as plt

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

def ulam_spiral(n):
    x, y = 0, 0
    dx, dy = 0, -1
    spiral = {}
    for i in range(n**2):
        if abs(x) == abs(y) or (x > 0 and y == 1 - x) or (x < 0 and y == x):
            dx, dy = -dy, dx
        if is_prime(i + 1):
            spiral[i + 1] = (x, y)
        x, y = x + dx, y + dy
    return spiral

def plot_ulam_spiral(n):
    spiral = ulam_spiral(n)
    plt.figure(figsize=(8, 8))
    plt.scatter([v[0] for v in spiral.values()], [v[1] for v in spiral.values()], c='blue', marker='s')
    plt.gca().invert_yaxis()
    plt.axis('equal')
    plt.axis('off')
    plt.show()

# Generate and plot Ulam spiral for n=101 (101x101 grid)
plot_ulam_spiral(101)
