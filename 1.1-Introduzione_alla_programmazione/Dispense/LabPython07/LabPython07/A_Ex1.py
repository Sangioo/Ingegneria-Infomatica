def A_Ex1(l):
    ris = set()
    for i in l:
        ris = ris.union(i)
    tmp = ris.copy()
    for elem in tmp:
        count = 0
        for i in l:
            if elem in i:
                count += 1
        if count > 1:
            ris.discard(elem)

    return ris

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex1, [[{3,2,90},{2,87,23},{2,23,3}]] , {90,87})
    counter_test_positivi += tester_fun(A_Ex1, [[set(),{-10},{2}]] , {-10,2})
    counter_test_positivi += tester_fun(A_Ex1, [[set()]] , set())
    counter_test_positivi += tester_fun(A_Ex1, [[set(),{10,-2},{10},{-2}]] , set())
    counter_test_positivi += tester_fun(A_Ex1, [[set(),{10,-9,4},{4,-5,2},{3,7,4}]] , {10,-9,-5,2,3,7})


    print('La funzione',A_Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
