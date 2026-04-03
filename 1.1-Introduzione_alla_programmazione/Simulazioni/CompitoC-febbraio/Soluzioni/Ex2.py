def Ex2(file):
    import re
    s = open(file,encoding='UTF-8').read()
    s=s.lower()
    pattern = r'\b([^aeiou \n])(\w*\1\1\w*\b)'
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

    counter_test_positivi += tester_fun(Ex2, ['testo1c.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo2c.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo3c.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo4c.txt'], 1)
    counter_test_positivi += tester_fun(Ex2, ['testo5c.txt'], 0)
    
    # test aggiuntivi
  
    counter_test_positivi += tester_fun(Ex2, ['testo6c.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo7c.txt'], 1)
    counter_test_positivi += tester_fun(Ex2, ['testo8c.txt'], 0)
    counter_test_positivi += tester_fun(Ex2, ['testo9c.txt'], 1)
    counter_test_positivi += tester_fun(Ex2, ['testo10c.txt'], 0)
  
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
