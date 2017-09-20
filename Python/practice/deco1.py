#coding=utf-8

def deco(fun):
    def func(*args,**kwargs):
        if args[0] != '毛裤':
            ret = fun(args[0])
            return ret + '毛裤'
        return args[0]
    return func


@deco
#fun = deco(fun)


def fun(a):
    return a

print fun('毛裤')
