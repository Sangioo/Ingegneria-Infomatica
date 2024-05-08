def A_Ex8(l):
    insieme = set()
    for s in l:
        insieme = insieme.union(set(s))
    

    max = 0
    maxC = ''
    for c in insieme:
        count = 0
        if not (96 < ord(c) < 123):
            continue
        
        for s in l:
            if c in s:
                count += 1
        if count > max or (count == max and c > maxC):
            max = count
            maxC = c
        
    return maxC

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, [["casa", "senape", "ketchup", "pasta"]] , "s")
    counter_test_positivi += tester_fun(A_Ex8, [["a", "b", "b", "a", "a", "a", "a"]] , "a")
    counter_test_positivi += tester_fun(A_Ex8, [["1fI", "1FI", "1FI", "1FI","1FI" ]] , "f")
    counter_test_positivi += tester_fun(A_Ex8, [["conte", "dpcm"]] , "c")
    counter_test_positivi += tester_fun(A_Ex8, [["Zlatan", "Ibraimovich", "Cristiano", "Ronaldo", "Francesco", "Totti"]] , "o")


    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
