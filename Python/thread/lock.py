import threading
import time

a = 1

def fun1():
    lock.acquire()
    global a
    # a += 1
    a = 100
    time.sleep(2)
    print 'fun1',a
    lock.release()


def fun2():
    lock.acquire()
    time.sleep(1)
    global a
    a = 10
    print 'fun2',a
    lock.release()

lock = threading.Lock()
t1 = threading.Thread(target = fun1)
t2 = threading.Thread(target = fun2)


t1.start()
t2.start()

t1.join()
t2.join()
