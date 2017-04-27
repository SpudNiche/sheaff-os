#!/usr/bin/python3

# Source: https://matplotlib.org/users/pyplot_tutorial.html

import numpy as np
import matplotlib.pyplot as plt

# Plot sin(x)/x for -10 to 10, x = angle (radians), y = voltage

def f(x):
    return np.sin(x)/x

x1 = np.arange(-10.0, 10.0, 0.1)

# Plot with proper labels

plt.figure(1)
plt.grid()
plt.title('ECE 331, HW12, Problem 5')
plt.xlabel('Angle, Radians')
plt.ylabel('Voltage, V')
plt.plot(x1, f(x1))
plt.show()
