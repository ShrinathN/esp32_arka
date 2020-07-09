#!/bin/python3
import sys

f = open(sys.argv[1], "r")
data = f.read()
f.close()

data = data.replace('"', '\\"')
data = data.replace('\t', '')
data = data.replace('\n', '\\n')


print('const char web_page_data[] = "' + data + '";')