#coding=utf-8
class Protect(object):
    def __init__(self):
        self.job = 'teacher'
        self.__name = "admin"

    def __python(self):
        print 'teacher python'

    def setName(self,name = 'admin'):
        if 4<=len(name)<=8:
            self.__name = name
        else:
            pass
    def getName(self):
        return self.__name
    # @property
    # def name(self):
    #     return self.__name
    # @name.setter
    # def name(self,name = 'admin'):
    #     if 4 <= len(name) <= 8:
    #         self.__name = name
    #     else:
    #         pass

class Private(Protect):
    pass

t = Protect()
print t.job
# print t.__name
# t.__python()双下滑线为私有属性与方法
t.setName('zhangsan')
print t.getName()

t1  = Private()
t1.setName()
print t1.getName()
