from socket import *
from time import ctime

HOST = '127.0.0.1'
PORT = 3000
BUFSIZE = 1024
ADDR = (HOST,POST)

sockfd = socket(AF_INET,SOCK_DGRAM,0)
sockfd.bind(ADDR)


while True:
    print 'waiting for message...'
    dataa,addr = sockfd.recvfrom(BUFSIZE)
    sockfd.sendto()
