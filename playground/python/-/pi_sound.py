import numpy as np
import sounddevice as sd

# Parameters
fs = 44100  # Sampling frequency (samples per second)
duration = 5.0  # Duration of the tone in seconds
frequency = np.pi * 100  # Frequency of the sine wave (π * 100 Hz)

# Generate the sine wave
t = np.linspace(0, duration, int(fs*duration), endpoint=False)
wave = np.sin(2 * np.pi * frequency * t)

# Play the sound
sd.play(wave, fs)
sd.wait()
