#coding=utf-8
#代码有问题不能运行
from socket import *
from time import ctime
import gevent
from gevent import monkey
monkey.patch_all()

def server(port):
    s = socket()
    s.bind(('192.168.1.151',port))
    s.listen(10)
    while True:
        cli,addr = s.accept()
        gevent.spawn(handler,cli)

def handler(conn):
    try:
        while True:
            data = conn.recv(1024)
            print 'recv:',data
            conn.send(ctime())
            if not data:
                break
    except Exception as e:
        print e
    finally:
        conn.close()
if __name__ == '__main__':
    server(4000)
