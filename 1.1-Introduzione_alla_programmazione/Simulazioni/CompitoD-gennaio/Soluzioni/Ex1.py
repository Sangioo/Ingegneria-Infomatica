def Ex1(s):
    massimo = 0
    for i in range(len(s)):
        if s[i].isupper():
            conta = 1
            for j in range(i+1,len(s)):
                conta += 1
                if s[j].isupper():
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

    counter_test_positivi += tester_fun(Ex1, ['caValloImbIzZarRito'],6)
    counter_test_positivi += tester_fun(Ex1, ['CasalegrandE'],12)
    counter_test_positivi += tester_fun(Ex1, ['SA'],2)
    counter_test_positivi += tester_fun(Ex1, ['ABCDEFGhhhhhgggRe'],10)
    counter_test_positivi += tester_fun(Ex1, [''],0)

    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex1, ['CVpazzo'],2)
    counter_test_positivi += tester_fun(Ex1, ['S....A'],6)
    counter_test_positivi += tester_fun(Ex1, ['PRaaa'],2)
    counter_test_positivi += tester_fun(Ex1, ['allLE'],2)
    counter_test_positivi += tester_fun(Ex1, ['PP'],2)
 
    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
