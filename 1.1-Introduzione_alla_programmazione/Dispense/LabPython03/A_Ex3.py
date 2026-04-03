def A_Ex3(s):
    for i in range(len(s)):
        if str(i) == s[i]:
            return True
    return False


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex3, ['223367'],True)
    counter_test_positivi += tester_fun(A_Ex3, ['1234567890'],False)
    counter_test_positivi += tester_fun(A_Ex3, ['2211003367'],False)
    counter_test_positivi += tester_fun(A_Ex3, ['1234567899'],True)
    counter_test_positivi += tester_fun(A_Ex3, ['2234567'],False)

    print('La funzione',A_Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
