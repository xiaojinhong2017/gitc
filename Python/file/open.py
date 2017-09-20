
#coding=utf-8
fd = open('file.txt')
#文件描述符
print fd
#关闭


# s = fd.read()
#
# print s

s1 = fd.readlines()
print s1
#结束是因为已经读完了
for line in fd:
    print line,

fd.close()

# with open('file.txt') as fd:
#     pass
import sys
#没有打印出来跟缓冲池有关
# print sys.stdin.read()
# print sys.stdin.readline()


fd1 = open('file.txt','r+',buffering=-1)
print fd1.read()


#文件读操作
# 1.fd.read([size])一次读size个字符
# 2.fd.readline([size])一次读size个字符，但遇到换行时不管够不够size个字符都算一次
# 3.fd.readllines([size])每一行以列表的形式存放
# 4.for line in fd


#标准输入输出流
# fd.stdin.read()
