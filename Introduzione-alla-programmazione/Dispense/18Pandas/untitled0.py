#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Dec  9 15:10:53 2022

@author: beppes
"""
import pandas



f=[]
for i in range(1000):
    x=i/10
    y=x**2
    f.append([x,y])
    
    
df = pandas.DataFrame(f,
                   columns=['x', 'y'])

df.to_excel('funzione.xlsx','T1',index=False)
   







#         a   b   c
# one    11  21  31
# two    12  22  32
# three  31  32  33