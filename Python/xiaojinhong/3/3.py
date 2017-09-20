#coding=utf-8
import re
s = ''
fd = open('text.py')
for line in fd:
    s = s + line




r = re.compile(r'\w*Django\S*')
result = r.findall(s)
print result
