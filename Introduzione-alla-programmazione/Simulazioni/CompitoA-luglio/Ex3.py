def Ex3(file,nome):
    f = open(file, encoding='UTF-8')
	
    ris = set()
    vittorie = {}
    for riga in f:
        riga = riga.strip().split(',')
		
        if riga[0] == nome and riga[2] == '2':
            vittorie[riga[1]] = vittorie.get(riga[1], 0) + 1
        elif riga[1] == nome and riga[2] == '1':
            vittorie[riga[0]] = vittorie.get(riga[0], 0) + 1
        else:
            vittorie[riga[0]] = vittorie.get(riga[0], 0)
            vittorie[riga[1]] = vittorie.get(riga[1], 0)
	
    massimo = max(list(vittorie.values()), default=0)
	
    for k in vittorie:
        if vittorie[k] == massimo and k != nome:
            ris.add(k)
	
    return ris

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['partite1.csv','Gianni'],{'Piero'})
    counter_test_positivi += tester_fun(Ex3, ['partite1.csv','Piero'],{'Paolo', 'Gianni'})
    counter_test_positivi += tester_fun(Ex3, ['partite2.csv','Paolo'],{'Piero', 'Gianni'})
    counter_test_positivi += tester_fun(Ex3, ['partite2.csv','Gianni'],{'Paolo', 'Piero'})
    counter_test_positivi += tester_fun(Ex3, ['partite2.csv','Piero'],{'Paolo', 'Gianni'})
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
