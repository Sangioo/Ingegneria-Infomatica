def Ex2(file,s):
    diz = {}
    maiuscole_s=set()
    for c in s:
        if c.isupper():
            maiuscole_s.add(c)
    f = open(file,encoding='UTF-8')
    num = 1
    for riga in f:
        l = []
        parole = riga.strip().split()
        for parola in parole:
            maiuscole_p = set()
            for c in parola:
                if c.isupper():
                    maiuscole_p.add(c)
            if len(maiuscole_p) > 0 and len(maiuscole_s & maiuscole_p) == 0:
                l.append(parola)
        diz[num] = l
        num += 1
    return diz
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['file1.txt','LarDo'], {1: ['Tanto'], 2: ['Al'], 3: ['raSe']})
    counter_test_positivi += tester_fun(Ex2, ['file1.txt','diFfIciLe'],{1: ['Tanto'], 2: ['Al'], 3: ['Datato', 'raSe']})
    counter_test_positivi += tester_fun(Ex2, ['file1.txt','cASa'],{1: ['Tanto'], 2: [], 3: ['Datato']})
    counter_test_positivi += tester_fun(Ex2, ['file2.txt','TantO'],{1: [], 2: ['Al', 'LA'], 3: ['Darlo'], 4: []})
    counter_test_positivi += tester_fun(Ex2, ['file3.txt','oRE'],{1: ['Tanto'], 2: ['Al', 'LA'], 3: ['Al', 'CAAs'], 4: ['Darlo', 'asAc']})

    # test aggiuntivi
  
    counter_test_positivi += tester_fun(Ex2, ['file4.txt','mado'],{1: ['Tanto'], 2: ['Al', 'LA'], 3: ['Al'], 4: ['Darlo'], 5: ['Mado'], 6: ['odMA']})
    counter_test_positivi += tester_fun(Ex2, ['file5.txt','aLpAl'],{1: ['Darlo'], 2: [], 3: ['Mado'], 4: [], 5: [], 6: []})  
    counter_test_positivi += tester_fun(Ex2, ['file4.txt','OrLac'],{1: ['Tanto'], 2: ['Al'], 3: ['Al'], 4: ['Darlo'], 5: ['Mado'], 6: ['odMA']})
    counter_test_positivi += tester_fun(Ex2, ['file5.txt','ollOP'],{1: ['Darlo'], 2: [], 3: ['Mado'], 4: ['odMA'], 5: [], 6: []})
    counter_test_positivi += tester_fun(Ex2, ['file6.txt','casaPS'],{1: ['Al', 'CAAs'], 2: ['Darlo', 'asAc'], 3: [], 4: []})
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
