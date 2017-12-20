
#面向对象
#封装(Encapsulation):   对外部世界隐藏对象的工作细节
#继承(Inheritance):     以通用的类为基础建立专门的类对象
#多态(Poymorphism):     意味着可以对不同类的对象使用同样的操作

#1.多态
#就算我不知道某个引用变量引用的对象是什么，仍然可以对它进行操作
#而且操作会因对象(或类)类型不同而表现出不同的行为

#EG:
from random import choice
x = choice(["hello world", [1, 2, 'e', 'e', 4]])    #choice函数会在参数中随机选择一个返回
print(x.count('e'))                                 #无论返回的是哪个都可以使用count方法
#这个例子中，无论choice返回的是"hello world"字符串,或者是[]列表,都可以无差别的调用count方法,不需要检测类型

print();print()

#任何不知道对象到底是什么类型,但是又要对对象"做点什么"的时候,都会用到多态
#EG: '+'这个操作符
print(1 + 2)
print('Fish' + 'license')
# '+'对数字、字符串...都能起作用 那么可以把它定义成如下形式:
def add(a, b):      #看起来没什么用,不过它却可以传入任何支持加法的对象
    return a + b

print(add(1,2))
print(add('Fish', 'license'))

print();print()

#EG2: 如果要编写打印长度信息的函数,只需要对象具有长度(len函数可用)即可:
def length_message(x):
    print("The length of", repr(x), 'is', len(x))

length_message('Fnord')
length_message([1,2,3])

#总结一下就是: 多态就是同样的操作对于不同的对象有不同的动作

print();print()

#封装是指向程序中的其他部分隐藏对象的具体实现细节的原则
#封装与多态不同: 
#   多态能让用户对于不知道什么类型的对象进行方法调用,
#而 封装是可以不用关心对象是如何构建(对象的内部信息)而直接使用

#书上又讲了一些不用封装的时候如何标记一个对象的'名字'---存在全局变量中,
#这样一来,一旦有第二个对象也set名字之后,全局变量改变,原先的数据就丢失了
#封装使得每个对象有自己的属性('attribute'),对象之间相互独立,能够很好的解决这个问题

print();print()

#继承: 以通用的为基础建立专门的
#其实是这么来的,如果想建立一个新类(这时已经有和它类似的类--暂时就叫旧类),比旧类多了几个新方法
#在建立的时候我不想把和旧类相似的代码复制粘贴该怎么办?
#再细说一点就是:我现在有一个类叫做Shape可以在屏幕上画出图像
#但是我现在想新创建一个类Rectangle,它既能在屏幕上画出图像,也能计算该形状的面积
#如果我不想把Shape中的代码复制到Rectangle中的话,可以让Rectangle继承Shape然后再添加计算面积的方法
#当Rectangle对象调用draw()画图像的时候,程序会自动从Shape类调用该方法

print();print()     #这章理论性的东西较多,这一行只用来分隔不同的内容,而不是输出

#类:    即是一种对象的集合, 比如说鸟类就是所有鸟的集合;
#对象:  即是类的实例,比如说鸟就是鸟类的实例
#超类和子类:    例如:百灵鸟和鸟类---百灵鸟是鸟类的子类;鸟类是百灵鸟类的超类或者父类

#一个操作的例子:
#鸟类Bird可以飞于是就有fly()方法,企鹅Penguin是鸟类的子类,理论上可以也继承了fly这一方法,但是企鹅并不会飞
#这样,在创建Penguin类时就需要重写(override)超类的fly方法,重写成:什么都不做 or 异常

print();print()

#自己创建类
class Person:
    def setName(self, name):        #self 相当于this指针
        self.name = name

    def getName(this):              #不一定非得叫self 也可以叫this或者其他
        return this.name

    def greet(self):
        print("Hello, world! I'm %s." % self.name)


foo = Person()
foo.setName('Triose')   #自动把自己当成第一个参数传入
bar = Person()
bar.setName('MICH')
print(foo.getName())
print(bar.getName())
foo.greet()
bar.greet()
print(foo.name)         #特征同样可以在外部访问

#一种神奇的看法: 如果知道foo是Person的子类的话,可以把foo.greet()看做Person.greet(foo)

print();print()

#特征、函数和方法
#方法和函数不一样,方法绑定对象而函数不绑定
#方法可以绑定在一个普通函数上:
class Class:
    def method(self):
        print("I have a self!")

def function():
    print("I don't...")

instance = Class()
instance.method()

instance.method = function
instance.method()
print()
#同理,可以使用其他变量引用同一个方法:
class Bird:
    song = 'BBBBBBBB'
    def sing(self):
        print(self.song)

bird = Bird()
bird.sing()
birdsong = bird.sing
birdsong()

print();print()

#私有化:
#一个类的属性可以有两种方法访问:
#   (1)class.attribute      (2)class.setAttribute() class.getAttribute() 即setter & getter
#但是有时我们并不希望别人通过(1)这种形式访问
#这时我们把属性设置成私有(private),别人就无法通过第一种方式访问了
#例如Java中的成员资格就有public/private/protected..
#但是Python并没有直接支持私有的方式,不过通过一些小技巧可以达到私有特征的效果
#为了让方法或者特性变为私有,只需要在它名字前加上双下划线:__ EG:
class Secretive:
    def __inaccessible(self):
        print("But you can't see me")

    def accassible(self):
        print("The secret message is:")
        self.__inaccessible()

secretive = Secretive()
#这样会报错
#   secretive.__inaccessible()
secretive.accassible()
#其实即便加上了双下划线也是可以硬生生的调用的,例如:
secretive._Secretive__inaccessible()
#但是这至少制造了障碍,让调用的人明白写程序的人并不想让你调用

print();print()

#类的命名空间:
#引例:以下两个函数等价
def foo(x): return x * x
foo = lambda x: x * x       #函数定义的简写
print(foo(10))
#这两个函数执行同样的功能,并且该函数在全局范围定义,也可处于局部的函数或方法内
#定义类的时候同样的事情也会发生,所有位于class语句中的代码都在特殊的命名空间中执行---类命名空间(class namespace)
#该命名空间可由类内所有成员访问
#并不是所有Python程序员都知道类的定义其实就是执行代码块,这一点非常有用
#比如,在类的定义区可以使用除了def之外的语句
class C:
    print("Class C being defined...")
#上面的例子只为说明class定义里可以写除了def之外的语句
print()
#下面的例子中,在类作用域里定义了一个可以供所有成员(实例)访问的变量(相当于C语言的静态变量),用来计算类的成员数量
class MemberCounter:
    members = 0
    def init(self):
        MemberCounter.members += 1      #类的变量改变,而不是某一实例的变量改变

m1 = MemberCounter()
m1.init()
print(MemberCounter.members)
m2 = MemberCounter()
m2.init()
print(MemberCounter.members)
#就像方法一样,类作用域内的变量也可以被所有实例访问:
print(m1.members)
print(m2.members)
#如果在通过某一实例改变了类对象的值,其他实例中该属性的值并不会改变(新numbers的值绑定到了改变它的变量中)
m1.members = 'hello'
print(m2.members)

print();print()

#今天到这吧


