def Ex2(file):
    import re
    
    fin = open(file, encoding='UTF-8')
    s = fin.read()
    fin.close()
    
    regex = r'\b([^aeiou \n])\w*\1\1\w*\b'
    
    match = re.findall(regex, s, re.IGNORECASE)
    
    return len(match)
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testo1c.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo2c.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo3c.txt'], 2)
    counter_test_positivi += tester_fun(Ex2, ['testo4c.txt'], 1)
    counter_test_positivi += tester_fun(Ex2, ['testo5c.txt'], 0)
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
