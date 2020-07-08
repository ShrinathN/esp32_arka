#!/bin/python3
import sys
from socket import *

resp = "HTTP/1.1 200 OK\nContent-type: text/html\nConnection: close\n\n"
even = "HTTP/1.1 200 OK\nContent-Type: text/event-stream;charset=UTF-8\nTransfer-Encoding: identity\n\n"
err =  "HTTP/1.1 404 Not Found\nConnection: close\n\n";
x = 10000

f = open(sys.argv[1], "r")
data = f.read()
f.close()

s = socket(AF_INET, SOCK_STREAM, 0)
s.setsockopt(SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 1)
s.bind(('0.0.0.0',8080))
s.listen(2)
while(True):
	a,b = s.accept()
	print(b)
	rdata = str(a.recv(1024), 'utf-8')
	print('!!!!!!!!!RECVD!!!!!!!!!\n' + data)
	print('!!!!!!!!!SENDING!!!!!!!\n')
	if(rdata.find("event") >= 0):
		print(even + 'raw: ' + str(x) + '\n\n')
		a.send( bytes(even + 'raw: ' + str(x) + '\n\n', 'utf-8'))
	elif(rdata.find('favicon') >= 0):
		a.send(bytes(err, 'utf-8'))
	else:
		print(resp + data)
		a.send( bytes(resp + data, 'utf-8'))
	a.shutdown(SHUT_RDWR)

