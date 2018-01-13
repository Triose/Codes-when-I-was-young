
import numpy as np



def getValue(v):
    return (1 + v) / (10 + v)

x = [None] * 10000
x[0] = 0
for i in range(1, 10000):
    x[i] = x[i - 1] + 0.1


