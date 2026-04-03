def A_Ex7(fileName):
    fin = open(fileName, encoding='UTF-8')
    s = fin.read().strip().split()
    fin.close()

    somma = 0
    for p in s:
        if '0' in p or '1' in p or '2' in p or '3' in p or '4' in p or '5' in p or '6' in p or '7' in p or '8' in p or '9' in p:
            somma += int(p)
    
    return somma

 
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex7, ["file1.txt"] , 14)
    counter_test_positivi += tester_fun(A_Ex7, ["file2.txt"] , 17)
    counter_test_positivi += tester_fun(A_Ex7, ["file3.txt"] , 18)
    counter_test_positivi += tester_fun(A_Ex7, ["file4.txt"] , 20)
    counter_test_positivi += tester_fun(A_Ex7, ["file5.txt"] , 0)

    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
