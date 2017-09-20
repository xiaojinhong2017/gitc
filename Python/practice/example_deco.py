#coding=utf-8

def deco(str):
    def _deco(fun):
        def _deco(name):
            if 4 <len(name)< 8:
                return fun(name)
            else:return str
        return _deco
    return _deco



@deco('admin')
def reg(name):
    return name

name = raw_input()
print reg(name)
