def Ex2(file,s):
    diz = {}
    vocali_s=set()
    for c in s:
        if c.lower() in 'aeiou':
            vocali_s.add(c.lower())
    f = open(file,encoding='UTF-8')
    num = 1
    for riga in f:
        l = []
        parole = riga.strip().split()
        for parola in parole:
            vocali_p=set()
            for c in parola:
                if c.lower() in 'aeiou':
                    vocali_p.add(c.lower())
            if vocali_s==vocali_p:
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

    counter_test_positivi += tester_fun(Ex2, ['testo1c.txt','lardo'], {1: ['Tanto'], 2: ['lardo', 'lorda'], 3: ['Datato']})
    counter_test_positivi += tester_fun(Ex2, ['testo1c.txt','difficile'],{1: [], 2: [], 3: []})
    counter_test_positivi += tester_fun(Ex2, ['testo1c.txt','casa'],{1: ['va', 'la', 'gatta'], 2: ['Al'], 3: []})
    counter_test_positivi += tester_fun(Ex2, ['testo2c.txt','tanto'],{1: ['Tanto', 'tonta'], 2: ['lardo', 'lorda', 'cosa'], 3: ['Darlo', 'ralod'], 4: ['LORDA']})
    counter_test_positivi += tester_fun(Ex2, ['testo3c.txt','ore'],{1: [], 2: [], 3: ['lorde'], 4: []})

    # test aggiuntivi
  
    counter_test_positivi += tester_fun(Ex2, ['testo4c.txt','mado'],{1: ['Tanto', 'tonta'], 2: ['lardo', 'lorda', 'cosa'], 3: ['lardo', 'lorda'], 4: ['Darlo', 'ralod'], 5: ['carlo', 'moda', 'coral', 'Mado'], 6: ['orcal', 'odMA']})
    counter_test_positivi += tester_fun(Ex2, ['testo5c.txt','alpal'],{1: [], 2: ['casa'], 3: [], 4: [], 5: ['palla', 'allap'], 6: []})  
    counter_test_positivi += tester_fun(Ex2, ['testo4c.txt','orlac'],{1: ['Tanto', 'tonta'], 2: ['lardo', 'lorda', 'cosa'], 3: ['lardo', 'lorda'], 4: ['Darlo', 'ralod'], 5: ['carlo', 'moda', 'coral', 'Mado'], 6: ['orcal', 'odMA']})
    counter_test_positivi += tester_fun(Ex2, ['testo5c.txt','ollop'],{1: [], 2: [], 3: [], 4: [], 5: ['pollo'], 6: ['OLLOP', 'lolpo']})
    counter_test_positivi += tester_fun(Ex2, ['testo6c.txt','casa'],{1: ['Al', 'asca', 'CAAs'], 2: ['asAc'], 3: ['cassa', 'acsa'], 4: ['cas', 'saca']})
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
