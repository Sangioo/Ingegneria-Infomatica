def Ex3(file,nome):
    f = open(file, "r")
    dati = []
    for riga in f:
        dati.append(riga.strip().split(","))
    f.close()
    giocatori = []
    for riga in dati:
        for giocatore in riga[:2]:
            if giocatore not in giocatori:
                giocatori.append(giocatore)
    massimo = 0
    insieme = set()
    for g in giocatori:
        if g != nome:
            conta = 0
            for riga in dati:
                if (nome in riga and g in riga[0] and riga[2] == '1')  or (nome in riga and g in riga[1] and riga[2] == '2'):
                    conta += 1
            if conta == massimo:
                insieme.add(g)
            elif conta > massimo:
                massimo = conta
                insieme = {g}

    return insieme

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['partite1.csv','Gianni'],{'Piero'})
    counter_test_positivi += tester_fun(Ex3, ['partite1.csv','Piero'],{'Paolo', 'Gianni'})
    counter_test_positivi += tester_fun(Ex3, ['partite2.csv','Paolo'],{'Piero', 'Gianni'})
    counter_test_positivi += tester_fun(Ex3, ['partite2.csv','Gianni'],{'Paolo', 'Piero'})
    counter_test_positivi += tester_fun(Ex3, ['partite2.csv','Piero'],{'Paolo', 'Gianni'})
  
    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex3, ['partite3.csv','Gianni'],{'Paolo', 'Piero'})
    counter_test_positivi += tester_fun(Ex3, ['partite3.csv','Piero'],{'Paolo'})
    counter_test_positivi += tester_fun(Ex3, ['partite4.csv','Paolo'],{'Anna', 'Gianni'})
    counter_test_positivi += tester_fun(Ex3, ['partite4.csv','Gianni'],{'Paolo', 'Piero'})
    counter_test_positivi += tester_fun(Ex3, ['partite4.csv','Piero'],{'Paolo'})
  
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
