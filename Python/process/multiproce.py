import multiprocessing
from time import ctime ,sleep
import os
from multiprocessing import  Queue ,Pipe
def worker(interval):
    n = 5
    print que.get()
    while n > 0:
        print "The time id {}".format(ctime())
        print "worker pid >>",os.getppid()
        sleep(interval)
        n -= 1


def teacher(interval):
    n = 5
    que.put([42,None,'hello'])
    child_conn.send([42,None,'hello'])
    while n > 0:
        print 'The time id {}'.format(ctime())
        print 'teacher pid >>',os.getppid()
        sleep(interval)
        n -= 1
if __name__ == '__main__':
    que = Queue()
    parent_conn,child_conn = Pipe()
    p = multiprocessing.Process(name = 'worker',target = worker ,args = (2,))
    p.start()
    q = multiprocessing.Process(name = 'teacher',target = teacher,args = (3,) )
    q.start()

    q.join()
    p.join()


    print parent_conn.recv()
    print 'p.pid:',p.pid
    print 'p.name:',p.name
    print 'p.is_alive:',p.is_alive
    print 'q.pid :',q.pid
    print 'q.name:',q.name
    print 'q.is_alive:',q.is_alive
