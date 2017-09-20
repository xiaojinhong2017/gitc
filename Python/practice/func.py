def func(a,b):
    print 'a:',a
    print 'b:',b
func(1,2)
print '======================='
func(b = 2,a = 1)
print '==================='
l = [2,3]
func(*l)
print '======================'
s = (1,2)
func(*s)
print '======================='

d = {'a':1,'b':2}
func(**d)
