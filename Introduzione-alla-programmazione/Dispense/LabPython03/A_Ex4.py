def A_Ex4(s,n):
    ris = ''
    for c in s:
        if ord(c)%n == 0 and c not in ris:
            ris += c
    return ris


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex4, ['stringa di prova',3],'rio')
    counter_test_positivi += tester_fun(A_Ex4, ['stringa di prova',2],'trn dpv')
    counter_test_positivi += tester_fun(A_Ex4, ['stringa di prova',5],'sind')
    counter_test_positivi += tester_fun(A_Ex4, ['',1],'')
    counter_test_positivi += tester_fun(A_Ex4, ['stringa di prova stringa di prova',4],'t dp')

    print('La funzione',A_Ex4.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

