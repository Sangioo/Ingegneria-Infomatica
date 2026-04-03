def A_Ex2(s):
    ris = ''
    for c in s:
        if c in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ' and c not in ris:
            ris += c
    
    ris = list(ris)
    for i in range(len(ris)):
        for j in range(i+1, len(ris)):
            if ris[j]<ris[i]:
                ris[i],ris[j] = ris[j],ris[i]
    ris = ''.join(ris)
    return ris


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex2, ['cIAo MAmMa'],'AIM')
    counter_test_positivi += tester_fun(A_Ex2, ['3219'], '')
    counter_test_positivi += tester_fun(A_Ex2, ['aG2Hl'], 'GH')
    counter_test_positivi += tester_fun(A_Ex2, ['PPq&/&90PQ'], 'PQ')
    counter_test_positivi += tester_fun(A_Ex2, [''], '')

    print('La funzione',A_Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
