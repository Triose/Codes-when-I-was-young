
#首先，字符串不可变，所以不能赋值(下面注释的代码是不合法的)
#   website = 'http://www.python.org'
#   website[-3:] = 'com'
#   print(website)

#格式化这个东西特别好，例如
source = "Hello, %s. %s enough for ya?"     #s是说明符
values = ('world', 'Hot')       #这是一个元组
print(source % values)
#   print(source % "world")     #不匹配(需要两个却只提供了一个)

mylist = [1,2,3,4,5]
values = ('world', mylist)
print(source % values)          #这样也可以

source = "The answer is %d."
x = int(123)
print(source % (x + 1))         #这样也可以

source = "Hello %% %s"           #如果被格式化的串中有%，则要用%%替代
value = "triose"
print(source % value)

source = "Pi with three decimals: %.3f"     #保留3位小数
from math import pi
print(source % pi)


#string模块自带的一种格式化值的方法
from string import Template         #这里出了一个小bug
#因为本来这个代码文件的名字叫做string.py，所以执行到这一句的时候会出现'cannot import name 'Template'',把名字改了就好了
s = Template('$x, glorious $x!')
print(s.substitute(x = 'slurm'))

#如果只替换一部分的话，需要用{}来表明起始和结束:
s = Template("It's ${x}tastic!")
print(s.substitute(x = 'slurm'))

#同理 用$$插入美元符号
s = Template("Make $$ selling $x!")
print(s.substitute(x = 'slurm'))

#除了关键字参数之外，还可以用字典变量提供value-key的键值对
s = Template("A $person must never $dowhat.")
d = {}
d['person'] = 'gentleman'
d['dowhat'] = 'show his socks'
print(d)
print(s.substitute(d))
#   print(s.safe_substitute(d))     #safe_substitute方法不会因为缺少一个参数而报错

#如果字符串格式化的右操作数是元组的话，其中的每一个元素都会被单独格式化：
s = "%d plus %d equals %d."
print(s % (1, 1, 2))

print();print()

#字符串的格式化转换类型：
#d, i:      带符号的十进制整数
#o:         不带符号的八进制
#u:         不带符号的十进制
#x:         不带符号的十六进制(小写)
#X:         同上(大写)
#e:         科学计数法表示的浮点数(小写)
#E:         同上(大写)
#g:         如果指数大于-4或者小于精度值则和e相同，其他情况与f相同
#G:         同上(E,F)
#C:         单字符
#r:         字符串(repr转换任意Python对象)
#s:         字符串(str...)

#例子:
print('Price of eggs: $%d.' % 42)
print('Hexadecimal price of eggs: %X.' % 42)
print('PI: %f.' % pi)
print('Very inexact estimate of pi: %i.' % pi)
print("Using str: %s." % 42)
print('Using repr: %r.' % 42)

print();print()

#字符串宽度和精度 %A.B   A:总位数， B:精度
print("%10.8f" % pi)
print('%.5s' % 'hello world')
#也可以用*来作为字段宽度或者精度，这是数值会从元组参数中读出
print('%*.*f' % (10, 8, pi))

print();print()

#符号、对齐和用0填充
print('%010.2f' % pi)       #用0填充
print('%-10.2f' % pi)       #左对齐
print('%-+10.2f' % pi)       #不论正负都标明符号

print();print()

#一个例子 用给定的宽度打印价格表    不用去纠结怎么设计的表格 看懂代码就好
#width = int(input('Please enter width: '))
width = 35

price_width = 10
item_width = width - price_width

header_format = '%-*s%*s'
format = '%-*s%*.2f'

print('=' * width)

print (header_format % (item_width, 'Item', price_width, 'Price'))

print('-' * width)

print(format % (item_width, 'Apples', price_width, 0.4))
print(format % (item_width, 'Pears', price_width, 0.5))
print(format % (item_width, 'Cantaloupes', price_width, 1.92))
print(format % (item_width, 'Dried Apricots(16 oz.)', price_width, 8))
print(format % (item_width, 'Prunes(4 lbs.)', price_width, 12))

print('=' * width)

print();print()

#字符串方法

#find:返回字串所在位置的最左端的索引,没有则返回-1
s = "With a moo-moo here, and a moo-moo there"
print(s.find('moo'))
print(s[s.find('moo') : s.find('moo') + 3])
print(s.find('python'))
print(s.find('moo', 10, 16))        #可提供开始点和结束点

print();print()

#join:是split的逆方法，用来连接序列中的元素
seq = ['1','2', '3', '4', '5']
sep = '+'
print(sep.join(seq))        #这个厉害了！

print();print()

#lower:返回字符串的小写字母版
s = "Hello world."
print(s.lower())
#title:所有首字母大写
print(s.title())

print();print()

#replace:替换所有匹配项
s = "This is a test"
print(s.replace('is', 'ezz'))

print();print()

#splict:根据xxx分割
print('1+2+3+4+5'.split('+'))   #分割成序列

#strip:去除两侧空格
print('          Hello World.           '.strip())

print();print()

#translate:替换字符串中的某些部分(只处理单个字符)，可以同时替换多个
#首先得有一个转换表---用maketrans函数
#两个参数分别为两个等长的字符串，用后一个的某个位置上的字母替换前一个对应位置的字母
#不过python3里面好像有点变动 下次再补上

#这章没有小结





















