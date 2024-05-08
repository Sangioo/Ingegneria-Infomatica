def Ex10(s,c1,c2):
    "MODIFICARE IL CONTENUTO DI QUESTA FUNZIONE PER SVOLGERE L'ESERCIZIO"

    ans = len(s)

    if c1 not in s and c2 not in s:
        return 0
    
    if s.count(c1) > s.count (c2):
        reps = s.count(c1)
    else:
        reps = s.count(c2)

    for i in range (reps):

        lenghtSubString = abs(s.find(c1) - s.find (c2)) + 1

        if lenghtSubString < ans:
            ans = lenghtSubString
        
        s = s[s.find(c1) + 1:]


    return (ans)





###############################################################################    

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 6

    # test distribuzione
  
    counter_test_positivi += tester_fun(Ex10, ['casale','a','l'],2)
    counter_test_positivi += tester_fun(Ex10, ['casale','c','e'],6)
    counter_test_positivi += tester_fun(Ex10, ['casale','s','s'],1)
    counter_test_positivi += tester_fun(Ex10, ['casale','f','g'],0)
    counter_test_positivi += tester_fun(Ex10, ['piacevolissimamente','o','e'],3)
    counter_test_positivi += tester_fun(Ex10, ['piacevolissimamente','i','m'],2)

   
    print('La funzione',Ex10.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
