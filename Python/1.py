#coding=utf-8
class Stack(object):
    '''
    stack
            这里是基于列表的栈（将列表作为基础数据结构）
    push 往里面放
    peek 查看栈顶元素
    pop 弹出栈顶元素，并返回这个方法的返回值
    empty 判断栈是否为空
    ***效率优化 栈长度保留
    '''
    def __init__(self):
        self.datas = []
        self.length = 0
        print '初始化完成'

    #===========================================================================
    # put向栈顶插入一个元素
    #@param data: 要插入的元素没有返回值
    #===========================================================================
    def push(self,data):
        self.datas.append(data)
        self.length += 1

    #===========================================================================
    # peek查看栈顶元素
    #@return 栈顶元素
    #===========================================================================
    def peek(self):
        return None if self.empty() else self.datas[len(self.datas) - 1]

    #===========================================================================
    # pop 弹出栈顶元素
    #===========================================================================
    def pop(self):
        try:
            return self.peek()
        finally:
            self.length -= 1
            del self.datas[len(self.datas) - 1]

    def empty(self):
        #return not bool(self.datas)
        return not bool(self.length)

    def __str__(self):
        print '-----------------------str called----------------------'
        return ','.join([str(data) for data in self.datas])


if __name__ == '__main__':
    stack = Stack()
    stack.push('(')
    stack.push('abc')
    stack.push(1 + 2J)
    stack.push(1.2)
    print '%s' % stack
    print str(stack.peek())

    print '%s' % stack
    print str(stack.pop())

    print '%s' % stack
    print str(stack.pop())

    print '%s' % stack
    print stack.empty()
    print str(stack.pop())

    print '%s' % stack
    print stack.empty()
    print str(stack.pop())

    print '%s' % stack
    print stack.empty()
