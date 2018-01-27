
# Hello_World 程序

print("Hello world")       #在python3里，print是函数，后面要加括号

print(1 / 2)
print(1 // 2)              #前一行会转换成实数，后一行是整数除法

print(2.75 % 0.5)       #现在小数也可以取余

print(2 ** 3)           #2 ^ 3 真方便

#用户输入:
#   mystr = input("Input sth below: \n")
#   print(mystr + '.')      #自动转换还是挺方便的
#   print(mystr + 1 + '.') #这样就不行

#mystr 是字符串类型，没法%(看来某个变量的类型是固定的，没法随意转换)
#   print("The number inputed before is an")
#   if mystr % 2 == 0: print("even number.")
#   else : print("odd number.")
#

#a ** b <=> pow(a, b)
print(pow(2, 3))

print (abs(-10))        #绝对值
print (round(12.555))   #四舍五入
print (round(12.499))

#引用包测试
#   print(math.floor(32.2))     #先引用
#   import math
#   print(math.floor(32.2))

#也可引用单个函数:      #这样不需要每次都写包的名字
from math import sqrt
print(sqrt(9))          #结果是实数

#参数错误会报错
#   x = -1
#   print(sqrt(x))
#   print(sqrt(-1))

#但是当引入cmath时(里面有complex number)
import cmath
print(cmath.sqrt(-1))
print(1+2j + 3+4j)      #这样写居然可以
print((1 + 2j) + (3 + 4j))  #我觉得应该是按类型合并了把

#字符串的单引号和双引号其实没有区别
print("Hello world.")
print('Hello world.')

#转义用 '\'
print('Let\'s go.')

#字符串拼接
xstr = "Hello"
ystr = "World"
print(xstr + ' ' + ystr + '.')

#   print(1000L)    #不能这么写！
print(10000000000000000000000000000000000000000000000000)
#看来python3的确和python2不太一样，数字后面没法加L了

# str() 和 repr()
x = 123
#   print("The value of x is " + x)     #这样会出错，因为x不是字符串
print("The value of x is " + str(x))
print("The value of x is " + repr(x))
#   print("The value of x is " + `x`)   #看来也没有反引号这么一说

#input 与 raw_input
#  name = input("Whis is your name? ")
#  print("Hello " + name + "!")

#区别就是python3 里没有raw_input了，because, in python3, raw_input was renameed to "input"
#   name = raw_input("What is your name? ")
#   print("Hello " + name + "!")

#跨行的字符串
print('''This is a string which needs to use 2 lines 
to be displayed.''')
#or 转义字符转义掉了行末的换行符
print("This is a string \
that just needs to take over 1 line, but, in source file, it takes over 2 lines.")

#对\进行转义可以用\，也可以直接在前面加一个r字母全部转义
print("The path is: C:\\no1")
print(r"The path is: C:\no1")
#   print(r"this is test of \")     #用了r的话，最后一个字符不能是\

#对了 还有一个挺有意思的问题， The multiline comments does not actually exits!
#"It is ridiculous that the language designers decided to forgo this important feature already prevalent in other languages."
#哈哈哈 网友评论也很逗


#总结：

#abs(num)           绝对值
#cmath.sqrt(x)      x的平方根(这个可用于负数)
#float(x)           把x转换为浮点数
#input("This place can add a tip")      #python2中的raw_input
#pow(x, y, z)       x ^ y % z 厉害炸了，python里根本不需要专门打一个快速幂函数了(只是不知道快不快)
    #print(pow(5, 2, 7))
#round(number, ndigits)                 #给定精度四舍五入
    #print(round(1.23456, 3))
#repr(obj)          #返回字符串表示形式
#str(obj)           #转换为字符串
#虽然结果一样





