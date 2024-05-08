def Ex2(file,s):
    """MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"""
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['file1.txt','LarDo'], {1: ['Tanto'], 2: ['Al'], 3: ['raSe']})
    counter_test_positivi += tester_fun(Ex2, ['file1.txt','diFfIciLe'],{1: ['Tanto'], 2: ['Al'], 3: ['Datato', 'raSe']})
    counter_test_positivi += tester_fun(Ex2, ['file1.txt','cASa'],{1: ['Tanto'], 2: [], 3: ['Datato']})
    counter_test_positivi += tester_fun(Ex2, ['file2.txt','TantO'],{1: [], 2: ['Al', 'LA'], 3: ['Darlo'], 4: []})
    counter_test_positivi += tester_fun(Ex2, ['file3.txt','oRE'],{1: ['Tanto'], 2: ['Al', 'LA'], 3: ['Al', 'CAAs'], 4: ['Darlo', 'asAc']})
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
