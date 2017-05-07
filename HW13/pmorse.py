#!/usr/bin/python

m = open("/dev/morse")              # Morse Device
f = open("/usr/share/dict/words")   # Dictionary file

for line in f:
    print line          # Print to stdout
    m.write(line)       # Write to morse device

# Clean up
m.close()
f.close()
