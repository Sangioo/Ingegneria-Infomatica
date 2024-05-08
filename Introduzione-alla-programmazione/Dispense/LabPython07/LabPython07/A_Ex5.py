def A_Ex5(l):
    i = 1
    while i < len(l):
        if l[i] > l[i-1]:
            l.append(l[i] - l[i-1])
        i += 1
    
    return l

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""    
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex5, [[10,1,11,31,251]] , [10,1,11,31,251,10,20,220,10,200,190])
    counter_test_positivi += tester_fun(A_Ex5, [[]] , [])
    counter_test_positivi += tester_fun(A_Ex5, [[2,7,3]] , [2,7,3,5,2])
    counter_test_positivi += tester_fun(A_Ex5, [[200,501,300]] , [200,501,300,301,1])
    counter_test_positivi += tester_fun(A_Ex5, [[3,2,0]] , [3,2,0])


    print('La funzione',A_Ex5.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
