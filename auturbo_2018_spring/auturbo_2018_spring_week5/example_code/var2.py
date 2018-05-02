import tensorflow as tf

var1 = tf.Variable([10,20,30], dtype=tf.float32)

sess = tf.Session()
result = sess.run(var1)

print result
