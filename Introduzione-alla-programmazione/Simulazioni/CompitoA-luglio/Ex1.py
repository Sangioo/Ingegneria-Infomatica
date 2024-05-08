def Ex1(s,c):
    ris = 0
    if s.count(c) == 0: return -1

    for i in range(len(s)-1):
        if s[i] == c and s[i+1]>c:
            ris += 1
    return ris


###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['mattinataturbolenta','t'],1)
    counter_test_positivi += tester_fun(Ex1, ['casa','t'],-1)
    counter_test_positivi += tester_fun(Ex1, ['casta','t'],0)
    counter_test_positivi += tester_fun(Ex1, ['t','t'],0)
    counter_test_positivi += tester_fun(Ex1, ['otto','t'],0)


    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
