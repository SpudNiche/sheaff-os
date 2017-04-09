import matplotlib.pyplot as plt

plt.plotfile('time_altitude.csv', delimiter = ' ', cols = (0, 1), names = ('Time, Seconds', 'Altitude, Feet'))

plt.title('ECE 331, HW10, Problem 4')

plt.show()
