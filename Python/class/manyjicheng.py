#coding=utf-8
class Calculator(object):
    name = 'luosifu'

    age = 88

class Talker(object):
    name = 'liyong'
    sex = 'man'

class TalkCalaulator(Calculator,Talker):
    pass

A = TalkCalaulator()

print A.name
print A.sex
print TalkCalaulator.__mro__
print TalkCalaulator.mro() # 查询优先级
#简单记：当属性名相同时，谁在前谁的优先级越高 , 实际上是按深度优先遍历
