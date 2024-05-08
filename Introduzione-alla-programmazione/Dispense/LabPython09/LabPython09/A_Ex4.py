def A_Ex4(fileName):
    fin = open(fileName, encoding='UTF-8')
    ris = {}
    
    pRiga = fin.readline().strip().split(',')
    for riga in fin:
        riga = riga.strip().split(',')
        
        if len(riga) != len(pRiga):
            continue
        if int(riga[1]) >= 18:
            ris[int(riga[0])] = ris.get(int(riga[0]), 0) + 1
    
    fin.close()
    return ris

###############################################################################


"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex4, ["esami1.csv"] , {1345: 1, 1346: 1, 1896: 1, 1753: 1})
    counter_test_positivi += tester_fun(A_Ex4, ["esami2.csv"] , {1346: 1})
    counter_test_positivi += tester_fun(A_Ex4, ["esami3.csv"] , {1347: 2, 1348: 1, 1349: 1})
    counter_test_positivi += tester_fun(A_Ex4, ["esami4.csv"] , {1100: 1, 1012: 1, 1021: 1})
    counter_test_positivi += tester_fun(A_Ex4, ["esami5.csv"] , {1345: 1, 1987: 1, 1346: 1, 1896: 1})

    print('La funzione',A_Ex4.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
