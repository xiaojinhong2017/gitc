import sys
fd = open('file.txt','a+')
s = sys.stdin.readline()
# fd.write(s)
fd.write("hello world \n nihao")
l = ['hello\n','nihao\n']
fd.writelines(l)
fd.close()
