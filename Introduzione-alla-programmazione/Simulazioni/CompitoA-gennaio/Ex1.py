def Ex1(l):
    count = 1
    max = 0
    for i in range(1,len(l)):
        if l[i-1][1] == l[i][0]:
            count += 1
        else:
            count = 1
        if count > max:
            max = count
    return max

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, [[(4,1),(1,2),(3,3),(3,5),(5,1),(1,4),(5,2),(2,1),(1,7)]],4)
    counter_test_positivi += tester_fun(Ex1, [[(4,1),(1,2),(3,3),(3,5),(5,1),(1,5),(5,2),(2,1),(1,7)]],7)
    counter_test_positivi += tester_fun(Ex1, [[(4,1),(1,5)]],2)
    counter_test_positivi += tester_fun(Ex1, [[(4,1),(1,2),(1,4),(5,2),(2,1),(1,7)]],3)
    counter_test_positivi += tester_fun(Ex1, [[]],0)

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
