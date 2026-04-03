def Ex3(file):
    # SOLUZIONE DEL PROF
    diz = {}
    prezzo = {}
    maxrincaro = {} 
    f = open(file,'r',encoding='UTF-8')
    for riga in f:
        dati = riga.strip().split(',')
        mese = dati[0]
        oggetti = dati[1::2]
        prezzi = dati[2::2]
        for i in range(len(oggetti)):
            if oggetti[i] not in diz:
                diz[oggetti[i]] = 'nessun rincaro'
                maxrincaro[oggetti[i]] = 0
            elif int(prezzi[i]) - prezzo[oggetti[i]] > maxrincaro[oggetti[i]]:
                diz[oggetti[i]] = mese
                maxrincaro[oggetti[i]] = int(prezzi[i]) - prezzo[oggetti[i]]
            prezzo[oggetti[i]] = int(prezzi[i])          
    f.close()
    return diz

    # SOLUZIONE MIA
    # fin = open(file, encoding='UTF-8')
    # s = fin.read().strip().split('\n')
    # fin.close()
    
    # prodotti = {}
    # rincaro = {}
    # ultimoprezzo = {}
    # for riga in s:
    #     riga = riga.strip().split(',')
    #     for i in range(1, len(riga), 2):
    #         prodotto = riga[i]
    #         prezzo = int(riga[i+1])
            
    #         if prodotto not in prodotti:
    #             prodotti[prodotto] = 'nessun rincaro'
    #             rincaro[prodotto] = 0
    #         elif prezzo - ultimoprezzo[prodotto] > rincaro[prodotto]:
    #             prodotti[prodotto] = riga[0]
    #             rincaro[prodotto] = prezzo - ultimoprezzo[prodotto]

    #         ultimoprezzo[prodotto] = prezzo
    
    # return prodotti

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['prezzi1.csv'],{'giacca': 'marzo', 'pantalone': 'febbraio', 'camicia': 'nessun rincaro'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi2.csv'],{'giacca': 'marzo', 'pantalone': 'aprile', 'camicia': 'aprile'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi3.csv'],{'giacca': 'marzo', 'pantalone': 'aprile', 'camicia': 'febbraio'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi4.csv'],{'giacca': 'marzo', 'pantalone': 'aprile', 'camicia': 'febbraio'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi5.csv'],{'giacca': 'aprile', 'pantalone': 'aprile', 'camicia': 'febbraio'})

    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex3, ['prezzi6.csv'],{'maglione': 'novembre', 'pantalone': 'ottobre', 'camicia': 'nessun rincaro'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi7.csv'],{'maglione': 'novembre', 'pantalone': 'dicembre', 'camicia': 'dicembre'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi8.csv'],{'maglione': 'novembre', 'pantalone': 'dicembre', 'camicia': 'ottobre'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi9.csv'],{'maglione': 'novembre', 'pantalone': 'dicembre', 'camicia': 'ottobre'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi10.csv'],{'maglione': 'dicembre', 'pantalone': 'dicembre', 'camicia': 'ottobre'})
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
