from scipy.io import loadmat
from scipy.fftpack import fft, fftfreq, fftshift, ifft
import numpy as np
import matplotlib.pyplot as plt

# Parametri
PASSO = 0.002
N1 = 8500
N2 = 9800
T_MIN = 0
T_MAX = 2.6


# PUNTO 1

# Caricamento del file .mat
dati_cp4 = loadmat('eeg_CP4_MI_LH_s09.mat')
segnale_cp4 = dati_cp4['eeg_CP4_MI_LH_s09'].flatten()

# Estrazione del segmento di interesse
segnale_xn = segnale_cp4[N1:N2]

# Calcolo del passo temporale
t = np.arange(T_MIN, T_MAX, PASSO)

# Calcolo dell'energia
energia = np.sum(segnale_xn**2)

# Grafico del segnale
plt.figure(figsize=(12, 6))
plt.plot(t, segnale_xn)
plt.title('Segnale x_n')
plt.xlabel('Tempo')
plt.ylabel('Ampiezza')
plt.grid(True)
box = dict(boxstyle='square', ec=(0,0,0), fc=(1,1,1))
plt.text(2.7, -11.5, f'Energia: {energia:.4f}',
         ha='right', va='center', size=15, bbox=box)
plt.legend()
plt.show()


# PUNTO 2

# Caricamento del file .mat per il segnale C4
dati_c4 = loadmat('eeg_C4_MI_LH_s09.mat')
segnale_c4 = dati_c4['eeg_C4_MI_LH_s09'].flatten()

# Estrazione del segmento di interesse
segnale_yn = segnale_c4[N1:N2]

# Calcolo del valore medio e sottrazione
media_yn = np.mean(segnale_yn)
segnale_yn_centrato = segnale_yn - media_yn

# Grafico del segnale con media rimossa
plt.figure(figsize=(12, 6))
plt.plot(t, segnale_yn_centrato)
plt.title('Segnale y_n')
plt.xlabel('Tempo')
plt.ylabel('Ampiezza')
plt.grid(True)
plt.legend()
plt.show()


# Calcolo del coefficiente di correlazione tra i segnali
correlazione = np.corrcoef(segnale_xn, segnale_yn_centrato)[0, 1]
print(f'Coefficiente di correlazione tra x_n e y_n: {correlazione:.4f}')

# plt.figure(figsize=(24, 6))
# plt.subplot(1,2,1)
# plt.plot(t, segnale_xn, label='Segnale x_n')
# plt.xlabel('Tempo')
# plt.ylabel('Ampiezza')
# plt.grid(True)
# plt.legend()

# box = dict(boxstyle='square', ec=(0,0,0), fc=(1,1,1))
# plt.text(3, -10.7, f'Coefficiente di correlazione tra x_n e y_n: {correlazione:.4f}',
#          ha='center', va='center', size=30, bbox=box)

# plt.subplot(1,2,2)
# plt.plot(t, segnale_yn_centrato, label='Segnale y_n')
# plt.xlabel('Tempo')
# plt.ylabel('Ampiezza')
# plt.grid(True)
# plt.legend()
# plt.show()


# PUNTO 3

# Calcolo della FFT del segnale CP4
trasformata_xn = fft(segnale_xn)
frequenze = fftfreq(segnale_xn.size, PASSO)
trasformata_xn_abs = np.abs(fftshift(trasformata_xn))
frequenze_shiftate = fftshift(frequenze)

# Grafico della trasformata di Fourier
plt.figure(figsize=(12, 6))
plt.plot(frequenze_shiftate, trasformata_xn_abs)
plt.title('Trasformata di Fourier del segnale x_n')
plt.xlabel('Frequenza')
plt.ylabel('Ampiezza')
plt.grid(True)
plt.show()

# Filtro passa-banda in frequenza
f1 = (frequenze - 10.5)/5
f2 = (frequenze + 10.5)/5
rect1 = np.where(np.abs(f1) <= 1/2, 1, 0)
rect2 = np.where(np.abs(f2) <= 1/2, 1, 0)
filtro = rect1 + rect2

# Grafico filtro passa-banda
plt.figure(figsize=(12, 6))
plt.plot(frequenze, filtro)
plt.title('Risposta in frequenza')
plt.xlabel('Frequenza')
plt.ylabel('Ampiezza')
plt.xlim(-20, 20)
plt.grid(True)
plt.show()

# Applicazione del filtro
segnale_filtrato = ifft(segnale_xn*filtro)

# Grafico del segnale filtrato (nel tempo)
plt.figure(figsize=(12, 6))
plt.plot(t, segnale_filtrato)
plt.title('Segnale filtrato')
plt.xlabel('Tempo')
plt.ylabel('Ampiezza')
plt.grid(True)
plt.legend()
plt.show()