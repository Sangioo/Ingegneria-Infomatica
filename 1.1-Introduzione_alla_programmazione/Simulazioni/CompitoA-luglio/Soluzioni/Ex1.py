def Ex1(s,c):
    if s.find(c)==-1:
        return -1
    count=0
    for i in range(len(s)-1):
        if s[i]==c and s[i+1]>c:
            count+=1
    return count

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['mattinataturbolenta','t'],1)
    counter_test_positivi += tester_fun(Ex1, ['casa','t'],-1)
    counter_test_positivi += tester_fun(Ex1, ['casta','t'],0)
    counter_test_positivi += tester_fun(Ex1, ['t','t'],0)
    counter_test_positivi += tester_fun(Ex1, ['otto','t'],0)

    
    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex1, ['mattinataturbolenta','a'],3)
    counter_test_positivi += tester_fun(Ex1, ['casa','t'],-1)
    counter_test_positivi += tester_fun(Ex1, ['tucasa','t'],1)
    counter_test_positivi += tester_fun(Ex1, ['casatu','t'],1)
    counter_test_positivi += tester_fun(Ex1, ['t','a'],-1)


    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
