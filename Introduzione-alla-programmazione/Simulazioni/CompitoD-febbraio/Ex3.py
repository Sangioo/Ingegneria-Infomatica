def Ex3(file1,n):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################
"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['esempio1d.txt',3],2)
    counter_test_positivi += tester_fun(Ex3, ['esempio1d.txt',4],2) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1d.txt',2],3) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1d.txt',1],5) 
    counter_test_positivi += tester_fun(Ex3, ['esempio2d.txt',5],2) 
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
