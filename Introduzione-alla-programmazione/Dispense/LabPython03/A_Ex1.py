def A_Ex1(s):
    max = 0
    for c in s:
        if s.count(c) > max:
            max = s.count(c)
    
    ris = ''
    for c in s:
        if s.count(c) == max and c not in ris:
            ris += c
    
    return ris


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex1, ['caso palese'] ,'ase')
    counter_test_positivi += tester_fun(A_Ex1, ['caso palesemente'] ,'e')
    counter_test_positivi += tester_fun(A_Ex1, ['caso palese zitto'] ,'aso et')
    counter_test_positivi += tester_fun(A_Ex1, ['aca'] ,'a')
    counter_test_positivi += tester_fun(A_Ex1, [''] ,'')

    print('La funzione',A_Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
