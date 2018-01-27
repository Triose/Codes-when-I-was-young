
#条件、循环以及其他

#print + ,打印多个值
print("Hello", "World")     #不会打印成元组,会添加空格
print("Hello", "World" + ',')   #这样就可以不加入空格了

#import的神奇功能
import math as foobar
print(foobar.sqrt(4))       #as提供别名

from math import sqrt as foobar
print(foobar(4))

print();print()

#赋值还能这么用
x, y, z = 1, 2, 3
print(x, y, z)

#两个变量交换
x, y = y, x
print(x, y)

#或者
values = 3, 2, 1
x, y, z = values
print(x, y, z)

#或者
scoundrel = {'name': 'Robin', 'grilfriend': 'Marion'}
key, value = scoundrel.popitem()
print(key, value)

#左右两边必须参数数量一样，否则会报错
#x, y, z = 1, 2
x, *y = 1, 2, 3, 4, 5       #这样可以
print(x, y)

print();print()

#链式赋值
x = y = 1
print(x, y)

print();print()

#增量赋值: +=, -=, *=, /=
x += 100
print(x)

print(); print()

#if语句中: False None 0 "" () {} [] 都会被当做False, 但是 bool([]) != bool({})以此类推
'''name = input("Enter your name:")
if name == "Triose":
    print("Hello Triose")
    print("This is the second line")        #这两句组成了一个语句块，相当于C中的{}
elif name == "Canaan":
    print("Hello Canaan!")                  #elif
else :
    print("This is the third line")
print("This is the forth line")'''

#镶嵌代码块
'''name = input("Enter your name:")
if name.endswith('Gumby'):
    if name.startswith('Mr.'):
        print('Hello. Mr.Gumby')
    elif name.startswith('Mrs.'):
        print('Hello. Mrs.Gumby')
    else:
        print('Hello. Gumby.')
else:
    print('Hello. stranger')'''

print();print()

#一些比较运算符:
#x == y
#x < y
#x > y
#x >= y
#x <= y
#x != y
#x is y     x和y是同一个对象
#x is not y x和y不是同一个对象
#x in y     x是y中的成员
#x not in y
#x <> y     x != y
#可连续:    0 < age < 100


#相等分为值相等和引用对象相等
x = y = [1, 2, 3]
z = [1, 2, 3]
#x与z值相等，但是引用对象不相等;x与y无论是值还是引用对象都相等
print("x & z:")
print(x == z)
print(x is z)
print("x & y:")
print(x == y)
print(x is y)

print();print()

#短路逻辑:比如if a or b中，a已经是true了，无论b取何值该条件都会成立，就不会算b的值
#   name = input("Enter your name:") or '<unknown>'
#   print(name)

#断言assert,和C一样
age = 10
assert 0 < age < 100
age = -1
#   assert 0 < age < 100    这里会出问题

print();print()

#while循环
'''x = 1
while x < 10:
    print(x)
    x += 1'''


'''name = ''
while not name:
    name = input('Please enter your name:')
print("Hello, %s!" % name)'''

#for循环
words = ['this', 'is', 'an', 'ex', 'parrot']
for word in words:
    print (word)

for num in range(1, 10):
    print(num)

print();print()

#遍历字典的所有key
d = {'x': 1, 'y': 2, 'z': 3}
for key in d:
    print(key, 'corresponds to', d[key])
for key, value in d.items():            #这里直接in d不行
    print(key, 'corresponds to', value)

#停顿了一晚上

print();print()

#一些迭代工具

#1.并行迭代:同时迭代多个列表
names = ['anne', 'beth', 'george', 'damon']
ages = [12, 45, 32, 103]

for i in range(len(names)):
    print(names[i] + "'age is", ages[i], "years old")

#zip可以把任意多个序列组合成元组
for name, age in zip(names, ages):
    print(name, "is", age, 'years old')

#zip可以处理不等长的序列，取最短值
for a, b in zip(range(5), range(10)):
    print(a, b)

print();print()

#2.按索引迭代:引例---在字符串列表中删除含有某个特征的字符串
mylist = ['asdf', 'bsdf', 'casdf', 'xxx' , 'eeee', 'xxxx', 'qwer']
print(mylist)

'''#方法一
for string in mylist:
    if 'xx' in string:
        index = mylist.index(string)        #需要在mylist中查找含有'xx'的string的下标，效率低
        mylist[index] = '[censored]'

print(mylist)'''

'''#方法二
index = 0                                   #用一个index在外面记录
for string in mylist:
    if 'xx' in string:
        mylist[index] = '[censored]'
    index += 1

print(mylist)'''

#方法三:enumerate函数(相当于提供了一个键值对)
for index, string in enumerate(mylist):
    if 'xx' in string:
        mylist[index] = '[censored]'

print(mylist)

print();print()

#翻转和排序迭代:reversed & sorted
#返回副本
seq = [4, 3, 6, 8, 3]
sseq = sorted(seq)
rseq = reversed(seq)
print(seq)
print(sseq)
print(list(rseq))       #返回的不是序列，而是一个可迭代对象

print();print()

#跳出循环   其实break和continue和C中的一样，打下面的程序是为了 range(99, 0, -1) 这种形式
from math import sqrt
for n in range(99, 0, -1):
    root = sqrt(n)
    if root == int(root):
        print(n)
        break

#while True这种形式EG:
'''while True:
    word = input("Please input a word:")
    if not word: break
    print("The word was " + word)'''

#循环中的else的奇妙用法:
for n in range(99, 81, -1):         #else居然可以写在循环外面，这里可以试试改一改循环的范围来看运行结果的不同(81 -> 80)
    root = sqrt(n)
    if root == int(root):
        print(n)
        break
else: print("Didn't find it!")

print();print()

#列表推导式--轻量级循环
print([x*x for x in range(10)])         #这个可厉害了
print([x*x for x in range(10) if x % 3 == 0])       #这个也厉害
print([(x, y) for x in range(3) for y in range(2)]) #这个也厉害

print();print()
#把名字首字母相同的男孩女孩组合在一起
boys = ['chris', 'arnold', 'bob']
girls = ['alice', 'bernice', 'clarice']
print([boy+'+'+girl for boy in boys for girl in girls if boy[0] == girl[0]])        #厉害厉害

print();print()

#pass, del, exec

#pass: 什么都不做(因为空代码块是非法的)相当于占位符
'''name = input('Enter your name:')
if name == 'A':
    print("Welcome!", name)
elif name == 'B':
    pass
else :
    print('Hello!', name)'''

#当某一对象没有引用变量指向的时候，Python解释器会删除它(像Java虚拟机一样)
#但是删除还有另外一种手动的方式就是del:移除引用变量对某一对象的引用，并且移除该引用变量本身(对象仍然存在)
#   del name
print(name)         #如果取消前一句的注释的话，就会报错'name is not defined'

print(); print()

#exec和eval
cmd = 'print("Hello World")'
exec(cmd)
#关于exec 本书里还有一些其他的介绍比如说命名空间 但是实践起来有一些问题，先放在这日后解决

#eval计算字符串中表达式的值
#   print(eval(input("Please input a n arithmetic expression:")))




#小结:
#print          可以打印多个值，用','隔开
#导入           import A as B 就能用B替代A
#赋值           a, b, c = 1, 2, 3这种样子
#代码块         通过tab弄出来的块块，对齐的就是一块
#条件
#断言           不满足就报错
#循环           for和while 这两个和C/C++有一些区别
#列表推导式     厉害厉害 x*x for x in range(9,0,-1) if ...
#pass del exec eval

#新函数:
#chr(n)             表示在ascii[n]
#   print(chr(97)) = a
#eval()             将字符串转换为表达式返回值
#enumerate(seq)     产生用于迭代的键值对
#ord(c)             和chr相反
#   print(ord('a')) = 97
#range(s,e,sl)      开始、结束、步长的整数列表。一次性构造整个列表
#reversed(seq)      产生seq的值的反向版本，用于迭代
#sorted(...)        排序(具体参数见后面的章节)
#xrange(...)        和range类似，不过只是先构造前一部分的列表
#zip(seq1, seq2, ..)构造用于并行迭代的新序列







