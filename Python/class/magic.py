#coding=utf-8
#new 与init 的不同

'''
__new__:创建对象时调用，会返回当前对象的一个实例

__init__:创建完对象后调用，对当前对象的一些实例初始化，无返回值
1、在类中，如果__new__和__init__同时存在，会优先调用__new__
2、__new__方法会返回所构造的对象，__init__则不会。__init__无返回值。
'''
'''This is a doc'''

class A(object):
    '''This is a class document'''
    def __init__(self):
        print '__init__..........'
        self.dict = {}

    def __new__(cls):
        print '__new__...........'
        return super(A,cls).__new__(cls)
    def __del__(self):
        print '__del__.......'
    def __call__(self,n):
        print 'call......',n
    def __getattr__(self,name):
        print 'You chufa getattr %s'%name
        return
    def __setattr__(self,name,value):
        print 'You chufa setattr'
        self.__dict__[name] = value
    def __delattr__(self,name):
        print 'You use delattr'
    def __getitem__(self,key):
        return self.dict[key]

    def __setitem__(self,key,value):
        self.dict[key]=value
    def __len__(self):
        return len(self.dict)





a = A()
print a.__doc__

a.value = 100
print a.value

# del a 不管写不写都执行print但是写了之后就是执行删除对象操作最后执行

# a(1)
print '==============='
a['a'] = 1
print a['a']
a['b'] = 2
print len(a)
print '==============='
