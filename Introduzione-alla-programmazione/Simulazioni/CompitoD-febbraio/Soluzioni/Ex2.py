def Ex2(file):
    import re
    s = open(file,encoding='UTF-8').read()
    s=s.lower()
    pattern = r'\b([aeiou])(\w+\1\w+\1\b)'
    l= re.findall(pattern, s,re.IGNORECASE)
    print(l)
    return len(l)
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testo1d.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo2d.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo3d.txt'], 1)
    counter_test_positivi += tester_fun(Ex2, ['testo4d.txt'], 1)
    counter_test_positivi += tester_fun(Ex2, ['testo5d.txt'], 3)
    
    # test aggiuntivi
  
    counter_test_positivi += tester_fun(Ex2, ['testo6d.txt'], 1)
    counter_test_positivi += tester_fun(Ex2, ['testo7d.txt'], 3)
    counter_test_positivi += tester_fun(Ex2, ['testo8d.txt'], 0)
    counter_test_positivi += tester_fun(Ex2, ['testo9d.txt'], 3)
    counter_test_positivi += tester_fun(Ex2, ['testo10d.txt'], 5)
  
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
