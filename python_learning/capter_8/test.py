
#异常
#本章介绍如何创建和引发自定义的异常,以及处理异常的各种方法

#是什么?
#Python用异常对象(exception object)来表示异常情况。遇到错误(例如除0等)后会引发异常。
#如果异常对象并未被处理或捕捉,程序就会用回溯(traceback,一种错误信息)终止执行:
#EG:
#   print(1/0)
#异常不止是错误信息的提示,而是一些类的实例--本例中就是ZeroDivisionError的实例
#这些实例可以被引发,并且可以用很多种方法进行捕捉,使得程序可以捉住错误并且对其进行处理,而不是让程序终止

#怎样引发异常?
#raise语句
#为了引发异常,可以使用一个类(通常是Exception的子类)或者实例参数调用raise语句,程序就会创建类的一个实例
#EG:
#   raise Exception('This is an unknown exception')     #括号内是错误提示信息

#一些最重要的內建异常(build-in exception)
#Exception                              所有异常的基类
#AttributeError                         特征引用或者赋值失败时引发
#IOError                                试图打开不存在的文件(包括其他情况)的时候引发
#IndexError                             使用序列中不存在的索引时引发
#KeyError                               使用映射中不存在的key时引发
#NameError                              找不到名字(变量)时引发
#SyntaxError                            语法不对时引发
#TypeError                              在內建操作或者函数应用于错误类型的对象时引发
#ValueError                             在內建操作或者函数应用于正确类型的对象,但是该对象使用不合适的值的时引发
#ZeroDivisionError                      除0或者对0取模时引发

print();print()

#自定义异常类: 如果想用特殊的错误处理代码处理某一问题时,就需要一个独立于exceptions模块的异常类
class ASimpleException(Exception): pass

#捕捉异常: try/except
#EG:
'''
try:
    x = int(input('Enter the first number: '))
    y = int(input('Enter the second number: '))
    print(x / y)
except ZeroDivisionError:
    print("The second number cannot be zero!")
'''

print()

#'屏蔽'异常:捕捉了不处理的话 异常就会一直传递下去
#假如要做一个计算器,当用户输入分母为0时, 如果muffled = true 则返回None,而不是结束程序; 反之则报错。可以这么写:

'''
class MuffledCalculator:
    muffled = False
    def calc(self, expr):
        try:
            return eval(expr)
        except ZeroDivisionError:
            if self.muffled:
                print('Division by zero is illegal')
            else:
                raise
        except TypeError:           #可以捕捉多个异常
            print("Please input an integer")

    def open(self):
        self.muffled = True

mf = MuffledCalculator()
mf.open()           #默认关闭,可以不加这句话
mf.calc("1 / 0")
mf.calc("1 / 'hello'")
'''

#也可以用一个块捕捉多个异常类型:
'''
try:
    x = int(input("Enter the first number: "))
    y = int(input("Enter the second number: "))     #输入0, asdf试试

    print(x / y)

except (ZeroDivisionError, TypeError, NameError, ValueError):
    print("Your numbers were bogus...")
'''

print();print()

#捕捉异常对象:
'''
try:
    x = int(input("Enter the first number: "))
    y = int(input("Enter the second number: "))

    print(x / y)

except (ZeroDivisionError, ValueError) as e:        #Python3用as替代了原来的,
    print(e)
'''

print();print()

#全部捕捉!
'''
try:
    x = int(input("Enter the first number: "))
    y = int(input("Enter the second number: "))

    print(x / y)

except :                #因为系统提供的异常类型可能无法覆盖到所有可能出现的异常,所以你也可以全部捕捉
    print("Something wrong happened!")
'''
#但是这样非常危险,这种捕捉方式会捕捉用户ctrl + d结束进程的举动并作为异常报错
#这时还是用 except Exception as e 比较好

print();print()

#没有异常出现时也可以用else
#例如 我想输入两个数,如果输入数据会导致异常,程序会要求用户重新输入,直到数据正确为止
'''
while True:
    try:
        x = int(input("Enter the first number: "))
        y = int(input("Enter the second number: "))

        print(x / y)
    except (ZeroDivisionError, ValueError) as e:
        print(e)
        print("Please enter again!")
    else:
        break
'''

print();print()

#最后---finally
#与try联合使用(像Java里一样) 无论是否有异常该代码块中的语句都会被执行
'''
x = None
try:
    x = 1 / 0
finally:
    print('Cleaning up...')
    del(x)
'''
#把x = None定义在try外面是因为x = 1 / 0会出现异常从而导致x这个变量不存在,finally块里就无法删除
#出现这种情况时,finally里的异常无法被捕捉
print()
#finally可以和try、except、else组合使用:
'''
try:
    print(1 / 0)
except NameError:
    print("Unknown variable")
else:
    print("That went well")
finally:
    print("Cleaning up...")
'''

print();print()

#函数内的异常的'传播'过程:
#如果函数内出现异常并且没有被处理,那么该异常会传播到该函数调用的地方.
#如果一直没有被处理,他就会一直传播,直到主程序.
#如果在主程序中还没有被处理,程序就会带着栈跟踪终止
#EG:
'''
def faulty():
    raise Exception("Sth is wrong")

def ignore_exception():
    faulty()

def handle_exception():
    try:
        faulty()
    except:
        print('Exception handled')

handle_exception()
print()
ignore_exception()
'''

print();print()

#异常的'细致'用法:
#EG:假设我们希望打印出字典中特定的键值对,如果该键不存在,则不打印.可以这么写:
def describePerson(person):
    print('Description of ', person['name'])
    print('Age:', person['age'])
    if 'occupation' in person:      #这里效率很低,查找了两次, 一次查找occupation是否存在,一次输出的时候查找值
        print('Occupation:', person['occupation'])

me = {'name': 'Triose', 'age': 22}
describePerson(me)
print()
#另外一种解决办法:
def describePerson2(person):
    print('Description of ', person['name'])
    print('Age:', person['age'])
    try:
        print('Occupation:' +  person['occupation'])
    except KeyError: pass

describePerson2(me)



#总结:
#异常对象           异常情况可以用异常对象来表示.它们可以用几种方法处理,不处理的话程序就会终止
#警告               警告类似与异常,但是一般仅打印错误信息
#引发异常           用raise语句引发异常.参数是异常类或者异常实例.还能够提供异常和错误信息做参数
#自定义异常类       继承Exception即可
#捕捉异常           try + except + else + finally
#异常和函数         在函数内引发异常时,它会传播到函数调用的地方



