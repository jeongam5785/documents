import tensorflow as tf

const = tf.constant([10,20,30], dtype=tf.float32)

sess=tf.Session()
result = sess.run(const)

print result
