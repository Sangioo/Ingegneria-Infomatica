def Ex1(l):
    if len(l) == 0:
        return 0
    massimo = 1
    conta = 1
    for i in range(len(l)-1):
        if l[i][1] == l[i+1][0]:
            conta += 1
        else:
            conta = 1
        if conta > massimo:
            massimo = conta
    return massimo
    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, [["da","ab","cc","ce","ea","ad","eb","ba","ag"]],4)
    counter_test_positivi += tester_fun(Ex1, [["da","ab","cc","ce","ea","ae","eb","ba","ag"]],7)
    counter_test_positivi += tester_fun(Ex1, [["da","aa"]],2)
    counter_test_positivi += tester_fun(Ex1, [["da","ab","ad","eb","ba","ag"]],3)
    counter_test_positivi += tester_fun(Ex1, [[]],0)

    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex1, [["ma","ab","cc","ce","ea","am","eb","b1","ag"]],4)
    counter_test_positivi += tester_fun(Ex1, [["ma","ab","nn","ne","ea","ae","eb","ba","ag"]],7)
    counter_test_positivi += tester_fun(Ex1, [["ma","ab","nn","ne"]],2)
    counter_test_positivi += tester_fun(Ex1, [["ma","ab","am","eb","ba","ag"]],3)
    counter_test_positivi += tester_fun(Ex1, [["ma","ab","eb","ag"]],2)

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

