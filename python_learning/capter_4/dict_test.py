
#字典是Python里唯一內建的mapping类型，key可以是数字、字符串甚至是元组


#如果要存储一个名单，以及名单上的人的生日，可以这么做:
names = ['Alice', 'Beth', 'Cecil', 'Dee-Dee', 'Earl']
dates = ['950105', '950106', '950107', '950108', '950109']
print(dates[names.index('Cecil')])
#但是这么做并不是很方便

#那么就使用字典
datedict = {'Alice' : '950105', 'Beth' : '950106', 'Cecil' : '950107'}
print(datedict['Cecil'])

print();print()

#dict类型
items = [('name', 'Gumby'), ('age', 42)]
d = dict(items)
print(d)

dd = dict(d)        #这个不是浅拷贝
dd['age'] = 50
print(d)
print(dd)

print();print()

#基本操作

#len:返回d中的项数
#d[k]:返回k的value
#d[k]=v:赋值
#del d[k]:删除key为k的项
#k in d:检查d中是否有键值为k的项
#key的类型可以是任意不可变类型
#假设某key原先不在字典中，对其赋值后，字典会自动添加该键值对
#k in d查找的是key是否在字典中，而不是值， 但是v in l查找的是v是否在list中
#在字典中查找比在列表中查找更高效(因为hash)

#如下注释代码不合法:
#   x = []
#   x[42] = 'Foobar'

#但是这样就可以:
x = {}
x[42] = 'Foobar'
print(x)

print();print()

#A simple database
people = {
        'Alice': {
            'phone': '2341',
            'addr': 'Foo drive 23'
            },
        'Beth':{
            'phone': '9102',
            'addr': 'Bar street 42'
            },
        'Cecil': {
            'phone': '3158',
            'addr': 'Baz avenue 90'
            }
        }
labels = {
        'phone': 'phone numbers',
        'addr': 'address'
        }
#   name = input("Name: ")
#   request = input('Phone number(p) or address(a)?')

#   if request == 'p': key = 'phone'
#   if request == 'r': key = 'addr'

#   if name in people: print("%s's %s is %s" % (name, labels[key], people[name][key]))

print();print()

#字典的格式化字符串
phonebook = {'Beth': '9102', 'Alice': '2341', 'Cecil': '3258'}
print("Cecil's phone number is %(Cecil)s." % phonebook)         #会直接输出键值，非常酷

print();print()

#字典的方法:
#1.clear:清除所有项
d = {}
d['name'] = 'Gumby'
d['age'] = 42
print(d)
d.clear()
print(d)

print();print()

#比较下面两个例子(关于引用变量的问题)

#EG1
x = {}
y = x
x['key'] = 'value'
print(y)
x = {}
print(y)

print()

#EG2
x = {}
y = x
x['key'] = 'value'
print(y)
x.clear()
print(y)

print();print()

#2.copy:返回一个具有相同键值对的新字典(浅拷贝),值可以替换，但是不能修改(否则原字典也会随之修改)
x = {'username': 'admin', 'machines': ['foo', 'bar', 'baz']}
y = x.copy()
y['username'] = 'mlh'           #这里是替换
y['machines'].remove('bar')     #这里是修改
print(y)
print()
print(x)

print();print()

#深拷贝: copy模块里的deepcopy()
from copy import deepcopy
d = {}
d['name'] = ['Alfred', 'Bertrand']
c = d.copy()
dc = deepcopy(d)
d['name'].append('clive')
print(c)                    #c是d经过浅拷贝生成的副本，所以c修改后d也会随之修改
print(d)
print(dc)                   #dc是c经过深拷贝生成的副本，所以无论c怎么改，dc不会变

print();print()

#3.fromkeys:用给定的key建立新字典，新字典的每个key都对应值None
dc = d.fromkeys(['Alfred', 'Bertrand'], 'Unknown')      #可以指定对应的值，默认是None
print(dc)

#4.get:更加宽松的访问字典的方法(key不存在与字典中时，不会出错)
#   print(dc['Cecil'])      #这句会显示key不合法
print(dc.get('Cecil'))

#字典方法示例
'''people = {
        'Alice': {
            'phone': '2341',
            'addr': 'Foo drive 23'
            },
        'Beth': {
            'phone': '9102',
            'addr': 'Bar street 42'
            },
        'Cecil': {
            'phone': '3158',
            'addr': 'Baz avenue 90'
            }
        }
lables = {
        'phone': 'phone number',
        'addr': 'address'
}

name = input('Name: ')

request = input('Phone number (p) or address (a)')

key = request
if request == 'p': key = 'phone'
if request == 'a': key = 'addr'

person = people.get(name, {})
label = labels.get(key, key)
result = person.get(key, 'not available')       #如果不存在key，结果就为'not available'

print("%s's %s is %s." % (name, label, result))

print();print()'''

#5.has_key:python3里并没有，用来查找是否含有特定的key

#6.items和iteritems:items将字典所有的项以列表的方式返回;iteritems返回一个迭代器
d = {'title': 'Python Web Site', 'url': 'http://www.python.org', 'spam': 0}
print(d.items())

#   it = d.iteritems()      #python3可能没有这个
#   print(list(it))

print();print()
#7.keys和iterkeys:将key以列表的形式返回
print(d.keys())

#   it = d.iterkeys()       #这个可能也没有
#   print(list(it))

print();print()

#8.pop:通过key移除键值对
dd = {'x': 1, 'y':2}
dd.pop('x')
print(dd)

print();print()

#9.popitem:弹出一个键值对(不确定是哪个)
print(d.popitem())
print(d)

print();print()

#10.setdefault:感觉和get一样，不设定默认且不存在的话会是None
print(d.get('title', 'N/A'))
print(d.setdefault('title', 'N/A'))

print(d.get('url', 'N/A'))
print(d.setdefault('url', 'N/A'))

print();print()

#11.update:用一个字典更新另外一个字典
d = {
        'title': 'Python Web Site',
        'url': 'http://www.python.org',
        'changed': 'Mar 14 22:09:15 MET 2008'
}
x = {
        'title': 'Python Language Website',
        'detail': 'No detail'
}
d.update(x)         #把对应项更新,没有对应的话就添加
print(d)

print();print()

#12.values和itervalues:返回值的列表(值可以重复)
d = {}
d[1] = 1
d[2] = 2
d[3] = 3
d[4] = 1
print(d.values())
#   print(d.itervalues())   #好像python3没有

#小结:
#什么叫映射
#用字典格式化字符串 '%(key)s' % dict
#字典的基本操作和方法
#新函数:
#dict(seq):         用键值对建立字典

