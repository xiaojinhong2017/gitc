l1 = [1,2,3,4]
l2 = [5,6,7,8]
for (x,y) in zip(l1,l2):
    print '%d,%d ----,%d'%(x,y,x+y)
keys = ['spam','eggs','toast']
vals = [1,3,5]
list(zip(keys,vals))
d = {}
for (k,v) in zip(keys,vals) :
    d[k] = v
print d
