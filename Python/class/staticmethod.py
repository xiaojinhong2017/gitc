#coding=utf-8


class TestStaticMethod:
    def foo():
        print 'calling static method foo()'
    foo = staticmethod(foo)
  # @staticmethod 可以用装饰器的方法声明这个方法为静态方法
class TestClassMethod:
    def foo(cls):
        print 'calling class method foo()'
        print 'class',cls.__name__
    foo = classmethod(foo)

TestStaticMethod.foo()
TestClassMethod.foo()


a = TestClassMethod()
a.foo()
b = TestStaticMethod()
b.foo()



class Color(object):
    _color = (0,0,0);
    @classmethod
    def value(cls):
        if cls.__name__ == 'Red':
            cls._color =(255,0,0)
        elif cls.__name__ == 'Green':
            cls._color = (0,255,0)
        return cls._color

class Red(Color):
    pass
class Green(Color):
    pass
class UnknowColor(Color):
    pass


red = Red()
green = Green()
xcolor = UnknowColor()

print 'red = ',red.value()
print 'green =',green.value()
print 'xcolor =',xcolor.value()
