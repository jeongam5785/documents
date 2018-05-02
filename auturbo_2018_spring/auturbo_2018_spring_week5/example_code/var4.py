import tensorflow as tf

var1 = tf.Variable([10,20,30], dtype=tf.float32)
var2 = tf.Variable([20,30,40], dtype=tf.float32)
result = var1 + var2

sess = tf.Session()
init = tf.global_variables_initializer();
sess.run(init)
result = sess.run(result)

print result
