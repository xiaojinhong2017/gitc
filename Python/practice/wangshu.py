for i in range(1,1000):
    k = 0
    for j in range(1,i):
        if(i % j == 0):
            k = k + j
    if i == k:
        print '%d'%i,

print ''
