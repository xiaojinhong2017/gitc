import sys

fd = open('test.txt','w')
while True:
    s = sys.stdin.readline()
    if s == '\n':
         break
    fd.write(s)

fd.close()
