# str = ['(','1','+','2',')','*','4']
str1=['(','2','*','(','4','+','1',')',')','*','2','-','2',"*",'3']
def pri(s):
    if s == '+'or s=='-':
        return 1
    elif s == '*'or s == '/':
        return 2
    elif s == '(':
        return 3
    elif s == ')':
        return 4
    else:
        return 0



def change(str):
    stack = []
    stack.append('#')
    for i in str:
        if pri(i) == 0:

            print i,
        else:
            if stack[len(stack)-1] == '#':
                stack.append(i)
            else:
                if i == '(':
                    stack.append('(')
                elif i == ')':
                    while stack[len(stack)-1] != '(':
                        print stack.pop(),
                    stack.pop()
                else:
                    if pri(i) > pri(stack[len(stack)-1]):
                        stack.append(i)
                    elif pri(i) <= pri(stack[len(stack)-1]) and pri(stack[len(stack)-1]) !=3 :
                        while pri(i) <= pri(stack[len(stack)-1]):
                            print stack.pop(),
                        stack.append(i)
                    elif stack[len(stack)-1] == '(':
                        stack.append(i)
    while True:
        if len(stack) == 1:
            break
        print stack.pop(),
change(str1)
