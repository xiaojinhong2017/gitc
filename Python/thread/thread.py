from time import ctime , sleep
import os
import threading

def music(name):
    print 'I was listening to music %s .%s'%(name,ctime())
    print os.getpid()
    sleep(2)

def move(name):
    print 'Iwas at the movie %s! %s'%(name,ctime())
    print os.getpid()
    sleep(5)

threads = []
t1 = threading.Thread(target = music,args = ('baby',))
t2 = threading.Thread(target = move,args = ('afanda',))

threads.append(t1)
threads.append(t2)

if __name__ == '__main__':
    for t in threads:
        t.setDaemon(True)
        t.start()
    for t in threads:
        t.join()
    print os.getpid()
    print 'all over %s'%ctime()
