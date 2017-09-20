面试题：异常处理
def div(a,b):
    try:
        return a / b

    # except ZeroDivisionError:
    #     print 'zero can not be divsion'



    # except (ZeroDivisionError,TypeError):
    #     print 'Error'



    # except:
    #     print 'error'


    except Exception:
        print 'Error'

result = div(5,'a')

print (result)

总结：
如果有多种可能异常出现可用以下方法处理:
1.分开写，有几种写几种
2.用元组方式写
3.用Exception代替所有异常
4.只写except（不建议）
