#!/usr/bin/env python

# Author: Nicholas LaJoie
# ECE 331 - Project 2
# Description: A test script to generate random temp data for plotting
# Sources: dos.python.org/2/library/sqlite3.html
    # https://randomnerdtutorials.com/sqlite-database-on-a-raspberry-pi/
    # http://stackoverflow.com/questions/6304808/how-to-pass-tuple-as-argument-in-python
    # http://stackoverflow.com/questions/209513/convert-hex-string-to-int-in-python
    # https://linux.die.net/man/8/i2cget
    # http://sharats.me/the-ever-useful-and-neat-subprocess-module.html#running-via-the-shell
    # http://www.raspberry-projects.com/pi/programming-in-python/i2c-programming-in-python/using-the-i2c-interface-2
    # http://effbot.org/librarybook/datetime.htm

import time             # For date and time calculations
import random
import sqlite3 as sq    # Interact with SQLite3 Database
import subprocess       # Run i2cget

# Initializations
conn = sq.connect('/home/pi/templogger/test.db') # Connect to the temp database
c = conn.cursor() # Cursor can execute sqlite commands

for i in range (24896188, 24896188 + (24*60)):
    faren = random.randrange(50, 90)

    # Insert data into preexisting table using a tuple
    data = ((faren, i))

    c.execute('INSERT INTO templog(temperature, datetime) values(?, ?);', data)

    # print "{} {} {}".format(faren, curday, yesterday) # DEBUGGING

# Clean up
conn.commit() # Commit changes to database
conn.close() # Close the connection
