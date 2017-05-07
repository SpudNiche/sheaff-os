#!/usr/bin/python3
import csv

d = csv.reader(open('predict60.csv'), delimiter=' ');
for row in d:
    print(row[0]+' '+row[1]);
