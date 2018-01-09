
import tensorflow as tf
import os
from numpy.random import RandomState as RS

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'            # 忽略警告

batch_size = 8
w1 = tf.Variable(tf.random_normal([2, 3], stddev = 1, seed = 1))
w2 = tf.Variable(tf.random_normal([3, 1], stddev = 1, seed = 1))

x = tf.placeholder(tf.float32, shape = (None, 2), name = "x-input")
y_ = tf.placeholder(tf.float32, shape = (None, 1), name = "y-input")

a = tf.matmul(x, w1)
y = tf.matmul(a, w2)

cross_entropy = -tf.reduce_mean(
        y_ * tf.log(tf.clip_by_value(y, 1e-10, 1.0)))
train_step = tf.train.AdamOptimizer(0.001).minimize(cross_entropy)

# 随机出一个样本数据集 X包括两个分量 Y表示X的两个分量之和是否<1(是: 1, 否: 0)
rdm = RS(1)
dataset_size = 128
X = rdm.rand(dataset_size, 2)
Y = [[int(x1 + x2 < 1)] for (x1, x2) in X]
# print(X)
# print(Y)

# 创建出一个会话来运行TensorFlow程序:
with tf.Session() as sess:
    init_op = tf.global_variables_initializer()
    sess.run(init_op)
    # 这里会输出w1 和 w2(没什么意义 都是随机随出来的值)
    print(sess.run(w1))
    print(sess.run(w2))
    print()


    STEPS = 5000
    for i in range(STEPS):
        start = (i * batch_size) % dataset_size
        end = min(start + batch_size, dataset_size)

        sess.run(train_step, feed_dict = {x: X[start: end], y_: Y[start: end]})

        if i % 1000 == 0:
            # 每隔一段时间计算在所有数据上的交叉熵并且输出
            total_cross_entropy = sess.run(cross_entropy, feed_dict = {x: X, y_: Y})
            print("After %d training step(s), cross entropy on all data is %g" % (i, total_cross_entropy))
            print()

    # 输出训练后w1和w2的取值
    print(sess.run(w1))
    print(sess.run(w2))


# 至此 这么一个程序大致的过程如下:
# 定义一个神经网络结构 通过随机的参数w1, w2计算预测值(前向传播过程)
# 但是 这个预测值暂时并没有意义 需要调整w1和w2的值来 "校准" 预测值和答案(需要定义损失函数和反向传播优化算法)
# 经过大量训练之后 w1和w2的值就可用于预测新的数据
