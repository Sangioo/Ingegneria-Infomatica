def Ex2(file):
    import re
    
    fin = open(file, 'r', encoding='UTF-8')
    s = fin.read()
    fin.close()
    
    if s.strip() == '':
        return {}
    
    primo = r'^(([a-z]+,)*[a-z]+)\.([a-z]+)\.(\d+)\W([a-z]+)\W'
    matchp = re.findall(primo, s, re.IGNORECASE)
    
    regex = r'\s(([a-z]+,)*[a-z]+)\.([a-z]+)\.(\d+)\W([a-z]+)\W'
    match = re.findall(regex, s, re.IGNORECASE)
    
    if not match and not matchp:
        return {}
        
    ris = {}
    for k in match:
        citta = k[4]
        if citta not in ris:
            ris[citta] = [0]*3
        
        nome = k[0].split(',')
        
        if len(nome) == 1:
            ris[citta][0] += 1
        elif len(nome) == 2:
            ris[citta][1] += 1
        elif len(nome) > 2:
            ris[citta][2] += 1
    
    citta = matchp[0][4]
    if citta not in ris:
        ris[citta] = [0]*3
    
    nome = matchp[0][0].split(',')
    
    if len(nome) == 1:
        ris[citta][0] += 1
    elif len(nome) == 2:
        ris[citta][1] += 1
    elif len(nome) > 2:
        ris[citta][2] += 1
    
    return ris
    
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testob1.txt'],{'Roma': [1, 1, 0], 'Milano': [1, 0, 0]})
    counter_test_positivi += tester_fun(Ex2, ['testob2.txt'],{'Roma': [2, 4, 0], 'Milano': [3, 0, 0], 'Napoli': [1, 0, 0]})
    counter_test_positivi += tester_fun(Ex2, ['testob3.txt'],{})
    counter_test_positivi += tester_fun(Ex2, ['testob4.txt'],{})
    counter_test_positivi += tester_fun(Ex2, ['testob5.txt'],{})
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
