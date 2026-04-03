def A_Ex3(fileName):
    fin = open(fileName, encoding='UTF-8')
    s = fin.read().strip().split('\n')
    fin.close()
    
    ris = set()
    for riga in s[1:]:
        riga = riga.strip().split(',')
        if riga[2] in ris:
            continue

        count = 0
        for i in s[1:]:
            i = i.strip().split(',')
            if int(i[1]) >= 18 and i[2] == riga[2]:
                count += 1
        
        if count >= 2:
            ris.add(riga[2])
    
    return ris



###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun
    
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex3, ["esami1.csv"], {'Fisica'})
    counter_test_positivi += tester_fun(A_Ex3, ["esami2.csv"], set())
    counter_test_positivi += tester_fun(A_Ex3, ["esami3.csv"], {'Ricerca Operativa','Analisi'})
    counter_test_positivi += tester_fun(A_Ex3, ["esami4.csv"], {'Basi di Dati'})
    counter_test_positivi += tester_fun(A_Ex3, ["esami5.csv"], set())

    print('La funzione',A_Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)