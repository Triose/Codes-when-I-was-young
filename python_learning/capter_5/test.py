
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

#今天先到这了




