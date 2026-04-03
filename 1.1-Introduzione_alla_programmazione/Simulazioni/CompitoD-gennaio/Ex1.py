def Ex1(s):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['caValloImbIzZarRito'],6)
    counter_test_positivi += tester_fun(Ex1, ['CasalegrandE'],12)
    counter_test_positivi += tester_fun(Ex1, ['SA'],2)
    counter_test_positivi += tester_fun(Ex1, ['ABCDEFGhhhhhgggRe'],10)
    counter_test_positivi += tester_fun(Ex1, [''],0)
    
    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
