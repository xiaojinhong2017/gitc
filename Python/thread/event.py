import threading
from time import sleep


e = threading.Event()


#冲破阻塞wait挡不住它
e.set()

event = e.wait()
print event
e.clear()


event = e.wait(2)
print('timeout:',event)
