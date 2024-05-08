def Ex3(file):
    fin = open(file, encoding='UTF-8')
    
    giocatori = fin.readline().strip().split(',')
    vittorie = [0]*len(giocatori)
    
    for riga in fin:
        riga = riga.strip().split(',')
        valida = True
        
        for i in range(len(riga)):
            riga[i] = int(riga[i])
            if riga[i] < 2 or riga[i] > 12:
                valida = False
        
        if valida and riga.count(max(riga)) == 1:
            vittorie[riga.index(max(riga))] += 1
    
    giocatori.reverse()
    vittorie.reverse()
    
    ris = set()
    for i in range(3):
        indice = vittorie.index(max(vittorie))
        ris.add(giocatori[indice])
        giocatori.pop(indice)
        vittorie.pop(indice)
    
    return ris

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['partite1.csv'],{'G3', 'G1', 'G2'})    
    counter_test_positivi += tester_fun(Ex3, ['partite2.csv'],{'G4', 'G3', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite3.csv'],{'G4', 'G3', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite4.csv'],{'G3', 'G1', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite5.csv'],{'G4', 'G1', 'G2'})

    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
