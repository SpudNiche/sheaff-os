# TempLogger - Nicholas LaJoie, ECE 331 Project 2
Logs the temperature once a minute and displays a plot of the last 24
hours of data on a publicly accessible URL. 

# Setup

## SQLite3 Database 

The database needs to hold the time, date, and temperature data. The data
is logged once a minute. 

Setting up a database: 
>> sudo apt-get install sqlite3 // Install SQLite 3
>> sqlite3 temp.db // Create a new db

Table Name: templog 
Layout: temp (in farenheit) | datetime (epoch, in minutes) 

Successfully implemented sending i2c data, date, and time from python script to database

## Python Script

See script i2c.py for details (well commented) 

## Plot

Used python to plot and save an image that will be served to the webpage via a simple php index page

## Comments

Due to limited time (my fault), this project did not quite go as planned. As it stands, the way the plot is 
served to the webpage is a pretty "hacked up" way to do it. I'm using python to grab data, plot it, save an image,
and then pass it to a php script to post in on the webpage. Really simple, but not ideal. 

## Future Work

1. Make it look a LOT better
2. Have the plotting python script itself serve the webpage (need to do some lighttdp config - cgi, etc.) 
3. Improve the code in general. There are a lot of areas for improvement! 
