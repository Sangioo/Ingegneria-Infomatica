def Ex3(file,l):
    fin = open(file, encoding='UTF-8')
    host = l[0]
    cores = l[1]
    ramd = l[2]
    
    ris = {}
    stop = False
    corecount = 0
    for riga in fin:
        riga = riga.strip().split(',')
        prog = riga[0]
        os = riga[1]
        ram = int(riga[2])
        
        if os != host:
            ris[prog] = 'Nessuno'
            continue
        if cores == corecount:
            ris[prog] = 'Nessuno'
            continue
        if ramd < ram:
            ris[prog] = 'Nessuno'
            continue
        
        ris[prog] = corecount + 1
        corecount += 1
        ramd -= ram
    
    return ris
        

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex3, ['programmi1.csv',['Windows',2,8]],{'prog1': 'Nessuno', 'prog2': 1, 'prog3': 2, 'prog4': 'Nessuno', 'prog5': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['programmi1.csv',['Windows',3,6]],{'prog1': 'Nessuno', 'prog2': 1, 'prog3': 'Nessuno', 'prog4': 'Nessuno', 'prog5': 2})
    counter_test_positivi += tester_fun(Ex3, ['programmi2.csv',['Linux',2,4]],{'prog1': 'Nessuno', 'prog2': 'Nessuno', 'prog3': 'Nessuno', 'prog4': 1, 'prog5': 'Nessuno'})
    counter_test_positivi += tester_fun(Ex3, ['programmi2.csv',['MacOS',2,8]],{'prog1': 1, 'prog2': 'Nessuno', 'prog3': 'Nessuno', 'prog4': 'Nessuno', 'prog5': 2})
    counter_test_positivi += tester_fun(Ex3, ['programmi2.csv',['Windows',4,10]],{'prog1': 'Nessuno', 'prog2': 1, 'prog3': 2, 'prog4': 'Nessuno', 'prog5': 'Nessuno'})

    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
