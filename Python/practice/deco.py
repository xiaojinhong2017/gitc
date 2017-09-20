#coding=utf-8

def deco(fun):
    def func():
        print 'bbbb'
        fun()
    return func


def fun():
    print 'aaa'

fun = deco(fun)
fun()
