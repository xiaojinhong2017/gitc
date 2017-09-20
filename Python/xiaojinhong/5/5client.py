from socket import *
from time import ctime
import sys


HOST = sys.argv[1]
PORT = int(sys.argv[2])
BUFSIZE = 1024
ADDR = (HOST,PORT)

sockfd = socket(AF_INET,SOCK_STREAM,0)
sockfd.connect(ADDR)


while True:
    print '''------------------------------
****** 1.login 2.resign******
------------------------------'''
    data = raw_input('>')
    if not data:
        break
    sockfd.send(data)

    data = sockfd.recv(BUFSIZE)
    print data
    if data == '1':
        print 'please login'
    if data == '2':
        print 'please resign'
    user = raw_input('>')
    sockfd.send(user)
sockfd.close()
