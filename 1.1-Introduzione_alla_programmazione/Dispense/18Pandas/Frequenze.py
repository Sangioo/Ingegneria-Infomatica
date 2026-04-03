#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Dec 10 18:47:00 2022

@author: beppes
"""


from matplotlib import pyplot as plt  #usiamo  la stringa plt invece di matplotlib.pyplot

s=open('I_Malavoglia.txt').read()

x=[]

for c in s:
    if c.lower() in 'aeiou':
        x.append(c.lower())


x.sort()
plt.hist(x)

plt.xlabel('valori della x')
plt.ylabel('Numero di occorrenze')
plt.grid(True) # disegna la griglia per render più leggibile l'istogramma
plt.show()
