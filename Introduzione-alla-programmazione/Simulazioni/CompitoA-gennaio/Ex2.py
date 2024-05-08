def Ex2(file):
    import re
    
    fin = open(file, encoding='UTF-8')
    s = fin.read()
    fin.close()
    
    corrette = r' \b((\w+\.)*\w+)@((\w+\.)*\w+)\b'
    matchCorrette = re.findall(corrette, s)
    
    ris = {}
    for k in matchCorrette:
        ris[k[2]] = [0]*3
    
    for k in matchCorrette:
        if k[2] in ris:
            key = k[2]
            partesinistra = k[0].split('.')
            
            if '' in partesinistra:
                continue
            
            if len(partesinistra) == 1:
                ris[key][0] += 1
            elif len(partesinistra) == 2:
                ris[key][1] += 1
            elif len(partesinistra) >= 3:
                ris[key][2] += 1
    
    return ris

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testoa1.txt'],{'gmail.com': [1, 1, 1], 'studenti.uniroma1.it': [0, 1, 0]})
    counter_test_positivi += tester_fun(Ex2, ['testoa2.txt'],{'gmail.com': [1, 1, 1], 'uniroma1.it': [0, 0, 1], 'studenti.uniroma1.it': [0, 1, 0], 'me.com': [0, 0, 1]})
    counter_test_positivi += tester_fun(Ex2, ['testoa3.txt'],{'gmail.com': [1, 1, 1], 'uniroma1.it': [0, 0, 1], 'studenti.uniroma1.it': [0, 1, 0], 'me.com': [0, 0, 1]})
    counter_test_positivi += tester_fun(Ex2, ['testoa4.txt'],{'gmail.com': [1, 1, 1], 'uniroma1.it': [0, 0, 1], 'studenti.uniroma1.it': [0, 1, 1], 'me.com': [1, 0, 1]})
    counter_test_positivi += tester_fun(Ex2, ['testoa5.txt'],{'gmail.com': [1, 1, 1], 'uniroma1.it': [0, 0, 1], 'studenti.uniroma1.it': [0, 1, 1], 'me.com': [1, 0, 1], 'dominio': [1, 0, 0]})

    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
