#coding=utf-8
import types

def fun(*args):
    if type(args[0]) is types.IntType :
        sum = 0
    elif type(args[0]) is types.StringType:
        sum = ''
    try:
        for i in args:
            sum = sum + i
        print sum
    except TypeError as e:
        print e
fun(1,2,3)
fun('1','2','3')
