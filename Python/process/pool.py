from multiprocessing import Process ,Pool
import time
import os

#pool.appy,pool.appy_async

def foo(i):
    time.sleep(2)
    print 100 + i
    return 100 + i

def Bar(arg):
    print 'exec done:',arg,os.getpid()

pool = Pool(5)

for i in range(10):
    pool.apply_async(func = foo,args = (i,),callback = Bar)

print 'end'

pool.close()
pool.join()
print os.getpid()
