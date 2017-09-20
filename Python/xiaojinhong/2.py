import random
result = []
def rand():
    count = 0
    while count != 6:
        ball = random.randint(1,33)
        if ball not in result:
            result.append(ball)
            count = count + 1
    ball1 = random.randint(1,16)
    result.sort()
    result.append(ball1)
    print result

rand()
