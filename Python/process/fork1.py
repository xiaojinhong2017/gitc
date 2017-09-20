import os ,time
from signal import *
import sys
pid = os.fork()
if pid < 0:
    print 'create process failed'
elif pid == 0:
    pid = os.fork()
    if pid == 0 :
        time.sleep(1)
        print 'This is son process',os.getpid(),os.getppid()
    elif pid > 0:
        # print os.getppid()
        # print 'This is child process',os.getpid(),os.getppid()
        sys.exit()
else:
    # time.sleep(0.1)
    print 'This is parent process',os.getpid()
    print pid
    # while True:
    #     pass
print '++++++++++++++++'
