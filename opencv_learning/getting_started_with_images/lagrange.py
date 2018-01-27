# 拉格朗日插值法:
# 已知有限个f(x[i])取值为y[i]
# 试构造多项式函数L(x)使得对于所有已知的x[i]有y[i] = L(x[i])
# 前段时间在高数书上看的 想了想觉得可以拟合出图像来 正好今天学了怎么画图就试着写一写
# 假设f(x) = x * x
# 已知x = [-10, ... 10]的f(x) = [...]
import random

x = [i for i in range(-20, 21, 1)]
y = [i * i for i in x]

def l(x, j, X):
    ans = 1.0
    for i in range(len(X)):
        if i != j:
            ans *= (x - X[i]) / (X[j] - X[i])
    return ans

def L(xj, X, Y):
    ans = 0.0
    for i in range(len(X)):
        ans += (Y[i] * l(xj, i, X))
    return ans;

x_test = [random.uniform(-20, 20) for i in range(21)]
x_test.sort()
y_test = []


for xi in range(len(x_test)):
    yi = L(x_test[xi], x, y)
    y_test.append(yi)
     

import matplotlib.pyplot as plt
plt.xlabel('variables')
plt.ylabel('values of variables')
plt.plot(x, y)
plt.plot(x_test, y_test)
plt.show()

# 两条线几乎是挨在一起的





