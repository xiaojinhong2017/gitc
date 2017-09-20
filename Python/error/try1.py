import traceback#引入模块



def div(a,b):
    try:
        return a / b
    except ZeroDivisionError,e:
        # print e
        # traceback.print_exc(file = open('tb.txt','w+'))
        a = traceback.format_exc()
        print a
    except TypeError as e:
        print e

result = div(3,0)
print result
