#!/usr/bin/env python
# -*- coding: utf-8 -*-

import socket
sock = socket.socket()
sock.connect(('localhost', 9090))
while True:
    sock.send(b"Hello!\n")

sock.close()

