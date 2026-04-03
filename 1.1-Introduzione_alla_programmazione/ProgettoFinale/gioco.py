

import pandas as pd
import numpy as np
from IPython.display import display, Image, clear_output



url1 = "https://upload.wikimedia.org/wikipedia/commons/thumb/c/c9/Interno_del_Colosseo.jpg/281px-Interno_del_Colosseo.jpg"

image1 = Image(url1) # carica l'immagine alla url1 nell'oggetto image1
image2=Image(open('Eiffel.png',"rb").read())
display(image1) # visualizza image1
input() # il programma aspetta un invio ('enter') prima di andare avanti
clear_output() # cancella output
display(image2) # visualizza image1
input() # il programma aspetta un invio ('enter') prima di andare avanti



#importiamo le librerie necessarie per il gioco