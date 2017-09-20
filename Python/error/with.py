with open('try.py') as fd:
    try:
        print fd.read()
    except:
        pass

class Test(object):
    def __enter__(self):
        print 'enter....'
    def __exit__(self,type,value,trancback):
        print 'exit....'
with Test() as t:
    print 'in with'
