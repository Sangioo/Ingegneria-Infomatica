from funzioni_esercizi import isIntero, divisoreNonComune
n1 = input('inserire n1: ')
n2 = input('inserire n2: ')
d = input('inserire d: ')

if isIntero(n1) and isIntero(n2) and isIntero(d):
    n1 = int(n1)
    n2 = int(n2)
    d = int(d)
    if n1 > 0 and n2 > 0 and d > 0:
        if divisoreNonComune(n1, n2, d):
            print(d, 'è un divisore di di ' + str(n1) + ', non in comune con', n2)
        else:
            print(d, 'non è un divisore di di ' + str(n1) + ', non in comune con', n2)
    else:
        print('errore: uno dei numeri inseriti non e\' maggiore di 0')
else:
    print('errore: uno dei valori inseriti non e\' un intero')