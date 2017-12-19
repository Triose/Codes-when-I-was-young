
#用函数实现斐波那契

def fib(num):
    fibs = [0, 1]
    for i in range(num - 2):
        fibs.append(fibs[-1] + fibs[-2])
    return fibs

#   num = int(input('How many numbers do you want? '))
#   print(fib(num))


#文档化函数
def square(x):
    'Calculates the square of the number x.'        #这个第七章会说
    return x * x

#   print(help(square))                                 #这个help函数的结果就是'Ca.....'

#没有返回值的函数:
def tst():
    print("This line is printed.")
    return 
    print("This line is not printed.")

x = tst()
print(x)

#传入的参数叫实参，函数中的参数叫形参,改变形参不会导致实参改变
def try_to_change(n):
    n = 'Mr.Gumby'
    return 

name = 'Mrs.Entity'
try_to_change(name)
print(name)

print(); print()

#但是，就像C一样，这样就会被改变
#可以理解为，形参和实参都是引用变量，它们都引用同一个对象，通过引用变量能够改变对象
def change(ns):
    ns[0] = 'Mr.Gumby'                  #这是替换，不是修改
    return 
names = ['Mrs. Entity', 'Mrs. Thing']
#   change(names)
print(names)
#如果不想这么改变的话可以这么做:
tmp = names.copy()  #或者tmp = names[:]
change(tmp)
print(tmp)
print(names)

print();print()

#一个用函数简化的例子,在字典中添加名字(first name + last name)
#名字

def init(dic):
    dic['first'] = {}
    dic['last'] = {}
    return 

def add_name(dic, name):
    first, last = name.split()
    if first in dic['first'].keys(): 
        dic['first'][first] = dic['first'][first] + ", " + name
    else:   
        dic['first'][first] = name
    if last in dic['last'].keys():
        dic['last'][last] = dic['last'][last] + ", " + name
    else:
        dic['last'][last] = name
    return 

dic = {}
init(dic)
add_name(dic, "Triose ASDF")
add_name(dic, "MICH ASDF")
for key1 in dic.keys():
    for key2 in dic[key1].keys():
        print(key1, key2, ":", dic[key1][key2])

#今天就到这，我需要复习前面的东西了 不然忘了


#过了4天...





