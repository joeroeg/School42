import bpy
import numpy as np
import math

# Clear existing objects
bpy.ops.object.select_all(action='SELECT')
bpy.ops.object.delete()

# Generate sample data
np.random.seed(42)
x = np.linspace(-3, 3, 15)
y = 2 * x + 1 + np.random.normal(0, 1.5, len(x))

# Create 3D axes
def create_axis(length=10, name='Axis'):
    bpy.ops.curve.primitive_bezier_curve_add()
    axis = bpy.context.object
    axis.data.dimensions = '3D'
    axis.data.bevel_depth = 0.05
    axis.scale = (length, length, length)
    axis.name = name
    return axis

x_axis = create_axis(name='X_Axis')
y_axis = create_axis(name='Y_Axis')
y_axis.rotation_euler.z = math.pi/2

# Create data points as spheres
for xi, yi in zip(x, y):
    bpy.ops.mesh.primitive_uv_sphere_add(radius=0.1, location=(xi, yi, 0))
    bpy.context.object.data.materials.append(bpy.data.materials.new(name="Blue"))
    bpy.context.object.active_material.diffuse_color = (0.1, 0.3, 1, 1)

# Create regression line (initially flat)
bpy.ops.curve.primitive_bezier_curve_add()
regression_line = bpy.context.object
regression_line.data.bevel_depth = 0.03
regression_line.data.materials.append(bpy.data.materials.new(name="Yellow"))
regression_line.active_material.diffuse_color = (1, 0.8, 0.2, 1)

# Animation parameters
m = 0.5  # Initial slope
b = -2   # Initial intercept
final_m = 1.98
final_b = 1.12
frames = 250

# Animate regression line
for frame in range(frames):
    t = frame / frames
    current_m = m + (final_m - m) * t
    current_b = b + (final_b - b) * t

    # Update curve points
    regression_line.data.splines[0].bezier_points[0].co = (-3, current_m*-3 + current_b, 0)
    regression_line.data.splines[0].bezier_points[1].co = (3, current_m*3 + current_b, 0)

    # Insert keyframes
    regression_line.keyframe_insert(data_path="location", frame=frame)

# Add residuals dynamically
for xi, yi in zip(x, y):
    residual = bpy.data.curves.new('Residual', type='CURVE')
    residual.dimensions = '3D'
    spline = residual.splines.new('POLY')
    spline.points.add(1)
    line_obj = bpy.data.objects.new('Residual', residual)
    bpy.context.collection.objects.link(line_obj)

    # Animate residual line
    for frame in range(frames):
        t = frame / frames
        current_m = m + (final_m - m) * t
        current_b = b + (final_b - b) * t
        y_pred = current_m * xi + current_b

        spline.points[0].co = (xi, yi, 0, 1)
        spline.points[1].co = (xi, y_pred, 0, 1)
        line_obj.keyframe_insert(data_path="data.splines[0].points[0].co", frame=frame)
        line_obj.keyframe_insert(data_path="data.splines[0].points[1].co", frame=frame)

# Create animated equation text
def create_animated_text(text, location):
    bpy.ops.object.text_add(location=location)
    text_obj = bpy.context.object
    text_obj.data.body = text
    text_obj.data.align_x = 'CENTER'

    # Animate text updates
    for frame in range(0, frames, 10):
        t = frame / framese
        current_m = m + (final_m - m) * t
        current_b = b + (final_b - b) * t
        text_obj.data.body = f"y = {current_m:.2f}x + {current_b:.2f}"
        text_obj.keyframe_insert(data_path="data.body", frame=frame)

    return text_obj

equation_text = create_animated_text("", (0, 0, 2))

# Set up camera and lighting
bpy.ops.object.camera_add(location=(5, -5, 5))
camera = bpy.context.object
camera.rotation_euler = (math.pi/6, 0, math.pi/4)
bpy.context.scene.camera = camera

bpy.ops.object.light_add(type='SUN', location=(5, -5, 10))

# Configure render settings
bpy.context.scene.render.engine = 'CYCLES'
bpy.context.scene.frame_start = 0
bpy.context.scene.frame_end = frames
bpy.context.scene.render.fps = 24
