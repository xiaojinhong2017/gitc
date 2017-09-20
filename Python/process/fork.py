import os
import time
#创建进程
pid = os.fork()
if pid < 0:
    print('create process failde')
elif pid ==0:
    print('This is child process:',os.getpid())
else:
    time.sleep(1)
    print('parent process',pid)
print('----------------')
