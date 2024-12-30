import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import odeint
from matplotlib.animation import FuncAnimation

# Physical parameters
g = 9.81
L1, L2 = 0.2, 1.0
m1, m2 = 0.5, 1.0
theta1, theta2 = np.pi / 2, np.pi / 2 + 0.01  # Slight perturbation
omega1, omega2 = 0.0, 0.0

# Time
dt = 0.01
t_max = 20
t = np.linspace(0, t_max, int(t_max / dt))

# Equations of motion
def derivatives(state, t):
    theta1, omega1, theta2, omega2 = state
    delta = theta2 - theta1
    den1 = (m1 + m2) * L1 - m2 * L1 * np.cos(delta) ** 2
    den2 = (L2 / L1) * den1

    dydt = np.zeros_like(state)
    dydt[0] = omega1
    dydt[1] = ((m2 * g * np.sin(theta2) * np.cos(delta) -
                m2 * np.sin(delta) * (L2 * omega2 ** 2 + L1 * omega1 ** 2 * np.cos(delta)) -
                (m1 + m2) * g * np.sin(theta1)) / den1)
    dydt[2] = omega2
    dydt[3] = (((m1 + m2) * (L1 * omega1 ** 2 * np.sin(delta) - g * np.sin(theta2) + g * np.sin(theta1) * np.cos(delta)) +
                m2 * L2 * omega2 ** 2 * np.sin(delta) * np.cos(delta)) / den2)
    return dydt

# Solve
state0 = [theta1, omega1, theta2, omega2]
trajectory = odeint(derivatives, state0, t)

# Extract positions
x1 = L1 * np.sin(trajectory[:, 0])
y1 = -L1 * np.cos(trajectory[:, 0])
x2 = x1 + L2 * np.sin(trajectory[:, 2])
y2 = y1 - L2 * np.cos(trajectory[:, 2])

# Animation
fig, ax = plt.subplots()
ax.set_xlim(-2.5, 2.5)
ax.set_ylim(-2.5, 2.5)
ax.set_aspect('equal')
line, = ax.plot([], [], 'o-', lw=2)
trace_x, trace_y = [], []

def update(frame):
    trace_x.append(x2[frame])
    trace_y.append(y2[frame])
    ax.plot(trace_x, trace_y, 'r-', lw=0.5)  # Path trace
    line.set_data([0, x1[frame], x2[frame]], [0, y1[frame], y2[frame]])
    return line,

ani = FuncAnimation(fig, update, frames=len(t), interval=dt * 1000, blit=True)
plt.show()
