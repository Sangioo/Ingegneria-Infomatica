def Ex3(file1):
    ris=set() 
    f1 = open(file1,'r',encoding='UTF-8')
    header=f1.readline().strip().split(',')
    N=len(header)
    vinte=[0]*N
    for riga in f1:
        partita = riga.strip().split(',')
        partitaOK = True

        for i in range(N):
            partita[i]=int(partita[i])
            if partita[i] < 2 or partita[i] > 12:
                partitaOK = False
        if partitaOK:
            if partita.count(max(partita)) == 1:       #esiste un vincitore
                vinte[partita.index(max(partita))] += 1
            
        
    while len(ris)<3:
        for i in range(N-1,-1,-1):
            if vinte[i] == max(vinte):
                 ris.add(header[i])
                 vinte[i]=-1
                 break
    return ris

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['partite1.csv'],{'G3', 'G1', 'G2'})    
    counter_test_positivi += tester_fun(Ex3, ['partite2.csv'],{'G4', 'G3', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite3.csv'],{'G4', 'G3', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite4.csv'],{'G3', 'G1', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite5.csv'],{'G4', 'G1', 'G2'})
    
    
    
    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex3, ['partite6.csv'],{'G3', 'G1', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite7.csv'],{'G4', 'G3', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite8.csv'],{'G4', 'G3', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite9.csv'],{'G4', 'G3', 'G2'})
    counter_test_positivi += tester_fun(Ex3, ['partite10.csv'],{'G3', 'G5', 'G2'})    
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
