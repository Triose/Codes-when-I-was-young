
import tensorflow as tf
import os

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'            # 忽略警告

# 非线性激活函数:
# tf.nn.relu, tf.sigmoid, tf.tanh...

# TF支持使用了激活函数和偏置项的神经网络:

'''
a = tf.nn.relu(tf.matmul(x, w1) + biases1)
y = tf.nn.relu(tf.matmul(a, w2) + biases2)
'''

# 交叉熵的计算过程:
'''
cross_entropy = -tf.reduce_mean(y_ * tf.log(tf.clip_by_value(y, 1e-10, 1)))
'''

# 1、 clip_by_value函数 限定值范围:
v = tf.constant([[1.0, 2.0, 3.0], [4.0, 5.0, 6.0]])
with tf.Session() as sess:
    print(tf.clip_by_value(v, 2.5, 4.5).eval())
# 所有小于2.5的值都被修改成2.5 所有大于4.5的值都被修改为4.5

# 2、 tf.log 对张量的值依次取对数 自然对数
    print(tf.log(v).eval())

# 3、 * 交叉熵中用的不是矩阵乘法 而是元素间对应相乘



