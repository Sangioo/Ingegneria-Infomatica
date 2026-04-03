def Ex3(file):
    fin = open(file, encoding='UTF-8')
    s = fin.read().strip().split('\n')
    fin.close()
    
    prodotti = {}
    rincaro = {}
    ultimoprezzo = {}
    for riga in s:
        riga = riga.strip().split(',')
        for i in range(1, len(riga), 2):
            prodotto = riga[i]
            prezzo = int(riga[i+1])
            
            if prodotto not in prodotti:
                prodotti[prodotto] = 'nessun rincaro'
                rincaro[prodotto] = 0
            elif prezzo - ultimoprezzo[prodotto] > rincaro[prodotto]:
                prodotti[prodotto] = riga[0]
                rincaro[prodotto] = prezzo - ultimoprezzo[prodotto]

            ultimoprezzo[prodotto] = prezzo
    
    return prodotti
            

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['prezzi1.csv'],{'giacca': 'marzo', 'pantalone': 'febbraio', 'camicia': 'nessun rincaro'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi2.csv'],{'giacca': 'marzo', 'pantalone': 'aprile', 'camicia': 'aprile'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi3.csv'],{'giacca': 'marzo', 'pantalone': 'aprile', 'camicia': 'febbraio'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi4.csv'],{'giacca': 'marzo', 'pantalone': 'aprile', 'camicia': 'febbraio'})
    counter_test_positivi += tester_fun(Ex3, ['prezzi5.csv'],{'giacca': 'aprile', 'pantalone': 'aprile', 'camicia': 'febbraio'})

    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
