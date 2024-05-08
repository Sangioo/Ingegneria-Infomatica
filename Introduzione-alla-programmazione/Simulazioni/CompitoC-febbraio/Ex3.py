def Ex3(file1,n):
    fin = open(file1, encoding='UTF-8')
    s = fin.read().lower().strip().split()
    fin.close()
    print(s)
    
    diz = {}
    for c in 'abcdefghijklmnopqrstuvwxyz':
        prima = True
        for parola in s:
            if not parola.startswith(c):
                continue
            
            if parola.startswith(c) and prima:
                diz[c] = [parola]
                prima = False
                continue
            
            intersezione = set(parola).intersection(set(diz[c][-1]))
            if len(intersezione) == n:
                diz[c].append(parola)
    
    massimo = 0
    for k in diz.values():
        if len(k) > massimo:
            massimo = len(k)
    
    return massimo

###############################################################################
"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',3],2)
    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',4],1) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',2],3) 
    counter_test_positivi += tester_fun(Ex3, ['esempio1c.txt',1],2) 
    counter_test_positivi += tester_fun(Ex3, ['esempio2c.txt',5],2) 

    
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
