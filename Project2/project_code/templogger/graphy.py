#!/usr/bin/python3

# Author: Nicholas LaJoie
# Source: https://matplotlib.org/users/pyplot_tutorial.html
    # Numerous Stack Overflow pages
    # matplotlib.org

import sqlite3 as sq
import time
import datetime

import numpy as np
import matplotlib.pyplot as plt
import matplotlib.dates as dt

# Plot the SQLite3 data using matplotlib
dpath = '/home/pi/templogger/temp.db'

while True:
    # Connect to database
    conn = sq.connect(dpath) # Connect to the TEST database
    c = conn.cursor()        # Cursor can execute sqlite commands

    # SQL Commands
    query = "SELECT * FROM templog ORDER BY datetime DESC LIMIT 1440"

    # Arrays to hold temp and dates
    temp = []
    dates = []

    # Iterate through data in sqlite database
    for row in c.execute(query):
        line = str(row).replace(')','').replace('(','').replace(' ','')
        splitInfo = line.split(',')
        t = int(splitInfo[1]) * 60
        d = datetime.datetime.fromtimestamp(float(t)).strftime('%c') # Converts epoch time to date string
        temp.append(splitInfo[0])
        dates.append(d)

    # Reverse data order to correct it
    temp.reverse()
    dates.reverse()

    # Set up for plotting
    axes = plt.gca()
    axes.set_xlim([0, 1439])
    axes.set_ylim([20, 90])
    datelabels = (dates[0], dates[205], dates[410], dates[615], dates[820], dates[1025], dates[1230], dates[1439])
    axes.set_xticklabels(datelabels, rotation = 45, ha = 'right')

    # Plot and save figure
    plt.figure(1)
    plt.tight_layout()
    plt.grid()
    plt.title('ECE 331 - Project 2 - Temperature Logger')
    plt.xlabel('Date/Time')
    plt.ylabel('Temperature, Degrees Farenheit')
    plt.plot(temp)
    fig = plt.gcf()

    # Save image so it can be sent to the webpage
    fig.savefig('/var/www/html/temp.png', frameon = 'True')
    plt.clf()

    # Clean up
    conn.close()

    # Delay
    print "Complete"
    time.sleep(60) # Update every minute
