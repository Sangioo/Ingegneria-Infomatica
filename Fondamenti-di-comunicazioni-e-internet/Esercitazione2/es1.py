import numpy as np
import matplotlib.pyplot as plt

t1 = np.linspace(-0.5, 0.5, 1000)

rect = np.where(t1, 1, 0)

plt.subplot(2, 1, 1)
plt.stem(t1, rect)
plt.title('rect')
plt.xlabel('amp')
plt.ylabel('tempo')
plt.xlim(-5, 5)
