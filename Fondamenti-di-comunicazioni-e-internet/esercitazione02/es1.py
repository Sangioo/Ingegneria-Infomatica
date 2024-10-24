import numpy as np
import matplotlib.pyplot as plt
from pprint import pprint

T_MIN = -5
T_MAX = 5
CAMPIONI = 1000
t = np.linspace(T_MIN, T_MAX, CAMPIONI)

# ESERCIZIO 1
# rect
rect = np.where(abs(t) <= 0.5, 1, 0)

plt.subplot(3, 1, 1)
plt.plot(t, rect)
plt.title('rect')
plt.xlabel('tempo')
plt.ylabel('amp')
plt.xlim(T_MIN, T_MAX)

# tri
tri = np.where(abs(t) <= 1, 1-abs(t), 0)

plt.subplot(3, 1, 2)
plt.plot(t, tri)
plt.title('tri')
plt.xlabel('tempo')
plt.ylabel('amp')
plt.xlim(T_MIN, T_MAX)

# convoluzione
conv = np.convolve(rect, tri)
t2 = np.linspace(T_MIN, T_MAX, 2*CAMPIONI-1)

plt.subplot(3, 1, 3)
plt.plot(t2, conv)
plt.title('convoluzione')
plt.xlabel('tempo')
plt.ylabel('amp')
plt.xlim(T_MIN, T_MAX)

plt.show()


# ESERCIZIO 2
