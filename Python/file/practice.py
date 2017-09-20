#coding=utf-8
# fd = open('test.txt','a+')
import time
line = 0
try:
    f = open('test.txt','a+')
except IOError as e:
    print e
for i in f:
    line += 1
while True:
    # time.sleep(1)
    # c = time.ctime()
    # fd.write(c)
    # fd.write('\n')
    # fd.flush()
    tm = time.localtime()
    line += 1
    print >>f,'%d,%4d-%02d-%02d-%02d  %02d:%02d:%02d'\
    %(line,tm.tm_year,tm.tm_mon,tm.tm_mday,tm.tm_hour,tm.tm_min,tm.tm_sec)
    f.flush()
