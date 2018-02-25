#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket
import time


sock = socket.socket()
sock.bind(('', 9090))
sock.listen(1)
conn, addr = sock.accept()

print ('connected:', addr)

start = time.time()
count = 0;
while True:
    data = conn.recv(2000)
    #udata = data.decode("utf-8")
    if data:
       # print ("data: " + udata)
        end = time.time()
        count = count + 1
        times = end - start
        if(times) > 1:
            break
print('TIME : ', times)
print('COUNT OF MESSAGES: ', count)
print('SPEED: ', count*2000/times, 'bytes/s')

conn.close()
