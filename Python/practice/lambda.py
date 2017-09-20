f = lambda x,y,z:x+y+z
print f(2,3,4)


l = [lambda x, y :x *y,
   lambda x,y : x + y,
   lambda x,y : x / y,
   lambda x,y : x - y]

for r in l :
     print r(9,3)
