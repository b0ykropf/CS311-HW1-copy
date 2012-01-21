import numpy as np
import matplotlib.pyplot as plt

x = [
77.267,
38.672,
19.680,
9.828,
4.939,
2.456,
1.319,
0.664,
0.360,
0.196,
0.205,
0.093,
0.070,
0.064]
y = range(0,len(x))
plt.plot(y,x)
plt.xlabel('Buffer size 2^n')
plt.ylabel('Seconds')
plt.title('Buffer Size vs Copy Time')
plt.show()
