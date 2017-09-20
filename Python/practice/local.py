a = 1
b = 2
def fun():
    c = 3
    d = 4
    return locals()

print globals()

print fun()
