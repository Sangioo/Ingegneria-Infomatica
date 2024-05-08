def Ex1(l):
    count = 1
    max = 1
    
    if len(l) == 0:
        return 0
    
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

    counter_test_positivi += tester_fun(Ex1, [["da","ab","cc","ce","ea","ad","eb","ba","ag"]],4)
    counter_test_positivi += tester_fun(Ex1, [["da","ab","cc","ce","ea","ae","eb","ba","ag"]],7)
    counter_test_positivi += tester_fun(Ex1, [["da"]],1)
    counter_test_positivi += tester_fun(Ex1, [["da","ab","ad","eb","ba","ag"]],3)
    counter_test_positivi += tester_fun(Ex1, [[]],0)

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
