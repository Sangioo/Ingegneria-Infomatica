def Ex2(file,s):
    fin = open(file, encoding='UTF-8')
    
    vocalis = set(s).intersection('aeiou')
    
    ris = {}
    count = 1
    for riga in fin:
        riga = riga.strip().split()
        ris[count] = []
        
        for parola in riga:
            vocalip = set(parola.lower()).intersection('aeiou')
            
            if vocalip == vocalis:
                ris[count].append(parola)
        count += 1
            
    return ris
        
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testo1c.txt','lardo'], {1: ['Tanto'], 2: ['lardo', 'lorda'], 3: ['Datato']})
    counter_test_positivi += tester_fun(Ex2, ['testo1c.txt','difficile'],{1: [], 2: [], 3: []})
    counter_test_positivi += tester_fun(Ex2, ['testo1c.txt','casa'],{1: ['va', 'la', 'gatta'], 2: ['Al'], 3: []})
    counter_test_positivi += tester_fun(Ex2, ['testo2c.txt','tanto'],{1: ['Tanto', 'tonta'], 2: ['lardo', 'lorda', 'cosa'], 3: ['Darlo', 'ralod'], 4: ['LORDA']})
    counter_test_positivi += tester_fun(Ex2, ['testo3c.txt','ore'],{1: [], 2: [], 3: ['lorde'], 4: []})

    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
