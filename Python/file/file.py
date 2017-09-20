#coding=utf-8

fd = open('06.html')
fs = open('file.html','w+')
for line in fd:
    #会记录上次读写位置
    fs.write(line)

#记录读写位置
print fd.tell()
fs.close();
fd.close();
