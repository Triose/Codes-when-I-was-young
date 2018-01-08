
def conflict(state, nextX):                                 # state[row] = col -> 第row行的皇后放在col列
    nextY = len(state)
    for i in range(nextY):
        if abs(state[i] - nextX) in (0, nextY - i):         # 同列或者同对角线
            return True
    return False

def queens(num = 8, state = ()):
    if len(state) == num - 1:
        for pos in range(num):
            if not conflict(state, pos):
                yield (pos,)
    else:
        for pos in range(num):
            if not conflict(state, pos):
                for result in queens(num, state + (pos, )):
                    yield((pos, ) + result)

for state in queens():
    print(state)




