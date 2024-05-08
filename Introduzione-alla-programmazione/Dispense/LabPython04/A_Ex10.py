def Ex10(s,c1,c2):
    if c1 not in s and c2 not in s:
        return 0

    min = len(s)
    for i in range(len(s)):
        for j in range(i, len(s)):
            if (s[i] in c1 and s[j] in c2) or (s[i] in c2 and s[j] in c1) and len(s[i:j+1]) <= min:
                print(i, j, len(s[i:j+1]))
                min = len(s[i:j+1])
    
    return min





###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 4

    # test distribuzione

    counter_test_positivi += tester_fun(Ex10, ['casale','a','l'],2)
    counter_test_positivi += tester_fun(Ex10, ['casale','c','e'],6)
    counter_test_positivi += tester_fun(Ex10, ['casale','s','s'],1)
    counter_test_positivi += tester_fun(Ex10, ['casale','f','g'],0)
   
    print('La funzione',Ex10.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
