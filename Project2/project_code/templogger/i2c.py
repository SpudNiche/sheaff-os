#!/usr/bin/env python

# Author: Nicholas LaJoie
# ECE 331 - Project 2
# Description: Grab i2c temp data and store in SQLite 3 database
# Sources: dos.python.org/2/library/sqlite3.html
    # https://randomnerdtutorials.com/sqlite-database-on-a-raspberry-pi/
    # http://stackoverflow.com/questions/6304808/how-to-pass-tuple-as-argument-in-python
    # http://stackoverflow.com/questions/209513/convert-hex-string-to-int-in-python
    # https://linux.die.net/man/8/i2cget
    # http://sharats.me/the-ever-useful-and-neat-subprocess-module.html#running-via-the-shell
    # http://www.raspberry-projects.com/pi/programming-in-python/i2c-programming-in-python/using-the-i2c-interface-2
    # http://effbot.org/librarybook/datetime.htm

import time             # For date and time calculations
import sqlite3 as sq    # Interact with SQLite3 Database
import subprocess       # Run i2cget

# Initializations
conn = sq.connect('/home/pi/templogger/temp.db') # Connect to the temp database
c = conn.cursor() # Cursor can execute sqlite commands

# Get i2c data
temp = subprocess.check_output(['/usr/sbin/i2cget','-y','1','0x48','0','b'])
cel = int(temp,16) # Convert to decimal, celsius
faren = (cel*(9.0/5.0)) + 32

# Get date and time
curday = time.time()
curday = int(curday / 60)

# Insert data into preexisting table using a tuple
data = ((faren, curday))

c.execute('INSERT INTO templog(temperature, datetime) values(?, ?);', data)

# Remove values more than 24 hours old
yesterday = time.time() - (24*60*60)
yesterday = int(yesterday / 60)

old = (yesterday,)
c.execute('DELETE FROM templog WHERE datetime <= ?;', old)

print "{} {} {}".format(faren, curday, yesterday) # DEBUGGING

# Clean up
conn.commit() # Commit changes to database
conn.close() # Close the connection
