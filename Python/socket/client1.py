from socket import *
from time import ctime,sleep
import sys
import os


class FtpClient:
    BUFSIZE =1024
    def __init__(self,serveraddr):
        self.serveraddr = serveraddr
    def do_get(self,filename):
        fd = open(filename,'wb')
        data = 'G ' +filename

        sockfd = socket(AF_INET,SOCK_STREAM,0)
        sockfd.connect(self.serveraddr)
        sockfd.send(data)
        data = sockfd.recv(self.BUFSIZE)

        if data[0:2] == 'OK':
            while True:
                data = sockfd.recv(self.BUFSIZE)
                if not data :
                    break
                fd.write(data)
            else:
                print ('get %s fail!'%filename)
                sockfd.close()
                fd.close()
                return
            print ('get %s ok!'%filename)
            sockfd.close()
            fd.close()
            return


def main():
    if len(sys.argv) < 3:
        print 'Plaese input valid arg'
        sys.exit(0)

    HOST = sys.argv[1]
    POST = int(sys.argv[2])
    ADDR = (HOST,POST)

    ftp = FtpClient(ADDR)

    while True:
        print '-----------------get filename--------------'
        print '-----------------quit--------------'
        print 'Input command >>'

        data = raw_input()
        if data[0] =='g':
            ftp.do_get(data[4:])
        elif data[0] == 'q':
            sys.exit(0)
        else:
            continue
    sys.exit(0)

if __name__ == '__main__':
    main()
