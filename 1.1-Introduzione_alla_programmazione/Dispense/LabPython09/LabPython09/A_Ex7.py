def A_Ex7(file):
    fin = open(file, encoding='UTF-8')
    ris = {}
    
    pRiga = fin.readline().strip().split(',')
    for riga in fin:
        riga = riga.strip().split(',')
        
        if len(riga) != len(pRiga):
            continue
        
        s1 = riga[0]
        s2 = riga[1]
        gol1 = int(riga[2])
        gol2 = int(riga[3])
        if gol1 > gol2:
            ris[s1] = ris.get(s1, 0) + 3
            ris[s2] = ris.get(s2, 0)
        elif gol2 > gol1:
            ris[s1] = ris.get(s1, 0)
            ris[s2] = ris.get(s2, 0) + 3
        else:
            ris[s1] = ris.get(s1, 0) + 1
            ris[s2] = ris.get(s2, 0) + 1
    
    fin.close()
    return ris

 
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex7, ["partite1.csv"] , {'Chelsea': 3, 'Everton': 3, 'Arsenal': 4, 'Tottenham': 1})
    counter_test_positivi += tester_fun(A_Ex7, ["partite2.csv"] , {'Chelsea': 4, 'Everton': 6, 'Arsenal': 4, 'Tottenham': 2})
    counter_test_positivi += tester_fun(A_Ex7, ["partite3.csv"] , {'Bayern': 4, 'Schalke': 3, 'Amburgo': 4, 'Werder': 1, 'Colonia': 4, 'Stoccarda': 0})
    counter_test_positivi += tester_fun(A_Ex7, ["partite4.csv"] , {'Bayern': 8, 'Schalke': 6, 'Amburgo': 8, 'Werder': 2, 'Colonia': 8, 'Stoccarda': 0})
    counter_test_positivi += tester_fun(A_Ex7, ["partite5.csv"] , {'Bayern': 5, 'Schalke': 6, 'Amburgo': 5, 'Werder': 5, 'Colonia': 5, 'Stoccarda': 6})

    print('La funzione',A_Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
