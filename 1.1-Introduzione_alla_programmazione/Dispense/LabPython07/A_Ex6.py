def A_Ex6(v1,v2):
    ris = set()
    for i in v1:
        for j in v2:
            if i%j == 0 or j%i == 0:
                ris.add((i,j))
    
    return ris

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex6, [{3,10,28},{2,20}], {(10,2),(28,2),(10,20)})
    counter_test_positivi += tester_fun(A_Ex6, [set(), {2}], set())
    counter_test_positivi += tester_fun(A_Ex6, [{3},set()], set())
    counter_test_positivi += tester_fun(A_Ex6, [{2,4},{8,2}], {(2,8),(4,8),(2,2),(4,2)})
    counter_test_positivi += tester_fun(A_Ex6, [{17,3},{22,5}], set())


    print('La funzione',A_Ex6.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
