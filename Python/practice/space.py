s = ''
a = raw_input('input >>')
for i in a:
    if i == ' ':
        s = s + '-'
    else:
        s = s + i
print s
