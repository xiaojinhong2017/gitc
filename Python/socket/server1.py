from socket import *
from time import sleep
import sys
import os


class FtpServer:
    BUfSIZE = 1024
    def __init__(self,sockfd):
        self.sockfd = sockfd

        def do_get(self,filename):
            try:
                fd = open(filename,'rb')
            except:
                self.sockfd.send('FAIL')
            self.socket.send('OK')

            while True:
                data = fd.readline()
                if not data:
                    break
                self.sockfd.send(data)
                sleep(0.1)
            fd.close()
            print 'get ok'
            return


def main():
    if len(sys.argv) < 3:
        print 'Input valid arg'
        sys.exit(0)

    HOST = sys.argv[1]
    POST = int(sys.argv[2])
    BUFSIZE = 1024
    ADDR = (HOST,POST)

    sockfd = socket(AF_INET,SOCK_STREAM,0)
    sockfd.bind(ADDR)
    sockfd.listen(5)

    while True:
        connfd,addr = sockfd.accept()
        print ('Connected from :',addr)
        data = connfd.recv(BUFSIZE)

        ftp = FtpServer(connfd)
        print ('>>>',data)

        if data[0] == 'G':
            ftp.do_get(data[2:])
        connfd.close()

        sys.exit(0)
    if __name__ =='__main__':
        main()
