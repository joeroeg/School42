import numpy as np
import plotly.graph_objects as go
from noise import pnoise3

# Parameters for the 3D Perlin noise
size = 64
scale = 20.0
octaves = 4
persistence = 0.5
lacunarity = 2.0

# Generate 3D Perlin noise
cloud = np.zeros((size, size, size))
for x in range(size):
    for y in range(size):
        for z in range(size):
            cloud[x, y, z] = pnoise3(x / scale, y / scale, z / scale, octaves, persistence, lacunarity)

# Normalize data for better visualization
cloud_normalized = (cloud - cloud.min()) / (cloud.max() - cloud.min())

# Prepare data for 3D visualization
x, y, z = np.indices(cloud_normalized.shape)
x, y, z = x.flatten(), y.flatten(), z.flatten()
values = cloud_normalized.flatten()

# Filter based on density to reduce points
threshold = 0.5  # Adjust for denser or sparser visualization
mask = values > threshold
x, y, z, values = x[mask], y[mask], z[mask], values[mask]

# Create a scatter plot for interactive visualization
fig = go.Figure(data=go.Scatter3d(
    x=x,
    y=y,
    z=z,
    mode='markers',
    marker=dict(
        size=2,
        color=values,
        colorscale='Plasma',  # Choose your favorite color map
        opacity=0.8
    )
))

# Customize layout
fig.update_layout(
    scene=dict(
        xaxis=dict(title="X"),
        yaxis=dict(title="Y"),
        zaxis=dict(title="Z")
    ),
    title="Interactive Interstellar Cloud"
)

fig.show()
