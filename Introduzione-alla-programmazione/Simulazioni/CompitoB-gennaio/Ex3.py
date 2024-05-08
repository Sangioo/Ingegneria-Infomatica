def Ex3(file,l):
    fin = open(file, encoding='UTF-8')
    spedizioneOfferta = l[0]
    ncorrieri = l[1]
    pesomax = l[2]
    
    ris = {}
    count = 1
    for riga in fin:
        riga = riga.strip().split(',')
        idpacco = riga[0]
        spedizioneRichiesta = riga[1]
        peso = int(riga[2])
        
        if spedizioneRichiesta != spedizioneOfferta:
            ris[idpacco] = 'Nessuno'
            continue
        elif peso > pesomax:
            ris[idpacco] = 'Nessuno'
            continue
        elif ncorrieri == 0:
            ris[idpacco] = 'Nessuno'
            continue
        
        ris[idpacco] = count
        count += 1
        pesomax -= peso
        ncorrieri -= 1
    
    return ris

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['pacchi1.csv',['Nazionale',2,800]],{'pacco1': 'Nessuno', 'pacco2': 1, 'pacco3': 2, 'pacco4': 'Nessuno', 'pacco5': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['pacchi1.csv',['Nazionale',3,600]],{'pacco1': 'Nessuno', 'pacco2': 1, 'pacco3': 'Nessuno', 'pacco4': 'Nessuno', 'pacco5': 2})
    counter_test_positivi += tester_fun(Ex3, ['pacchi2.csv',['Mondiale',2,400]],{'pacco1': 'Nessuno', 'pacco2': 'Nessuno', 'pacco3': 'Nessuno', 'pacco4': 1, 'pacco5': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['pacchi2.csv',['Europea',2,800]],{'pacco1': 1, 'pacco2': 'Nessuno', 'pacco3': 'Nessuno', 'pacco4': 'Nessuno', 'pacco5': 2})
    counter_test_positivi += tester_fun(Ex3, ['pacchi2.csv',['Nazionale',4,1000]],{'pacco1': 'Nessuno', 'pacco2': 1, 'pacco3': 2, 'pacco4': 'Nessuno', 'pacco5': 'Nessuno'})

    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
