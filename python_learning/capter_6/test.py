
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
#然后通过first or last name来查找全名

def init(dic):
    dic['first'] = {}
    dic['last'] = {}
    return 

def add_name(dic, name):        #这里和书上的代码功能几乎一样，不过书上的调用稍麻烦，略
    first, last = name.split()
    '''
    if first in dic['first'].keys(): 
        dic['first'][first].append(name)
    else:   
        dic['first'][first] = [name]
    if last in dic['last'].keys():
        dic['last'][last].append(name)
    else:
        dic['last'][last] = [name]
    这里可以优化成如下:
    '''
    dic['first'].setdefault(first, []).append(name)
    dic['last'].setdefault(last, []).append(name)
    return 

dic = {}
init(dic)
add_name(dic, "Triose ASDF")
add_name(dic, "MICH ASDF")
for key1 in dic.keys():
    for key2 in dic[key1].keys():
        print(key1, key2, ":", dic[key1][key2])
#今天就到这，我需要复习前面的东西了 不然忘了

print();print()

#过了4天...
def lookup(data, label, name):      #查找函数
    return data[label].get(name)

print(lookup(dic, 'last', 'ASDF'))

print();print()

#如果参数本身不可改变，那么函数中也不能改变该参数
def inc(x): x += 1

a = 10; inc(a)
print(a)
#但是可以把改变后的值当做返回值传回来,如果值多余一个的话，就用元组传回来(列表也可的):
def inc_r(x, y): return (x + 1, y + 1)

a = inc_r(10, 109)
print(a)

#如果实在要改变,就把值放在列表中:
def inc_2(x): x[0] += 1

a = [10]; inc_2(a)
print(a)

#以上相当于在C++语言中用函数改变一个int值,C++有&，C有指针，都可以改变函数外的int类型，但是python没有！
#所以实在要改变的话，只能用以上的方法返回或者放在列表中改变(放在列表中改变可以类比C或者C++中放在数组里改变)

print();print()

#默认参数
def hello(greeting = "Hello", name = "World"):
    print(greeting, name, '!')

hello()
hello("Greeting")
#   hello(, "universe") 这么省略不行!
hello(name = "universe")    #这个叫 关键字参数(使用参数名提供的参数)

def hello_2(greeting = "Hello", name = "World", punctuation = "!"): print("%s %s%s" % (greeting, name, punctuation))

hello_2('Good morning', punctuation = '...')        #位置参数和关键字参数一起用

print();print()

#接收任意多的参数(收集参数):  作为元组输出
def print_params(*params):      #*是收集其余位置的参数
    print(params)
print_params('Testing')
print_params(1, 2, 3, 4, 5)
print_params()  #一个空元组

print()

#但是 局限是没法收集关键字参数:下面注释的代码会报错
#   print_params('Hmm...', sth = 43)
#如果要收集关键字参数可以这么写:
def print_params2(**params):
    print(params)

print_params2(x = 1, y = '2')       #返回的是字典，而不是元组

print()

#可以混合使用:
def print_diff(x, y, z = 3, *pospar, **keypar):
    print(x, y, z)
    print(pospar)
    print(keypar)

print_diff(1, 2, 3, 4, 5, 6, foo = 1, bar = 2)

print();print()

#参宿收集的逆过程(在函数的调用端,而不是定义端)
def add(x, y): return x + y

params = (1, 2)
print(add(*params))     #在调用端用了*,把params中的东西'分配'给各个参数

print()

#同样的方式用来处理字典:
def hello3(greeting = 'hello', name = 'world'): print(greeting, name)
dic = {'name': 'triose', 'greeting': 'Well met'}    #这里字典的key一定要和函数的参数名一致，不然会报错
hello3(**dic)           #这里如果只加一个*的话，不会报错，传入的是字典的key

print();print()

#用**和不用的区别:
def with_stars(**dic):
    print(dic['name'], 'is', dic['age'], 'years old')

def without_stars(dic):
    print(dic['name'], 'is', dic['age'], 'years old')

args = {'name': 'Mr. Gumby', 'age': 42}
with_stars(**args)
without_stars(args)
#对就是没有区别。星号只在定义函数(允许使用不定数目的参数)或者调用('分割'字典或者序列)时才用

'''
看到这估计也该蒙了,我总结了一下上面收集参数及其逆过程的逻辑:
============================================================
1.收集多个参数:
    定义:   print_params(*params)
    调用:   print_params(1, 2, 3, 4, 5, 6)
    params以元组的形式展现
2.收集关键字参数:
    定义:   pring_params(**params)
    调用:   print_params(name1 = 'asdf', name2 = 1234)
    params以字典的形式展现
逆过程:
1.分配多个参数:
    定义:   add(x, y)
    调用:   add(*params)        #其中 params = (1, 2)
2.分配多个关键字参数
    定义:   hello3(greeting = 'A', name = 'B)
    调用:   hello3(**dic)       #其中 dic = {'greeting' = 'Well met', 'name' = 'Triose'}
    补充说明:这里可以只加一个*，那么调用的时候分配给形参的就是dic的key.
             另外: dic的键的名字必须和形参名字一样!

然后!
因为这两种形式的定义在功能上并没有区别(如果函数内代码一样的话)
    (1) with_stars(**dic)       (2) without_stars(dic)          #这里的dic是个字典
    (1) with_stars(*params)     (2) without_stars(params)       #这里的params是个元组
所以一般不多写这写*
再进一步: *用于在定义函数(允许使用不定数目的普通参数和关键字参数)时或者调用函数('分割'字典和序列)时才有用
例如:
def test_call(x, y, name, age):
     print(x + y)
     print(name, age)
 
param1 = (1, 2)
param2 = {'name': 'triose', 'age': 22}
test_call(*param1, **param2)
============================================================
'''

print();print()

#练习一下:
def story(**kwds):
    return 'Once upon a time, there was a'\
           ' %(job)s called %(name)s.' % kwds

def power(x, y, *others):
    if others:
        print('Received redundant parameters:', others)
    return x ** y

def interval(start, stop = None, step = 1):
    'Imitates range() for step > 0'
    if not stop:
        start, stop = 0, start
    result = []
    i = start
    while i < stop:
        result.append(i)
        i += step
    return result

print(story(job = 'king', name = 'Gumby'))

print()

print(story(name = 'Sir Robin', job = 'brave knight'))

print()

params = {'job': 'language', 'name': 'Python'}
print(story(**params))

print()
del(params['job'])
print(story(job = 'stroke of genius', **params))        #可以把两个字典合成一个

print(power(2, 3))

print()

print(power(3, 2))

print()

print(power(y = 2, x = 3))          #x和y换了位置，不过标出了关键字，所以结果不会变

print()

params = (5,) * 2
print(power(*params))

print()

print(power(3, 3, 'Hello World'))

print()

print(interval(10))

print()

print(interval(1, 5))

print()

print(power(*interval(3, 7)))       #不一定非要是元组，也可以是列表

print();print()

#这章太长了!

#作用域
x = 1
scope = vars()
#print(scope)            #所有的变量都存在一个字典里(这样解释起来也方便,真是厉害了)

print(scope['x'])
scope['y'] = 2
print(scope['y'])
print(x + y)

print();print()

#局部变量访问全局变量
def combine(parameter): print(parameter + external)

external = 'berry'
combine('Shrub')

print();print()

#当某局部变量名字和全局变量一样时,就会覆盖全局变量导致无法直接访问
#不过可以这样访问:  globals()['parameter_name']
def combine(parameter):
    print(parameter + globals()['parameter'])

parameter = 'berry'
combine('Shrub')

#各种变量的字典:
#vars           所有变量
#globals        所有全局变量
#locals         所有局部变量


print();print()

#在函数内部创建的变量会自动成为局部变量,除非告知其为全局变量
x = 1
def change_global():
    global x
    x += 1

change_global()
print(x)            #这样就可以在函数内部改变外部变量的值了

print();print()

#嵌套作用域:(这个可真神奇)
#一个函数位于另外一个函数里面,外层函数返回内层函数。也就是说内层函数本身被返回了但是并没有被调用。
#最重要的是返回的函数仍然可以访问它的定义所在的作用域。换句话说就是它'带着'它的环境(和相关的局部变量)
def multiplier(factor):
    def multiplyByFactor(number):
        return number * factor
    return multiplyByFactor

double = multiplier(2)
print(double(5))

triple = multiplier(3)
print(triple(3))

print(multiplier(5)(4))
#类似multiplyByFactor函数存储子封闭作用域的行为叫做闭包(closure)
#外部变量在Python2中不能进行重新绑定，但是在Python3中,nonlocal关键字被引入.
#它与global关键字类似，可以让用户对外部作用域(并非全局作用域)的变量进行赋值

print();print()

#递归(终于到递归了)
#两个讲了一万年的例子:阶乘和幂
def factorial(n):
    if n == 1: return 1
    return n * factorial(n - 1)

def power(x, n):
    if n == 0: return 1
    return x * power(x, n - 1)

#二分查找的例子
def search(sequence, number, lower, upper):
    if lower == upper:
        assert number == sequence[upper]
        return upper
    else:
        mid = (lower + upper) // 2
        if number > sequence[middle]:
            return search(sequence, number, mid + 1, upper)
        else:
            return search(sequence, number, lower, mid)

#标准库中有bisect模块可以非常有效的实现二分查找



#这章最后还讲了'函数式编程' 我理解为面向过程的编程
#最后这一段话我没看懂 先留在这
#这章很长再加上花了很大力气弄懂了两个问题 真是累死了








