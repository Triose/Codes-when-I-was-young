
#序列有6种类型，其中有列表和元组(列表可修改，元组不行)

#序列:
edward = ['Edward Gumby', 42]
print(edward)   #可以print
john = ['John Smith', 50]
database = [edward, john]
print(database) #相当于二维

#通用序列操作:(索引indexing, 分片slicing, 加adding, 乘multiplying, 映射mapping, 成员资格 etc)

#indexing:
greeting = "Hello"
print(greeting[0])
print(greeting[-1])
print('Hello'[0])   #这样也行
#   forth = input('Year: ')[3]
#   print(forth)        #那我输入就可以直接输入第4个数


#下面是一段注释
'''months = [
        'January',
        'February',
        'March',
        'April',
        'May',
        'June',
        'July',
        'August',
        'September',
        'October',
        'November',
        'December'
]
ending = ['st', 'nd', 'rd'] + 17 * ['th'] \
        + ['st', 'nd', 'rd'] + 7 * ['th'] \
        + ['st']
year = input('Year: ')
month = input('Month(1 - 12): ')
day = input('Day(1-31): ')

month_number = int(month)
day_number = int(day)

month_name = months[month_number - 1]
ordinal = day + ending[day_number - 1]

print(month_name + ' ' + ordinal + ' ' + year) '''

#分片
tag = '<a href="http://www.python.org">Python web site</a>'
print(tag[9 : 30])  #[)这种形式,如果查找first appear的话，容易输出first appear位置之前的内容
#   print(tag[9] + " " + tag[30])
print(tag[32 : -4]) #仍然是从左到右
#   print(tag[32] + " " + tag[-4])

numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(numbers[3 : 6])
print(numbers[0 : 1])
#访问后3个元素:
print(numbers[7 : 10])
print(numbers[-3 : 0])      #这样不行
print(numbers[-3 : ])       #直到结束
print(numbers[ : 3])       #从0开始


#一个小例子(提取URL 的 domain)
#   domain = input("Please enter the url: ")[11 : -4]
#   print("Domain name: " + domain);

#步长这个东西相当于 for(int i = a, i < b; i += sl)
print(numbers[0: : 2])      #通过设置步长steplength来输出想要的数(例如奇数) 相当于 i += steplength
print(numbers[0: : 3])      #步长默认为1,可以显式给定
print(numbers[5: : -1])     #步长可以是负数(这时是逆序输出) 这时开始点必须大于结束点

#序列可以相加(相同类型)
x = [1, 2, 3]
y = [4, 5, 6]
print(x + y)

#乘法
mystr = "Sth important " * 3
print(mystr)
#None表示没有值
emptylist = [None] * 10     #10个单位空间
print(emptylist)

#一个小例子 序列(字符串)乘法示例
'''sentence = input("Sentence: ")

screen_width = 80
text_width = len(sentence)  #字符串长度
box_width = text_width + 6
left_margin = (screen_width - box_width) // 2

print()
print(' ' * left_margin + '+' + '-' * (box_width - 2) + '+')
print(' ' * left_margin + '| ' + ' ' * text_width + ' |')
print(' ' * left_margin + '| ' + sentence + ' |')
print(' ' * left_margin + '| ' + ' ' * text_width + ' |')
print(' ' * left_margin + '+ ' + '-' * (box_width - 2) + '+')
print()'''

#成员资格
permission = "rw"
print('w' in permission)
print("x" in permission)

#   users = ["mlh", "foo", "bar"]
#   usr = input("Enter your user name: ")
#   print(usr in users)

#check 用户名和密码:
'''database = [
        ['albert', '1234'],
        ['dilbert', '4242'],
]
username = input("Input your username here: ")
pin = input("PIN code: ")
if [username, pin] in database: print('Access granted!')
else : print("Access rejected!")'''

#长度，最小值，最大值
print(len(numbers))
print(min(numbers))
print(max(numbers))






#列表(可修改)
print(list("hello"))

#列表基本操作(所有之前的序列的基本操作，列表全部可以用)

#赋值
x = [1, 1, 1]
x[1] = 2
x[2] = 3
print(x)

#删除
names = ["Alice", "Beth", "Cecil", "Dee-Dee", "Earl"]
del names[2]
print(names)
print(len(names))       #彻底删除

#分片赋值
name = list('Perl')
print(name)
name[2: ] = list('arxxxxxx')    #可以长度不等
name[2: 3] = list('yyyyyyy')    #这样居然也可以
print(name)

#插入一段也是可行的
numbers = [1, 5]
numbers[1: 1] = [2, 3, 4]
print(numbers)                  #并不会替换
print(numbers[0 : : 2] )
#列表基本操作到此结束

#列表方法: (方法与对象紧密相连的函数)
#1.append 追加新对象
numbers.append(6)
print(numbers)  #append不是返回新对象，而是直接修改

#2.count 统计某个东西出现的次数
print(numbers.count(1))

#3.extend 追加一个序列, 直接修改，而不是返回新对象
x = [1, 2, 3]
y = [2, 4, 6, 8, 10]
x.extend(y)
print(x)

#4.index 查找某元素位置
knights = ["We", "are", "the", "knights", "who", "say", "ni"]
print(knights.index("are"))     #数组下标
#但是,元素不存在时会报错。可以这样避免, EG:
#   mystr = input("Input the string you want to find: ")
#   if knights.count(mystr) > 0: print("Index of " + mystr + " is " + str(knights.index(mystr))
#   else : print("Not founded!")

#5.insert 插入元素
numbers = [1, 2, 3, 5]
numbers.insert(3, 'four')       #insert(a, b) 往numbers[a]插入b
print(numbers)

#6.pop 移除idx位置或者最后一个元素
print(numbers.pop(4))           #既改变又有返回值
print(numbers.pop())
print(numbers)

#栈操作:
numbers.append(numbers.pop(0))
print(numbers)

#队列操作:
numbers.insert(0, numbers.pop())
print(numbers)

#7.remove移除与某个值第一个匹配项 无返回值
x = ['to', 'be', 'or', 'not', 'to', 'be']
x.remove('to')
print(x)                        #不存在的元素会报错 可用上面的方法防止报错

#8.reverse逆序  无返回值
x.reverse()
print(x)

#9.sort 排序，默认升序 无返回值
x.sort()
print(x)
#注意这个:
x = [4, 3, 6, 9, 1]
#   y = x
#   y.sort()
#   print(y)
#   print(x)        #x的值也会同样改变(x和y都是对同一段内存单元的引用)
#solution:
y = x[ : ]
y.sort()
print(y)
print(x)            #这样x的值就不会改变了，因为x[:]实际上返回了一个新的列表
#列表到此结束


#元组 不可变(所以没有方法)
x = (1, 2, 3)
print(x)
print(x[1])
x = (1, )           #即使只有一个值，也得加括号
print(x)

y = 3 * (40 + 2,)
print(y)

#基本操作
#1.tuple 把序列转换为元组
x = [1, 2, 3]
print(tuple(x))

#2.分片
print(tuple(x)[0:2])

#因为元组不可边，所以它可以作为映射的key


#总结
#各项基本操作以及方法
#新函数:
#cmp(x, y)              比较两个值
#len(seq)               seq的长度
#list(seq)              把seq转换成列表
#tuple(seq)             把seq转换成元组
#max(args), min(args)   最大值和最小值
#reversed(seq)          进行反向迭代
#sorted(seq)            返回排好序的列表



