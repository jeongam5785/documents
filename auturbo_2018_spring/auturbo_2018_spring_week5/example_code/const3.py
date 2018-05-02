import tensorflow as tf

const1 = tf.constant([10,20,30], dtype=tf.float32)
const2 = tf.constant([20,30,40], dtype=tf.float32)

const3 = const1 + const2

sess=tf.Session()
result = sess.run(const3)

print result
