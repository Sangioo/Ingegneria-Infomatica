def Ex3(file,l):
    ris = {}
    f = open(file,'r',encoding='UTF-8')
    ditta_sped = l[0]
    ditta_corrieri = l[1]
    ditta_peso = l[2]
    primo_corriere = 1
    for riga in f:
        dati = riga.strip().split(',')
        nome = dati[0]
        spedizione = dati[1]
        peso = int(dati[2])
        if spedizione == ditta_sped and primo_corriere <= ditta_corrieri and peso <= ditta_peso:
            ris[nome] = primo_corriere
            primo_corriere += 1
            ditta_peso -= peso
        else:
            ris[nome] = 'Nessuno'
    f.close()
    return ris

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""
#(MacOs Europea, Windows Nazionale, Mondiale Mondiale, Android Regionale

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['pacchi1.csv',['Nazionale',2,800]],{'pacco1': 'Nessuno', 'pacco2': 1, 'pacco3': 2, 'pacco4': 'Nessuno', 'pacco5': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['pacchi1.csv',['Nazionale',3,600]],{'pacco1': 'Nessuno', 'pacco2': 1, 'pacco3': 'Nessuno', 'pacco4': 'Nessuno', 'pacco5': 2})
    counter_test_positivi += tester_fun(Ex3, ['pacchi2.csv',['Mondiale',2,400]],{'pacco1': 'Nessuno', 'pacco2': 'Nessuno', 'pacco3': 'Nessuno', 'pacco4': 1, 'pacco5': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['pacchi2.csv',['Europea',2,800]],{'pacco1': 1, 'pacco2': 'Nessuno', 'pacco3': 'Nessuno', 'pacco4': 'Nessuno', 'pacco5': 2})
    counter_test_positivi += tester_fun(Ex3, ['pacchi2.csv',['Nazionale',4,1000]],{'pacco1': 'Nessuno', 'pacco2': 1, 'pacco3': 2, 'pacco4': 'Nessuno', 'pacco5': 'Nessuno'})

    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex3, ['pacchi3.csv',['Nazionale',4,1000]],{'pacco1': 'Nessuno', 'pacco2': 1, 'pacco3': 2, 'pacco4': 'Nessuno', 'pacco5': 'Nessuno', 'pacco6': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['pacchi3.csv',['Nazionale',3,600]],{'pacco1': 'Nessuno', 'pacco2': 1, 'pacco3': 'Nessuno', 'pacco4': 'Nessuno', 'pacco5': 'Nessuno', 'pacco6': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['pacchi3.csv',['Mondiale',2,400]],{'pacco1': 'Nessuno', 'pacco2': 'Nessuno', 'pacco3': 'Nessuno', 'pacco4': 1, 'pacco5': 'Nessuno', 'pacco6': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['pacchi4.csv',['Europea',2,800]],{'pacco1': 1, 'pacco2': 'Nessuno', 'pacco3': 'Nessuno', 'pacco4': 'Nessuno', 'pacco5': 2, 'pacco6': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['pacchi4.csv',['Nazionale',4,1000]],{'pacco1': 'Nessuno', 'pacco2': 1, 'pacco3': 2, 'pacco4': 'Nessuno', 'pacco5': 'Nessuno', 'pacco6': 'Nessuno'})
    


print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
