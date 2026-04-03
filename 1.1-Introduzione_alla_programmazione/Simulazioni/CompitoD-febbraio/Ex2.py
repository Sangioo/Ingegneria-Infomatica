def Ex2(file):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testo1d.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo2d.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo3d.txt'], 1)
    counter_test_positivi += tester_fun(Ex2, ['testo4d.txt'], 1)
    counter_test_positivi += tester_fun(Ex2, ['testo5d.txt'], 3)
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
