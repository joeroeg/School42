import matplotlib.pyplot as plt
from matplotlib.patches import PathPatch
from matplotlib.path import Path
import matplotlib.patches as patches
import numpy as np


# Define the first 1000 digits of pi
pi_digits = "314159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360652605463072"

# Function to draw a bezier curve between two points
def draw_bezier(ax, p0, p1, c, lw):
    verts = [p0, ((p0[0]+p1[0])/2, (p0[1]+p1[1])/2), p1]
    codes = [Path.MOVETO, Path.CURVE3, Path.CURVE3]
    path = Path(verts, codes)
    patch = patches.PathPatch(path, facecolor='none', lw=lw, edgecolor=c, alpha=0.7)
    ax.add_patch(patch)

# Create a figure and a circular plot
fig, ax = plt.subplots(figsize=(12,12))
circle = plt.Circle((0.5, 0.5), 0.4, color='black', fill=False)
ax.add_artist(circle)

# Divide the circle into 10 segments and label them
for i in range(10):
    angle = 2 * np.pi * i / 10
    x = 0.5 + 0.4 * np.cos(angle)
    y = 0.5 + 0.4 * np.sin(angle)
    ax.add_artist(plt.Circle((x, y), 0.025, color=plt.cm.tab10(i)))
    ax.text(x, y, str(i), color='white', ha='center', va='center', fontsize=12)

# Connect the digits of pi with bezier curves
for i in range(len(pi_digits) - 1):
    angle1 = 2 * np.pi * int(pi_digits[i]) / 10
    angle2 = 2 * np.pi * int(pi_digits[i + 1]) / 10
    x1 = 0.5 + 0.4 * np.cos(angle1)
    y1 = 0.5 + 0.4 * np.sin(angle1)
    x2 = 0.5 + 0.4 * np.cos(angle2)
    y2 = 0.5 + 0.4 * np.sin(angle2)
    lw = 2 if i == 762 else 0.5  # Highlight the Feynman point
    draw_bezier(ax, (x1, y1), (x2, y2), plt.cm.tab10(int(pi_digits[i])), lw)

# Highlight the Feynman point with a circle
feynman_point = plt.Circle((0.5, 0.5 + 0.4), 0.04, color='purple', fill=True)
ax.add_artist(feynman_point)

# Set limits and aspect
ax.set_xlim(0, 1)
ax.set_ylim(0, 1)
ax.set_aspect('equal')
ax.axis('off')  # Turn off the axis

plt.show()
