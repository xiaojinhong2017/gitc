#coding=utf-8
#python中没有重载，重写,因为没有必要:python中有丰富的传参方式
class Animal(object):
    def __init__(self,name):
        self.name = name
        print self.name
    foot = 4
    def run(self):
        print 'run........'


class Cat(Animal):
    call = 'miao'


class Dog(Animal):
    jiao = 'wang'
    def run(self):
        print 'run fast.....'

a = Cat('cat')
print a.call
print a.foot
a.run()
# 为了考虑为什么 python 不提供函数重载，首先我们要研究为什么需要提供函数重载。
# 函数重载主要是为了解决两个问题。1。可变参数类型。2。可变参数个数。
# 另外，一个基本的设计原则是，仅仅当两个函数除了参数类型和参数个数不同以外，其功能是完全相同的，
# 此时才使用函数重载，如果两个函数的功能其实不同，那么不应当使用重载，而应当使用一个名字不同的函数。
# 好吧，那么对于情况 1 ，函数功能相同，但是参数类型不同，python 如何处理？
# 答案是根本不需要处理，因为 python 可以接受任何类型的参数，如果函数的功能相同，那么不同的参数类型
# 在 python 中很可能是相同的代码，没有必要做成两个不同函数。
# 那么对于情况 2 ，函数功能相同，但参数个数不同，python 如何处理？
# 大家知道，答案就是缺省参数。对那些缺少的参数设定为缺省参数即可解决问题。
# 因为你假设函数功能相同，那么那些缺少的参数终归是需要用的。
# 好了，鉴于情况 1 跟 情况 2 都有了解决方案，python 自然就不需要函数重载了。
#
