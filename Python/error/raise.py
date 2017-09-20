#coding=utf-8

# print 'hello'
#
# raise
#
# print 'kitty'
# 自定义一个异常
# 抛出异常
class MyError(Exception):
    pass

try:
    s = None
    if s is None:
        print ('s 是空对象')
        raise MyError('异常错误信息')
    print (len(s))
except MyError as e:
    print '空对象没有长度'
    print e.args
