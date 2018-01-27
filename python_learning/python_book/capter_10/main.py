# 模块的使用方法(已经写了一个hello.py在同一个文件夹中)        #  1
import sys                               #  2
sys.path.append(".")        # 除了默认路径之外 还需要从这里找模块 #  3
                                         #  4
import hello                             #  5
                                         #  6
print();print()                          #  7
                                         #  8
import hello                # 导入一次和多次是一样的 #  9
                                         # 10
print();print()                          # 11
                                         # 12
# 先写一个hello2.py的模块                       # 13
import hello2                            # 14
hello2.hello()                           # 15
                                         # 16
print();print()                          # 17
                                         # 18
# 作为模块运行？或者是作为程序导入？                      # 19
# 现在有了一个hello4(跳过了hello3)                # 20
import hello4       # 这样hello4是作为模块导入 而不是像'python hello4.py'命令那样作为主程序运行 # 21
hello4.hello()                           # 22
                                         # 23
print();print()                          # 24
                                         # 25
# get你的放模块的路径                            # 26
import pprint                            # 27
pprint.pprint(sys.path)     # 这个模块中的这个函数提供了更加智能的打印方式 # 28
# 如果你不想通过sys.path.append(dir)添加的话 可以把模块放在sys.path对应的目录里 # 29
                                         # 30
print();print()                          # 31
                                         # 32
# package                                # 33
# 现在有了一个drawing的文件夹                      # 34
import drawing                  # 会引入drawing中的__init__.py(此时colors.py和shapes.py没有被引入) # 35
import drawing.colors           # 会引入drawing中的colors.py # 36
from drawing import shapes      # 同理 会引入shapes.py # 37
                                         # 38
print();print()                          # 39
                                         # 40
# 模块中有什么？                                # 41
import copy                              # 42
                                         # 43
# 使用dir函数可以看到模块包含的内容:                    # 44
pprint.pprint(dir(copy))                 # 45
mylist = [name for name in dir(copy) if not name.startswith('_')]       # 用列表推导式过滤掉_开头的 # 46
print(mylist)                            # 47
                                         # 48
print()                                  # 49
# 上面可以看到 copy中有一个__all__文件 这个变量包含一个列表 可以打印出来查看 # 50
print(copy.__all__)                      # 51
# all是一个列表 当import copy的时候 会引入这个列表中包含的模块---Error, Copy, Deepcopy # 52
                                         # 53
print();print()                          # 54
                                         # 55
# help() get帮助                           # 56
# help(copy)        # 太长了 就注释掉了          # 57
# 相当于man一样 这个函数(help)显示的是copy.__doc__文档的内容 # 58
                                         # 59
print();print()                          # 60
                                         # 61
# 模块源代码的位置:                              # 62
print(copy.__file__)                     # 63
# 在: /usr/lib/python3.5/copy.py中 使用方法写得非常详细 # 64
                                         # 65
print();print()                          # 66
                                         # 67
# 标准库                                    # 68
                                         # 69
print()                                  # 70
                                         # 71
# 第一个必须是sys---可以让你get到与python解释器联系紧密的obj和function # 72
# help(sys)     # 具体见                    # 73
# 例如 python程序可以接收参数(像C一样,这里给出一个C的sample---sp.c) # 74
# 对sp.c执行如下命令就可查看接收的参数:                  # 75
# gcc sp.c -o sp                         # 76
# ./sp asdf 1234                         # 77
# 这里的asdf 和 1234就是sp程序接收的参数              # 78
# 程序会输出3行 分别是:                           # 79
# ./sp                                   # 80
# asdf                                   # 81
# 1234                                   # 82
# 因为argv[0]是./sp的指针 argv[1]开始才是参数的指针, argc是参数的数目 # 83
# python同理--稍简单:                         # 84
print(sys.argv)                          # 85
# 这里写了一个reverseargs.py用于逆序打印参数           # 86
import reverseargs                       # 87
reverseargs.printReversedArgs()          # 88
                                         # 89
print();print()                          # 90
                                         # 91
# os--调用操作系统接口                           # 92
# 例如os.system(command) 在操作系统shell中执行command命令 # 93
import os                                # 94
os.system("ps")     # 和在命令行里执行ps一样       # 95
# 所以python一定程度可以替代shell script           # 96
                                         # 97
print();print()                          # 98
                                         # 99
# fileinput 文件读入                         # 100
# 这段代码写在fileinputTestDrive.py中---类似Java的命名 # 102
# 傻逼一样的执行了python fileinputTestDrive.py main.py 就多出了丑的要死的行号          # 103
# 这代码没法写了,接下来的代码写在main_part2.py中                                         # 104
                                         # 105
                                         # 106
                                         # 107
                                         # 108
                                         # 109
                                         # 110

