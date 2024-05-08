def Ex1(l):
    massimo = 0
    for i in range(len(l)):
        for j in range(len(l), i, -1):
            print(l[i:j])
            somma = sum(l[i:j])
            if somma < 100 and len(l[i:j]) > massimo:
                massimo = len(l[i:j])
    
    return massimo
    
    
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, [[335,88,21,2,3,9,150]],4)
    counter_test_positivi += tester_fun(Ex1, [[335]],0)
    counter_test_positivi += tester_fun(Ex1, [[1,2,3,4,5,6,7]],7)
    counter_test_positivi += tester_fun(Ex1, [[]],0)
    counter_test_positivi += tester_fun(Ex1, [[335,188,221]],0)

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
