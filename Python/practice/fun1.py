# coding=utf-8
def fun(a):
    a = 3
    print a


a = 1
fun(a)
print a

def fun1(l):
    l[0] = 10
    print l



l = [1,2,3,4]
fun1(l)
print l

l = [1,2,3,4]
# l1 = l[:]
import copy
l1 = copy.copy(l)
fun1(l1)
print l

def fun2(a):
    a[4][0] = 50
    print a

l = [1,2,3,4,[5,6,7]]


def fun3(*a):
    print a

fun3(1,2,3,4,5)

def fun4(a,*b):
    print a,b

fun4(1,2,3,4,5)




def fun5(a,b = 100,*c,**d): #必须按这个顺序
    print a,b,c,d

fun5(1,2,3,4,5,6,d = 7)
fun5(1,2,d = 3)

#默认参数
def fun6 (a,b = 100):
    print a,b

fun6(1)
