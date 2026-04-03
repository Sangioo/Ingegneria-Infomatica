def Ex2(file):
    f = open(file, encoding='UTF-8')
    s = f.read().strip().split()
    f.close()
	
    ultima = s[-1]
    s = ''.join(s)
    s = s.replace(ultima, '')
	
    ris = {}
    for c in ultima:
        ris[c] = s.count(c)
		
    return ris

###################################################################


"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testo1.txt'],{'p': 0, 'a': 3, 'l': 1, 'o': 3, 'n': 0, 'e': 0})
    counter_test_positivi += tester_fun(Ex2, ['testo2.txt'],{'a': 6, 'b': 2, 'o': 2, 'm': 0, 'i': 1, 'n': 1, 'e': 6, 'v': 1, 'l': 3})
    counter_test_positivi += tester_fun(Ex2, ['testo3.txt'],{'a': 0})
    counter_test_positivi += tester_fun(Ex2, ['testo4.txt'],{'c': 0, 'a': 0, 's': 0})   
    counter_test_positivi += tester_fun(Ex2, ['testo5.txt'],{'s': 0, 't': 0, 'a': 10, 'b': 10, 'i': 2, 'l': 6, 'e': 3})
 
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
