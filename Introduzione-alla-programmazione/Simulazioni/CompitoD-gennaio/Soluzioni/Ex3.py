def Ex3(file):
    ris=set() 
    f = open(file,'r',encoding='UTF-8')
    header=f.readline().strip().split(',')
    N=len(header)
    positive=[0]*N
    for riga in f:
        partita = riga.strip().split(',')
        for i in range(N):
            partita[i]=int(partita[i])
        if sum(partita) == 0: # la somma vale 0, quindi è una partita corretta
            for i in range(N):
                if partita[i] > 0:       #questo giocatore ha vinto qualcosa
                    positive[i] += 1
            
    while len(ris)<3:
        for i in range(N-1,-1,-1):
            if positive[i] == max(positive):
                 ris.add(header[i])
                 positive[i] = -1
                 break
    return ris
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['giochi1.csv'],{'G1', 'G4', 'G3'})   
    counter_test_positivi += tester_fun(Ex3, ['giochi2.csv'],{'G1', 'G4', 'G3'})
    counter_test_positivi += tester_fun(Ex3, ['giochi3.csv'],{'G1', 'G4', 'G3'})
    counter_test_positivi += tester_fun(Ex3, ['giochi4.csv'],{'G1', 'G3', 'G5'})
    counter_test_positivi += tester_fun(Ex3, ['giochi5.csv'],{'G1', 'G3', 'G7'})
    
    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex3, ['giochi6.csv'],{'G2', 'G3', 'G4'})
    counter_test_positivi += tester_fun(Ex3, ['giochi7.csv'],{'G2', 'G3', 'G4'})
    counter_test_positivi += tester_fun(Ex3, ['giochi8.csv'],{'G2', 'G3', 'G4'})
    counter_test_positivi += tester_fun(Ex3, ['giochi9.csv'],{'G2', 'G3', 'G4'})
    counter_test_positivi += tester_fun(Ex3, ['giochi10.csv'],{'G2', 'G3', 'G4'})    
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

