import multiprocessing
def worker():
    '''worker function'''
    print('worker')
    return

if __name__=='__main__':
    jobs = []
    for i in range(5):
         p = multiprocessing.Process(target = worker)
         jobs.append(p)
         p.start()
