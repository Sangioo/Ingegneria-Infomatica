def Ex1(v,i1,i2):
    massimo = 0
    for i in range(len(v)):
        for j in range(len(v), i, -1):
            if v[i:j].count(i1) == v[i:j].count(i2) and v[i:j].count(i1)>0 and v[i:j].count(i2)>0:
                if len(v[i:j]) > massimo:
                    massimo = len(v[i:j])
    
    return massimo

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, [[9,5,7,33,9,5,5,5,8,5,33,33,6,15,8,5,6],33,5],9)
    counter_test_positivi += tester_fun(Ex1, [[9,5],9,5],2)
    counter_test_positivi += tester_fun(Ex1, [[7,4,11,33,9,5,14,2],9,5],8)
    counter_test_positivi += tester_fun(Ex1, [[7,4,11,9,9,5,14,2],9,5],4)
    counter_test_positivi += tester_fun(Ex1, [[],9,5],0)
 
    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
