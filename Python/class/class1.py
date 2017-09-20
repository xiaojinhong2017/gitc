#coding=utf-8

class Person(object):
    age = 12

    def __init__(self,name):
        self.name = name
    def change_age(self,num):
        self.age = self.age + num

a = Person("xiaoming")
# b = Person()
print a.age
print a.name
# print b.age
a.change_age(1)
print a.age

#1
def fun(self):
    print self
    print 'add function'

Person.fun = fun
a.fun()
#2
print '___________________'
a.f = fun

print a.f

print '___________________'
a.f(1)
#3
import new
a.f = new.instancemethod(fun,a,Person)
a.f()
