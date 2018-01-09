import os
import tensorflow as tf

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'            # 忽略警告

a = tf.constant([1.0, 2.0], name = "a")
b = tf.constant([2.0, 3.0], name = "b")
result = a + b
sess = tf.Session()
print(sess.run(result))
sess.close()

# 以上的代码定义了一个计算图中的计算
# tensorflow会自动把定义的计算转换为计算图上的节点
# 通过x.graph可以查看张量所属的计算图
# tf.get_default_graph函数获取当前默认的计算图

print(); print()

# tf.Graph函数可以生成新的计算图,不同图上的张量和运算都不会共享

g1 = tf.Graph()
with g1.as_default():
    v = tf.get_variable("v", initializer = tf.zeros_initializer()(shape = [1]))

g2 = tf.Graph()
with g2.as_default():
    v = tf.get_variable("v", initializer = tf.ones_initializer()(shape = [1]))

with tf.Session(graph = g1) as sess:
    tf.global_variables_initializer().run()
    with tf.variable_scope("", reuse = True):
        print(sess.run(tf.get_variable("v")))


with tf.Session(graph = g2) as sess:
    tf.global_variables_initializer().run()
    with tf.variable_scope("", reuse = True):
        print(sess.run(tf.get_variable("v")))

# 以上一段用来说明 不同计算图中定义的相同名字的变量相互独立

print();print()

# 张量是对运算结果的引用 不是具体数值(可以理解为对定义的运算结果的引用)
a = tf.constant([1.0, 2.0], name = "a")
b = tf.constant([2.0, 3.0], name = "b")
c = tf.constant([3.0, 4.0], name = "c")
result = tf.add(a, b, name = "add")
result2 = tf.add(b, c, name = "add")
print(result, result2)

# TensorFlow 通过session(会话)来执行定义好的计算
# 当所有计算完成后,需要关闭会话-> sess.close() 否则会有资源泄露的问题
# 当程序异常结束时,可能执行不到sess.close()语句 所以可以通过Python的上下文管理器来管理这个会话:
''' 这样写就不需要显式的写出sess.close()语句 上下文结束时 会自动执行该语句
with tf.Session() as sess:
    # 计算过程
    sess.run(xxxxxx)
'''

# 可以有默认会话 不过需要手动设置
sess = tf.Session()
with sess.as_default():
    print(result.eval())            # 因为有了默认会话 所以不需要sess.run(xxx) 只用 tensor.eval()就可以执行计算过程

# 也可以这样:
print(result.eval(session = sess))




