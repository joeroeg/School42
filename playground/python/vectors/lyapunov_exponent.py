import numpy as np

# Example: Calculate Lyapunov Exponent for two slightly different initial conditions
def lyapunov_exponent(delta_theta, delta_omega, t_max=10, dt=0.01):
    t = np.linspace(0, t_max, int(t_max / dt))
    separation = []

    for _ in t:
        # Integrate equations for two slightly perturbed pendulums
        # Calculate separation and store its logarithm
        separation.append(np.log(np.abs(delta_theta)))

        # Update separation (simplified for demonstration)
        delta_theta += delta_omega * dt
        delta_omega += -0.1 * delta_theta * dt

    return np.mean(separation)

exp = lyapunov_exponent(1e-5, 0)
print("Lyapunov Exponent:", exp)
