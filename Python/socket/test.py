#coding=utf-8

class LinkNode(object):
    def __init__(self,val):
        self.val = val
        self.next = None


class Sogliage(object):
    @staticmethod
    def to_do(l1,l2):
        H = LinkNode(None)
        p = H
        flag = 0
        while (l1 != None) and (l2 != None):
            if (l1.val + l2.val + flag) < 10:
                node = LinkNode(l1.val + l2.val + flag)
                p.next = node
                p = p.next
                l1 = l1.next
                l2 = l2.next
                flag = 0
            else:
                node = LinkNode((l1.val + l2.val + flag) % 10)
                p.next = node
                p = p.next
                l1 = l1.next
                l2 = l2.next
                flag = 1

        if l1 == None:
            p.next = l2
            while p.next != None:
                p.next.val = p.next.val + flag
                if p.next.val >= 10:
                    p.next.val = p.next.val % 10
                    p = p.next
                else:
                    break
            if p.next == None:
                node = LinkNode(1)
                p.next = node

        else:
            p.next = l1
            while p.next != None:
                p.next.val = p.next.val + flag
                if p.next.val >= 10:
                    p.next.val = p.next.val % 10
                else:
                    break
            if p.next == None:
                node = LinkNode(1)
                p.next = node
        return H

def linklist(l):
    H = LinkNode(l[0])
    p = H
    for i in l[1:]:
        node = LinkNode(i)
        p.next = node
        p = p.next

    return H

def main(l1,l2):
    L1 = linklist(l1)
    L2 = linklist(l2)
    H = Sogliage.to_do(L1,L2)
    p = H.next

    while p != None:
        print p.val,'->',
        p = p.next
    print None


if __name__ == "__main__":
    l1 = [3,4,5]
    l2 = [3,6,4]
    main(l1,l2)
