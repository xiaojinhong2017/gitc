class A(object):
    attr = 'text'
class B(A):
    pass

class C(B):
    pass

print issubclass(C,A)

a = A()

print isinstance(a,A)


n = 1
print isinstance(n,int)


c = C()
print isinstance(c,A)
print isinstance(c,(A,B,C))
print '============================'
print hasattr(a,'attr')
print getattr(a,'attr','sorry')
setattr(a,'name','zhangsan')
print a.name

#delattr(a,'attr')不能删除类中的属性，只能删除私有属性
delattr(a,'name')
