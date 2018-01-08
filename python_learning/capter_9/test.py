
# 不要像这种形式命名变量: __future__


# 构造方法:
class FooBar:
    def __init__(self, value = 42):     # 可以有参数
        self.somevar = value

f = FooBar("adf")
print(f.somevar)

# 同理析构方法: __del__ 不过建议不使用

print();print()

# 一个继承中重写构造函数的问题:
class Bird:
    def __init__(self):
        self.hungry = True
    def eat(self):
        if self.hungry == True:
            print("Aaah...")
        else: print("No thanks")

class SongBird(Bird):
    def __init__(self):
        self.sound = "Squawk!"
    def sing(self):
        print(self.sound)

sb = SongBird()
sb.sing()           # 这里没毛病
# 但是
#   sb.eat()            #这里会出问题,提示sb没有hungry特性
# 原因是重写了构造函数导致超类的构造函数没有执行

# 两种解决方案:

print();print()
    
# 1.调用未绑定方法:
class SongBird_2(Bird):
    def __init__(self):
        Bird.__init__(self)         # 没有与实际对象绑定的方法
        self.sound = "Squawk!"
    def sing(self):
        print(self.sound)

sb2 = SongBird_2()
sb2.sing()
sb2.eat()

print()

# 2.super
class SongBird_3(Bird):
    def __init__(self):
        super(SongBird_3, self).__init__()          # 这么写
        self.sound = 'Squawk!'
    def sing(self):
        print(self.sound)

sb3 = SongBird_3()
sb3.sing()
sb3.eat()

print();print()


# 序列和映射的基本规则:
# 如果可变,则需4个方法,否则只需前两个
#   __len__(self): 长度
#   __getitem__(self, key): 求key的值
#   __setitem__(self, key, value): 把key对应到value上
#   __delitem__(self, key): 删除元素

# 例如我要构造一个序列
def checkIndex(key):
    if not isinstance(key, int): raise TypeError
    if key < 0: raise IndexError

class Seq:
    def __init__(self, start = 0, step = 1):
        self.start = start 
        self.step = step 
        self.changed = {}

    def __getitem__(self, key):
        checkIndex(key)
        
        try: return self.changed[key]
        except KeyError:
            return self.start + key * self.step 

    def __setitem__(self, key, value):
        checkIndex(key)
        self.changed[key] = value

s = Seq(0, 2)   # 对应 __init__(self, start, step)
print(s[4])     # 对应 __getitem__(self, key)
s[4] = 100      # 对应 __setitem__(self, key, value)
# del s[4]      # 对应 __delitem__(self, key) 这里没写
print(s[4])

print();print()

# 这一小节我没懂他具体意思:
class CounterList(list):
    def __init__(self, *args):
        self.cnt = 0
        super(CounterList, self).__init__(*args)
    def __getitem__(self, index):
        self.cnt += 1
        return super(CounterList, self).__getitem__(index)
# 这个类大概是这样: 在list的功能之上增加一个计数的功能,记录访问list的次数
cl = CounterList(range(10))
print(cl)
cl.reverse()
print(cl)
print(cl.cnt)           # 这里大概是想表示 ‘我访问了list却没有被记录’
print(cl[3] + cl[5])    # 这里意思是 我访问了两次list 并且被记录了下来
print(cl.cnt)

print();print()

# 一个问题和一种方案
# 假设有如下类和如下方法:
class Rectangle:
    def __init__(self):
        self.width = 0
        self.height = 0
    def setSize(self, size):
        self.width, self.height = size
    def getSize(self):
        return self.width, self.height
# Rectangle中并没有size这个特性 这是我们为了方便使用假想出来的特性
r = Rectangle()
r.width = 10
r.height = 5
print(r.getSize())
r.setSize((5, 10))
print(r.getSize())
# 上面的例子中, getSize和setSize是一个名为size的假想属性的访问器方法
# 但是, 如果有一天 需要把size变成一个真实的特性 那么类的代码 和所有使用了该类的代码都需要改变
print();print()
# python能够隐藏访问器方法,让所有特性看起来一样.而这些通过访问器定义的特性被称为 '属性'
# 上面的类可以做如下改进
class Rectangle1:
    def __init__(self):
        self.width = 0 
        self.height = 0 
    def setSize(self, size):
        self.width, self.height = size
    def getSize(self):
        return self.width, self.height
    size = property(getSize, setSize)       # 这里的property创建了一个属性,其中访问器函数被用作参数

r1 = Rectangle1()
r1.setSize((10, 5))
print(r1.width, r1.height)
print(r1.size)
r1.size = 150, 100
print(r1.width, r1.height)
# 说明: property函数有4个参数: fget, fset, fdel, fdoc
# 上述四个参数分别对应4个方法

print();print()





# 装饰器这一段我看懵了{{{

# 首先来区分 实例方法、静态方法和类方法:

# 实例方法: 实例能够使用的方法: 
class Foo:
    def __init__(self, name):
        self.name = name
    def hi(self):
        print(self.name)

foo = Foo("Triose")
foo.hi()

print()

# 静态方法: 位于类的命名空间的普通函数, 不会对任何实例类型进行操作.
class Foo_1:
    def __init__(self, name):
        self.name = name
    def hi(self):
        print(self.name)
    @staticmethod
    def add(a, b):
        return a + b

foo_1 = Foo_1("MICH")
print(foo_1.add(1, 2))
foo_1.hi()
print(Foo_1.add(1, 2))

print()

# 类方法: 类方法时将类本身作为对象进行操作的方法
class Foo_2:
    name = "Cecily"
    @classmethod
    def hi(cls, x):
        print(cls.name * x)

foo_2 = Foo_2()
foo_2.name = "CCCCCC"
print(foo_2.name)
foo_2.hi(3)
Foo_2.hi(x = 3)

# 这一段先存疑}}}

print();print()

# 拦截: 4个函数
# __getattribute__(self, name):     当特性name被访问时自动被调用
# __getattr__(self, name):          当特性name被访问时且对象没有相应的特征时被自动调用
# __setattr__(self, name, value):   当试图给特性name赋值时被自动调用
# __delattr__(self, name):          当试图删除特性name时被自动调用
# EG:
class Me:
    myname = "Triose"
    age = 10
    def __init__(self, name):
        self.myname = name
    def __getattribute__(self, name):
        if name == "myname":
            print("You want to know my name")
        elif name == "gender":
            print("You want to know my gender, but I don't want to tell you")
    def __setattr__(self, name, value):
        if name == "myname":
            print("You want to rename me as", value)
        print()
    def __delattr__(self, name):
        if name == "myname":
            print("You want to delete my name")
        print()

me = Me("Triose")
# me.myname
me.gender
# me.myname = "MICH"
# del me.myname

# 今天先到这(关于装饰器和拦截器怎么用 先存疑)

print();print()

# 病了几天
# 迭代器:
class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1
    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        if self.a > 100: raise StopIteration
        return self.a
    def __iter__(self):
        return self

fibs = Fibs()
for f in fibs:
    if f < 10:
        print(f)
    else: break

print()

# 还可以用list函数把一个可迭代对象显式的转换为list对象
class TestIterator():
    def __init__(self):
        self.value = 0
    def __next__(self):
        self.value += 1
        if self.value > 10: raise StopIteration
        return self.value
    def __iter__(self):
        return self

print(list(TestIterator()))

print();print()

# 生成器
nested = [[1,2],[3,4],[5]]
# 如果要按顺序打印nested中的数字:
def flatten(nested):
    for i in nested:
        for j in i:
            yield(j)

for num in flatten(nested):
    print(num)
# 带有yield的函数叫做生成器,每次产生一个值后被冻结然后等待下一次被唤醒

print()

# 展开任意维度的对象:用到了递归 有点难理解 不过每次打印出nested出来就会好理解很多
def flatten_1(nested):
    # 排除字符串
    try:
        nested + ' '
    except TypeError: pass
    else: raise TypeError

    try:
        for subset in nested:
            for item in flatten_1(subset):
                yield(item)
    except TypeError:
        yield(nested)

nested = [[1,2,[3, 4, 5]]]
print(list(flatten_1(nested)))


print();print()

def repeater(value):
    while True:
        new = (yield value)
        if new is not None: value = new

r = repeater(42)
print(r.__next__())
r.send("hello world")
print(r.__next__())

# 上面是生成器的使用

print();print()

# 八皇后--见nquene.py




