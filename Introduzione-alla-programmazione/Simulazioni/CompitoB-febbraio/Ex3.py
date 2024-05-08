def Ex3(file):
    fin = open(file, encoding='UTF-8')
    
    rincaro = {}
    pcambi = {}
    ris = {}
    for riga in fin:
        riga = riga.strip().split(',')
        print(riga)
        giorno = riga[0]
        valute = riga[1::2].copy()
        cambi = [float(x) for x in riga[2::2]]
        
        for i in range(len(valute)):
            if valute[i] not in pcambi:
                rincaro[valute[i]] = 0
                ris[valute[i]] = 'nessun rincaro'
            
            elif cambi[i] - pcambi[valute[i]] > rincaro[valute[i]]:
                rincaro[valute[i]] = cambi[i] - pcambi[valute[i]]
                ris[valute[i]] = giorno
                
            pcambi[valute[i]] = cambi[i]
    
    return ris

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['cambi1.csv'],{'dollaro': '30', 'sterlina': '10', 'rublo': 'nessun rincaro'})
    counter_test_positivi += tester_fun(Ex3, ['cambi2.csv'],{'dollaro': '26', 'sterlina': '30', 'rublo': '30'})
    counter_test_positivi += tester_fun(Ex3, ['cambi3.csv'],{'dollaro': '17', 'sterlina': '18', 'rublo': '18'})
    counter_test_positivi += tester_fun(Ex3, ['cambi4.csv'],{'dollaro': '24', 'sterlina': '26', 'rublo': '22'})
    counter_test_positivi += tester_fun(Ex3, ['cambi5.csv'],{'dollaro': '65', 'sterlina': '65', 'rublo': '55'})

    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
