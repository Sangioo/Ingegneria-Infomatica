def A_Ex1(s,n):
    if len(s)<n: return ''
    
    maxS = ''
    max = 0
    for i in range(len(s)-n+1):
        tmpS = ''
        tmpM = 0
        for j in range(n):
            tmpS += s[i+j]
            tmpM += ord(s[i+j])
        
        if tmpM>max:
            maxS = tmpS
            max = tmpM
        
    return maxS


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 4

    counter_test_positivi += tester_fun(A_Ex1, ['scacco matto',3], 'tto')
    counter_test_positivi += tester_fun(A_Ex1, ['scacco',3], 'sca')
    counter_test_positivi += tester_fun(A_Ex1, ['scacco',7], '')
    counter_test_positivi += tester_fun(A_Ex1, ['prova',5], 'prova')

    print('La funzione',A_Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
