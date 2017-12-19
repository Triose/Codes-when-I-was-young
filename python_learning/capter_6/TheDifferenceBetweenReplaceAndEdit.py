#学到这有了个疑问,关于替换和修改，还有=和浅拷贝还有深拷贝
#特别写一个程序来加深印象

#=
x = [1, 2, 3]
y = x           #用Java的话说:这里是x和y两个引用变量同时指向一个对象,所以无论通过哪一个引用变量都可以改变内存中的对象
y[0] = 100      #替换
print("X is", x)
print("Y is", y)
print()
y.append(10)    #修改
print("X is", x)
print("Y is", y)

print();print()

#浅拷贝: .copy() or x = y[:]
x = [1, 2, [3, 4, 5]]
xc = x.copy()   #xc是x的浅拷贝对象的引用,在对xc的操作中,替换不会使得x发生改变,但是修改会
xc[0] = 1000    #这里是替换
print("X is", x)
print("X's copy is", xc)
print()
xc[2].append(999)   #这里是修改
print("X is", x)
print("X's copy is", xc)

print();print()

#深拷贝: deepcopy(x)
from copy import deepcopy
x = [1, 2, [3, 4, 5]]
xdc = deepcopy(x)       #xdc是x的一个完全一样的副本(完完全全引用的是另外一个对象，无论这个对象怎么变--替换或修改，x都不会变)
xdc[0] = 100
print("X is", x)
print("The deepcopy of X is", xdc)
print()
xdc[2].append(888)
print("X is", x)
print("The deepcopy of X is", xdc)


#所以这三体两面的关系大概如下图

'''
1表示x会变，0表示不会
----------- ---------- -----------
|          |   替换   |    修改  |
----------- ---------- -----------
| y=x      |    1     |     1    |
----------- ---------- -----------
----------- ---------- -----------
| xc       |    0     |     1    |
----------- ---------- -----------
| xdc      |    0     |     0    |
----------- ---------- -----------
'''











