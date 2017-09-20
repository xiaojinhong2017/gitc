#coding=utf-8

#单线程  协程优点 阻塞后继续执行其他任务等阻塞结束后再执行本任务
import gevent
import urllib2
#真正io阻塞要用monkey用sleep模拟可以不用设置
from gevent import monkey
monkey.patch_all()

def foo():
    print 'Running in foo'
    # gevent.sleep(2)

    #发送一个http请求
    urllib2.urlopen('http://www.newbieol.com')
    f = open('green.py')

    print 'switch to foo again'
def bar():
    print 'Running in bar'
    gevent.sleep(3)
    print 'switch to bar again'

#初始化两个携程对象
f = gevent.spawn(foo)
b = gevent.spawn(bar)
gevent.joinall([f,b])
