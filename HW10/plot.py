#!/usr/bin/python3

import matplotlib.pyplot as plt

plt.plotfile('time_altitude.csv', delimiter = ' ', cols = (0, 1), names = ('Time, Seconds', 'Altitude, Meters'))

plt.title('ECE 331, HW10, Problem 4')

plt.show()
