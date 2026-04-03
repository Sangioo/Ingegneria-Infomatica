def A_Ex8(file):
    fin = open(file, encoding='UTF-8')
    ris = {}
    
    for riga in fin:
        riga = riga.strip().split(',')
        
        nome1 = riga[0].strip()
        nome2 = riga[1].strip()
        valore = riga[2].strip()
        if valore == 'amici':
            ris[nome1] = ris.get(nome1, set())
            ris[nome1].add(nome2)
            ris[nome2] = ris.get(nome2, set())
            ris[nome2].add(nome1)
        elif valore == 'nemici':
            ris[nome1] = ris.get(nome1, set())
            ris[nome1].discard(nome2)
            ris[nome2] = ris.get(nome2, set())
            ris[nome2].discard(nome1)
        
    for k in ris:
        ris[k] = list(ris[k])
        ris[k].sort()
    
    fin.close()
    return ris
    
    
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, ["amici1.csv"] , {'Paolo': ['Marco'], 'Marco': ['Paolo'], 'Anna': ['Maria', 'Paola'], 'Maria': ['Anna'], 'Paola': ['Anna'], 'Giorgio': []})
    counter_test_positivi += tester_fun(A_Ex8, ["amici2.csv"] , {'Paolo': ['Marco'], 'Marco': ['Paolo'], 'Anna': ['Maria'], 'Maria': ['Anna'], 'Paola': [], 'Giorgio': []})
    counter_test_positivi += tester_fun(A_Ex8, ["amici3.csv"] , {'Paolo': ['Marco'], 'Marco': ['Paolo'], 'Anna': ['Maria', 'Paola'], 'Maria': ['Anna'], 'Paola': ['Anna'], 'Giorgio': []})
    counter_test_positivi += tester_fun(A_Ex8, ["amici4.csv"] , {'Marco': ['Giorgio', 'Paolo'], 'Giorgio': ['Marco'], 'Paolo': ['Marco'], 'Anna': ['Maria', 'Paola'], 'Maria': ['Anna'], 'Paola': ['Anna']})
    counter_test_positivi += tester_fun(A_Ex8, ["amici5.csv"] , {'Marco': [], 'Giorgio': [], 'Paola': [], 'Anna': []})

    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
