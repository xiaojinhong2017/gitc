#coding=utf-8
fd = open('file.txt','r+')
fd.read(12)
print fd.tell()

fd.read(12)
print fd.tell()

fd.seek(0)
fd.write('南无善男')
