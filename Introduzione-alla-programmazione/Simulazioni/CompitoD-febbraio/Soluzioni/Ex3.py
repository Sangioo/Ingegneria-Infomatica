def Ex3(file1,n):
    ris={}
    f = open(file1,'r',encoding='UTF-8')
    for r in f:
        riga=r.strip().split()
        #print('riga',riga)
        for parola in riga:
            parola=parola.lower()
            #print(parola)
            if parola[-1] not in ris:
                ris[parola[-1]]=[parola]
            elif len(set(ris[parola[-1]][-1]).intersection(set(parola))) >= n:
                ris[parola[-1]].append(parola)
                print(parola[-1],ris[parola[-1]])
    massimo=0
    print(ris)
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

    counter_test_positivi += tester_fun(Ex3, ['esempio1d.txt',3],2)
    counter_test_positivi += tester_fun(Ex3, ['esempio1d.txt',4],2) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1d.txt',2],3) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1d.txt',1],5) 
    counter_test_positivi += tester_fun(Ex3, ['esempio2d.txt',5],2) 

    
    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole2.txt',10],1)
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole2.txt',7],25)
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole2.txt',8],1)
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole2.txt',9],1)
    counter_test_positivi += tester_fun(Ex3, ['I_Malavoglia_parole2.txt',11],1)
    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
