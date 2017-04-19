#!/usr/bin/python3

import urllib.request

print(urllib.request.urlopen("http://www.google.com").read())
