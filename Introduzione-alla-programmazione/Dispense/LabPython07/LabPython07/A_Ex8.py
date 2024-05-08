def A_Ex8(l):
    ris = []
    stringhe = []
    for elem in l:
        if elem[0] in stringhe:
            i = stringhe.index(elem[0])
            ris[i] = (ris[i][0], ris[i][1].union(set(elem[1])))
        else:
            stringhe.append(elem[0])
            ris.append((elem[0], set(elem[1])))
    ris.sort()
    return ris


###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 4

    counter_test_positivi += tester_fun(A_Ex8, [[('pippo',['blu','giallo']),('minnie', ['rosa']),('pippo', ['rosso', 'blu'])]] , [('minnie',{'rosa'}), ('pippo', {'blu', 'rosso', 'giallo'})])
    counter_test_positivi += tester_fun(A_Ex8, [[('roma',['colosseo']),('parigi',['tour eiffel'])]],  [('parigi',{'tour eiffel'}),('roma',{'colosseo'})])
    counter_test_positivi += tester_fun(A_Ex8,[[('roma',['colosseo']),('parigi',['tour eiffel']),('roma',['fontana di trevi','colonna di traiano','colosseo'])]],  [('parigi',{'tour eiffel'}),('roma',{'colosseo','fontana di trevi','colonna di traiano'})])
    counter_test_positivi += tester_fun(A_Ex8, [[]] , [])


    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
