def A_Ex9(s1,s2):
    if len(s1) > len(s2):
        s = s2
    else:
        s = s1
    
    max = 0
    for i in range(len(s)):
        for j in range(len(s), i, -1):
            if s[i:j] in s1 and s[i:j] in s2:
                if len(s[i:j]) > max:
                    max = len(s[i:j])
    
    return max

    
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""
if __name__ == '__main__':
    from tester import tester_fun
    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione
  
    counter_test_positivi += tester_fun(A_Ex9, ['casa','cappello'], 2)
    counter_test_positivi += tester_fun(A_Ex9, ['carcassa','cassapanca'], 5)
    counter_test_positivi += tester_fun(A_Ex9, ['sorpasso','passo e sorpasso'], 8)
    counter_test_positivi += tester_fun(A_Ex9, ['casa',''], 0)
    counter_test_positivi += tester_fun(A_Ex9, ['a','a'], 1)

    print('La funzione',A_Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
    
