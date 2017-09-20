def fun(N):
    def fun1(x):
        return x ** N
    return fun1

f = fun(2)
print (f(3))



def fun2(a):
    def fun3():
        nonlocal a
        a += 1
        print (a)
    fun3()

fun2(10)


a = 1
def fun4():
    global a
    a += 1
    print (a)
fun4()
