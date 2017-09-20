def div(a,b):
    try:
        return a / b
    except ZeroDivisionError,e:
        print e
    else:
        print 'else'
    finally:
        print 'finally'

result = div(3,0)
print result
