#coding=utf-8
#解释携程
#常用的携程模块:eventlet gevent stackless
from greenlet import greenlet

def test1():
    print 12
    gr2.switch()
    print 43
    gr2.switch()

def test2():
    print 56
    gr1.switch()
    print 78

gr1 = greenlet(test1)
gr2 = greenlet(test2)

gr1.switch()
