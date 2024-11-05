import numpy as np
import matplotlib.pyplot as plt
from scipy import fft

ampiezza = 2
frequenza = 20
campioni = 5000
t_min = 0
t_max = 2
t_int = (t_max - t_min)/campioni

t = np.linspace(t_min, t_max, campioni)

# segnale coseno
coseno = ampiezza * np.cos(2 * np.pi * frequenza * t)

plt.subplot(3, 1, 1)
plt.grid(True)
plt.plot(t, coseno)
plt.title("PARTE REALE")
plt.ylabel("ampiezza")
plt.xlabel("tempo")

# segnale seno
seno = ampiezza * np.sin(2 * np.pi * frequenza * t)

plt.subplot(3, 1, 2)
plt.grid(True)
plt.plot(t, seno)
plt.title("PARTE IMMAGINARIA")
plt.ylabel("ampiezza")
plt.xlabel("tempo")

# segnale somma
somma = coseno + 1j*seno

# trasformata di Fourier
trasformata = fft.fftshift(fft.fft(somma))
arrayFrequenze = fft.fftfreq(t.size, d=t_int)

plt.subplot(3, 1, 3)
plt.grid(True)
plt.plot(fft.fftshift(arrayFrequenze), np.abs(trasformata))
plt.title("TRASFORMATA")
plt.ylabel("ampiezza")
plt.xlabel("frequenza")

plt.show()