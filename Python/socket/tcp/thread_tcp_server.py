from socket import *
from time import ctime
from threading

HOST = '127.0.0.1'
PORT = 8000
BUFSIZE = 1024
ADDR = (HOST,PORT)

sockfd = socket(AF_INET,SOCK_STREAM,0)

sockfd.bind(ADDR)

sockfd.listen(5)

def connect1(connfd,addr):
    print 'connect',addr
    while True:
        c = connfd.recv(BUFSIZE)
        print c
        if c = '\r\n':
            break
        connfd.sendall('[%s]\n'%ctime())
    connfd.close()

while True():
    print 'waiting'
    connfd,addr = sockfd.accept()

    t1 = threading.Thread(name = '',target = connect1,args = (connfd,addr))
    t1.setDaemon(1)
    t1.start()

sockfd.close()
