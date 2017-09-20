def fun(*args):
    # print args[0][2]
    k = 0
    l = len(args)
    while k <= l-1:
        for i in range(k,l):
            for j in range(k,l):
                if j != (l-1):
                    print args[i][j]
                if j == l-1:
                        for i in range(k,l):
                            if i != (l-1):
                                print args[i][j]
                            else:
                                while j > k:
                                    print args[i][j]
                                    j = j-1
                                if j == k:
                                    while i > k:
                                        print args[i][j]
                                        i = i - 1
                                    if i == k:
                                        l = l - 2
                                        k = k + 2

    else:
        print args[l][l]









fun((1,2,3,4,5),(6,7,8,9,10),(11,12,13,14,15),(16,17,18,19,20),(21,22,23,24,25))
