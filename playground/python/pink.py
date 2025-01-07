import numpy as np
from scipy.signal import lfilter
import soundfile as sf

def generate_pink_noise(duration, sample_rate):
    """
    Generate Pink Noise.

    :param duration: Duration in seconds.
    :param sample_rate: Sample rate in Hz.
    :return: Array of pink noise samples.
    """
    num_samples = duration * sample_rate

    # Generate white noise
    white = np.random.normal(size=num_samples)

    # Apply a filter to create pink noise (1/f distribution)
    # Coefficients derived from a basic 1/f approximation
    b = np.array([0.049922, 0.050612, 0.050612, 0.049922])
    a = np.array([1, -2.494956, 2.017264, -0.522189])
    pink = lfilter(b, a, white)

    # Normalize the pink noise to a desired range (e.g., -1 to 1)
    pink = pink / np.max(np.abs(pink))

    return pink

# Parameters
duration = 5  # seconds
sample_rate = 5000    # Hz

# Generate Pink Noise
pink_noise = generate_pink_noise(duration, sample_rate)

# Save or play the noise (requires additional libraries like soundfile or pyaudio)
sf.write("pink_noise_1.wav", pink_noise, sample_rate)
