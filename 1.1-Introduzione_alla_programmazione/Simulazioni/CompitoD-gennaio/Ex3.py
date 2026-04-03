def Ex3(file):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['giochi1.csv'],{'G1', 'G4', 'G3'})   
    counter_test_positivi += tester_fun(Ex3, ['giochi2.csv'],{'G1', 'G4', 'G3'})
    counter_test_positivi += tester_fun(Ex3, ['giochi3.csv'],{'G1', 'G4', 'G3'})
    counter_test_positivi += tester_fun(Ex3, ['giochi4.csv'],{'G1', 'G3', 'G5'})
    counter_test_positivi += tester_fun(Ex3, ['giochi5.csv'],{'G1', 'G3', 'G7'})
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

