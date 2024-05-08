def veroFalso():
    ##############################################################################################
    # Modificare il valore del return elencando le lettere delle domande che valutate essere vere
    # Ad esempio, se pensate che B, C, e D siano vere la funzione deve restituire 'BCD'
    ##############################################################################################

    d=eval(open('VeroFalsoD.txt',encoding="UTF-8").read())
    for dom in 'ABCDEFGH':
        print(dom+')', end='')
        print(d[dom]['premessa'])
        print(d[dom]['domanda'])
        print()
    return 'ABCDEFGH'

veroFalso()
print('**** Modificare il valore restituito dalla funzione ****')
