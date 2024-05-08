def A_Ex8(fileName):
    fin = open(fileName, encoding='UTF-8')

    max = 0
    maxI = 1
    i = 1
    for s in fin:
        s = s.strip()

        conta = 0
        for c in 'abcdefghijklmnopqrstuvwxyzàáèéìíóòùúîô'.upper():
            conta += s.count(c)
        
        if conta >= max:
            max = conta
            maxI = i
        i += 1
    
    fin.close()
    return maxI
        

 
###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, ["file1.txt"] , 2)
    counter_test_positivi += tester_fun(A_Ex8, ["file2.txt"] , 2)
    counter_test_positivi += tester_fun(A_Ex8, ["file3.txt"] , 2)
    counter_test_positivi += tester_fun(A_Ex8, ["file4.txt"] , 3)
    counter_test_positivi += tester_fun(A_Ex8, ["file5.txt"] , 3)

    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
