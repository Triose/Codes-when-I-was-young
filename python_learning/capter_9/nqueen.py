
pos = []

def valid(pos, point):
    for p in pos:
        if point[0] == p[0] or point[1] == p[1]: return False           # 同行同列
        elif abs(point[0] - p[0]) == abs(point[1] - p[1]): return False # 同对角线, 千万记得加abs
    return True

def nqueens(n, row):
    if len(pos) == n:
        print(pos)
        return 
    for i in range(n):
        point = (row, i)
        if valid(pos, point):
            pos.append(point)
            nqueens(n, row + 1)
            pos.pop()

nqueens(8, 0)




