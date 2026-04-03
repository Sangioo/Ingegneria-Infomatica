def A_Ex7(l):
    strMax = ''
    numMax = 0
    occMax = 0
    for elem in l:
        count = 0
        maxVal = elem[1]
        for i in l:
            if i[0] == elem[0]:
                count += 1
                if i[1] > maxVal:
                    maxVal = i[1]

        if count > occMax:
            occMax = count
            strMax = elem[0]
            numMax = elem[1]
        
        elif count == occMax:
            if maxVal > numMax:
                occMax = count
                strMax = elem[0]
                numMax = elem[1]
            
            elif maxVal == numMax:
                if elem[0] < strMax:
                    occMax = count
                    strMax = elem[0]
                    numMax = elem[1]
    
    return (strMax, numMax)


###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 3

    counter_test_positivi += tester_fun(A_Ex7, [[['italiano',6], ['geografia',10], ['matematica',6],['storia',8], ['matematica', 10], ['storia', 8], ['geografia', 7]]] , ('geografia',10))
    counter_test_positivi += tester_fun(A_Ex7, [[['italiano',7], ['storia',6]]], ('italiano',7))
    counter_test_positivi += tester_fun(A_Ex7, [[['storia',4],['storia',6],['matematica',7]]], ('storia',6))



    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
