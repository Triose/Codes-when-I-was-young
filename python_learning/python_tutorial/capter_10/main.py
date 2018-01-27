import os

# get 当前工作路径
print(os.getcwd())

# 改变当前工作路径
# os.chdir("/home/triose/")
# 调用系统接口在当前工作路径下创建文件夹
# os.system("mkdir pythonDirTest")

print();print()

# 返回os中所有的模块
# print(dir(os))

print();print()

# 有一个高级的模块做文件操作---shutil
# 以下分别为copyfile和move的用法，前者是源文件 后者是目标文件地址
import shutil
# shutil.copyfile('/home/triose/140824209/140824209_part1.Rmd', '/home/triose/git_reps/Codes-when-I-was-young/python_learning/capter_10/testfile.txt')
# shutil.move('/home/triose/git_reps/Codes-when-I-was-young/python_learning/capter_10/testfile.txt', '/home/triose/asdf.txt')

print();print()

# glob提供了根据通配符查找的功能
import glob
print(glob.glob("*.py"))        # glob函数返回一个列表

print();print()

# 接收命令行参数
import sys
print(sys.argv)     # 返回一个列表 第0项是程序的名字 从第1项开始为参数内容

print();print()

# 和C&C++一样, python也有标准输入(stdin),标准输出(stdout),和标准错误(stderr)
# sys.stderr.write("PUT SOME ERROR INFORMATION HERE")
# 可以用sys.exit()终止脚本
# sys.exit()

print();print()

# re模块提供了通配符操作
import re
print(re.findall(r"\bf[a-z]*", "which foot or hand fell fastest"))          # 找所有f开头的部分

print();print()

# math模块
import math
print(math.cos(math.pi))
print(math.log(1024, 2))        # 第一个是对数 第二是是底数
print(math.log2(1024))

print();print()

# random模块做随机选择
import random
print(random.choice(['apple', 'pear', 'banana']))       # 从列表里随机选择一个数
print(random.sample(range(100, 150), 20))               # 取样20个
print(random.random())                                  # 随机出一个float类型的数
print(random.randrange(6))                              # 从range(6)中随机出一个整数

print();print()

# 统计模块
import statistics
data = [2.75, 1.75, 1.25, 0.25, 1.25, 3.5]
print(statistics.mean(data))                # 求平均
print(statistics.median(data))              # 中位数

print();print()

# 访问网络
# 有许多模块可用于访问网络，其中最简单的两个就是 urllib.request-用于从url取回数据;smtplib-发邮件
'''
这段好像有问题 先存疑
from urllib.request import urlopen
with urlopen('http://tycho.usno.navy.mil/cgi-bin/timer.pl') as response:
    for line in response:
        line = line.decode('utf-8')
        if 'EST' in line or 'EDT' in line:
            print(line)
'''
print()
'''
发邮件这段写在sending_email.py里
import smtplib
import email.mime.multipart
import email.mime.text

msg = email.mime.multipart.MIMEMultipart()
msg.['from'] = 'triose@163.com'
msg['to'] = 

'''


print();print()

# 日期和时间
from datetime import date
now = date.today()
print(now)


print(now.strftime("%m----%d----%y"))

print();print()

# 数据压缩
# 今天到这 不想打了


















