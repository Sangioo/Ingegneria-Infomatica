def Ex1(s):
    s=s.lower()
    massimo = 0
    for i in range(len(s)):
        if s[i] in 'aeiou':
            conta = 1
            for j in range(i+1,len(s)):
                conta+=1
                if s[j] in 'aeiou':
                    if conta > massimo:
                        massimo = conta
                    break
    return massimo
    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, ['cavalloaltrimenti'],5)
    counter_test_positivi += tester_fun(Ex1, ['cav_llo potente'],6)
    counter_test_positivi += tester_fun(Ex1, ['al123llllu'],10)
    counter_test_positivi += tester_fun(Ex1, ['ao'],2)
    counter_test_positivi += tester_fun(Ex1, ['u..a comune'],4)
    

    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex1, [''],0)
    counter_test_positivi += tester_fun(Ex1, ['trl'],0)
    counter_test_positivi += tester_fun(Ex1, ['a'],0)
    counter_test_positivi += tester_fun(Ex1, ['alla'],4)
    counter_test_positivi += tester_fun(Ex1, ['unora'],3)


    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
