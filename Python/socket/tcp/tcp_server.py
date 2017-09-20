from socket import *
from time import ctime
from multiprocessing import Process,Pool

HOST = '127.0.0.1'
PORT = 4003
BUFSIZE = 1024
ADDR = (HOST,PORT)

sockfd = socket(AF_INET,SOCK_STREAM,0)

sockfd.bind(ADDR)

sockfd.listen(5)


while True:
    print 'waiting for connection...'
    connfd,addr = sockfd.accept()
    print 'connected from:',addr
    while True:
        data = connfd.recv(BUFSIZE)
        if  data == '\r\n':
            break
        print data
        connfd.sendall('[%s]\n'%ctime())

connfd.close()
sockfd.close()
