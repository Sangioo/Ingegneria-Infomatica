def Ex3(file):
    diz = {}
    prezzo = {}
    maxrincaro = {} 
    f = open(file,'r',encoding='UTF-8')
    for riga in f:
        dati = riga.strip().split(',')
        mese = dati[0]
        valute = dati[1::2]
        cambi = dati[2::2]
        for i in range(len(valute)):
            if valute[i] not in diz:
                diz[valute[i]] = 'nessun rincaro'
                maxrincaro[valute[i]] = 0
            elif float(cambi[i]) - prezzo[valute[i]] > maxrincaro[valute[i]]:
                diz[valute[i]] = mese
                maxrincaro[valute[i]] = float(cambi[i]) - prezzo[valute[i]]
            prezzo[valute[i]] = float(cambi[i])          
    f.close()
    return diz

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione
    
    counter_test_positivi += tester_fun(Ex3, ['cambi1.csv'],{'dollaro': '30', 'sterlina': '10', 'rublo': 'nessun rincaro'})
    counter_test_positivi += tester_fun(Ex3, ['cambi2.csv'],{'dollaro': '26', 'sterlina': '30', 'rublo': '30'})
    counter_test_positivi += tester_fun(Ex3, ['cambi3.csv'],{'dollaro': '17', 'sterlina': '18', 'rublo': '18'})
    counter_test_positivi += tester_fun(Ex3, ['cambi4.csv'],{'dollaro': '24', 'sterlina': '26', 'rublo': '22'})
    counter_test_positivi += tester_fun(Ex3, ['cambi5.csv'],{'dollaro': '65', 'sterlina': '65', 'rublo': '55'})
    

    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex3, ['cambi6.csv'],{'dracma': '45', 'sterlina': '40', 'rublo': 'nessun rincaro'})
    counter_test_positivi += tester_fun(Ex3, ['cambi7.csv'],{'dracma': '315', 'sterlina': '320', 'rublo': '320'})
    counter_test_positivi += tester_fun(Ex3, ['cambi8.csv'],{'dracma': '57', 'sterlina': '58', 'rublo': '58'})
    counter_test_positivi += tester_fun(Ex3, ['cambi9.csv'],{'dracma': '72', 'sterlina': '73', 'rublo': '71'})
    counter_test_positivi += tester_fun(Ex3, ['cambi10.csv'],{'dracma': '125', 'sterlina': '125', 'rublo': '110'})
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
