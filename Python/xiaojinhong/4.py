class rank:
    def __init__(self,len):
        self.len = len
    def do_maopao(self,list):
        for i in range(0,self.len):
            for j in range(i+1,self.len):
                if list[i] > list[j]:
                    list[i],list[j] = list[j],list[i]
        print list
    def do_select(self,list):
        for i in range(0,self.len):
            flag = i
            min = list[i]
            for j in range(i+1,self.len):
                if min > list[j]:
                    min = list[j]
                    flag = j
            list[i],list[flag] =  list[flag],list[i]
        print list


class sonrank(rank):
    def do_quick(self,list):
        for i in range(0,self.len):
            j = self.len-1
            mid = list[i]

            while i <= j:
                if list[j] < mid:
                    list[j],list[i] = list[i],list[j]
                    while i < j:
                        if list[i] > mid:
                           list[i],list[mid] = list[mid],list[i]
                        else:
                            i = i + 1
                else:
                    j = j-1
        print list


r = rank(10)
r1 = sonrank(10)
r.do_maopao([1,2,34,10,6,7,22,34,10,81])
r.do_select([1,2,34,10,6,7,22,34,10,81])
r1.do_quick([1,2,34,10,6,7,22,34,10,81])
