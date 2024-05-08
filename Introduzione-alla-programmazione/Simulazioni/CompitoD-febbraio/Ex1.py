def Ex1(l):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, [[3,2,-8,1,2,3,9,0]],4)
    counter_test_positivi += tester_fun(Ex1, [[335]],1)
    counter_test_positivi += tester_fun(Ex1, [[1,-2,3,4,5,-6,7]],3)
    counter_test_positivi += tester_fun(Ex1, [[0]],0)
    counter_test_positivi += tester_fun(Ex1, [[35,-1,2]],1)
    
    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
