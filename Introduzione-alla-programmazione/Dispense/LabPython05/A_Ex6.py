def A_Ex6(v1,v2):
    p1 = 0
    p2 = 0
    i = 1
    while p1 != p2 or p2==0==p1:
        p1 += v1
        p2 += v2*i
        i += 1
    
    return i-1


##############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 4

    counter_test_positivi += tester_fun(A_Ex6, [20,1],39)
    counter_test_positivi += tester_fun(A_Ex6, [10,5],3) 
    counter_test_positivi += tester_fun(A_Ex6, [1,1],1)
    counter_test_positivi += tester_fun(A_Ex6, [100,10],19)


    print('La funzione',A_Ex6.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

    