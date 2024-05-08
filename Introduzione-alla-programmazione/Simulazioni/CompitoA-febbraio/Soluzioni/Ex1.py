def Ex1(s,c1,c2):
    # SOLUZIONE DEL PROF
    maxlen = 0
    for i in range(len(s)):
        for j in range(i+1,len(s)):
            parte = s[i:j+1]
            if j+1-i > maxlen and parte.count(c1) == parte.count(c2) and parte.count(c1)>0:
                maxlen = j+1-i
                #print(parte)
    return maxlen

    # MIA SOLUZIONE
    # massimo = 0
    # for i in range(len(s)-1):
    #     for j in range(i+1, len(s)+1):
    #         stringa = s[i:j]
    #         if stringa.count(c1) != stringa.count(c2):
    #             continue
    #         elif len(stringa) > massimo:
    #             massimo = len(stringa)
    
    # return massimo

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['matanto va la gatta al lardo','t','a'],16)
    counter_test_positivi += tester_fun(Ex1, ['tanto va la gatta al lardo che ci lascia','a','o'],16)
    counter_test_positivi += tester_fun(Ex1, ['tanto va la gatta al lardo',' ','a'],20)
    counter_test_positivi += tester_fun(Ex1, ['tanto va la gatta al lardo che ci lascia lo zampino','a',' '],51)
    counter_test_positivi += tester_fun(Ex1, ['tanto va la gatta al lardo','n','o'],25)

    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex1, ['e quindi uscimmo a riveder le stelle','r','a'],25)
    counter_test_positivi += tester_fun(Ex1, ['e quindi uscimmo a riveder le stelle, scrisse Dante','r','s'],42)
    counter_test_positivi += tester_fun(Ex1, ['e quindi uscimmo a riveder le stelle, scrisse Dante',' ','e'],51)
    counter_test_positivi += tester_fun(Ex1, ['e quindi uscimmo a riveder le stelle','a',' '],9)
    counter_test_positivi += tester_fun(Ex1, ['e quindi uscimmo a riveder le stelle','n','o'],36)

    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
