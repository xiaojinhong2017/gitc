# def fun():
#     print 'The yield test'
#     yield 5
#
# t= fun()
# t.next()


import time
def fib(max):
    a,b = 0,1
    while a < max:
        k = yield
        a,b = b, a+b
        print "+++",k
t = fib(20)
t.next()
while True:
    time.sleep(1)
    print t.send(10)
# for i in fib(20):
#     print i
