#coding=utf-8
class Person(object):
    sex = 'man'
    age = 18
    def fun(self):
        print 'fdhsfhsd'
    class Metel(object):
        height = 21
        def fun(self):
            print 'hello'

a = Person()
a.name = 'zhangsan'#添加私有变量
a.age = 20
b = Person()
print b.sex
print a.sex
print a.name
print a.age
print '+++++++++++++++++++++++++'
print Person.sex
Person.age = 19
print Person.age
# print Person.name不能打印私有变量
a.fun()
c =a.Metel()
print c.height
c.fun()
