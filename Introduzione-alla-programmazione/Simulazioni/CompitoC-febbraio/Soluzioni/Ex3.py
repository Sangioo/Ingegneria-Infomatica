def Ex3(file1,n):
    ris={}
    f = open(file1,'r',encoding='UTF-8')
    for r in f:
        riga=r.strip().split()
        #print('riga',riga)
        for parola in riga:
            parola=parola.lower()
            #print(parola)
            if parola[0] not in ris:
                ris[parola[0]]=[parola]
            elif len(set(ris[parola[0]][-1]).intersection(set(parola)))==n:
                ris[parola[0]].append(parola)
    print(ris)
    massimo=0
    for k in ris:
        if len(ris[k])>massimo:
            massimo=len(ris[k])
    return massimo

###############################################################################
"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',3],2)
    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',4],1) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',2],3) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',1],2) 
    counter_test_positivi += tester_fun(Ex3, ['esempio2c.txt',5],2) 

    
    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole.txt',2],7)
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole.txt',4],5)
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole.txt',6],4)
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole.txt',8],2)
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole.txt',10],1)
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
