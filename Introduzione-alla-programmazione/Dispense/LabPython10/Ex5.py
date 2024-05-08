def Ex5(file):
    fin = open(file, encoding='UTF-8')
    s = fin.read().strip()
    fin.close()
    
    ris = {'auto': 0, 'moto': 0, 'ciclomotore1': 0, 'ciclomotore2': 0, 'errata': 0}
    
    regex = {'auto': r'\b[A-Z][A-Z]\d\d\d[A-Z][A-Z]\b',
             'moto': r'\b[A-Z][A-Z]\d\d\d\d\d\b',
             'ciclomotore1': r'\b[A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9]\b',
             'ciclomotore2': r'\b[A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9][A-Z0-9]\b'}
    
    somma = 0
    for k in regex:
        targa = re.findall(regex[k], s, re.MULTILINE)
        ris[k] = len(targa)
        somma += len(targa)
    
    ris['errata'] = len(s.split('\n')) - somma
    
    return ris
    
      
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex5, ["targhe1.txt"] , {'auto': 2, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 1})
    counter_test_positivi += tester_fun(Ex5, ["targhe2.txt"] , {'auto': 2, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 2})
    counter_test_positivi += tester_fun(Ex5, ["targhe3.txt"] , {'auto': 3, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 3})
    counter_test_positivi += tester_fun(Ex5, ["targhe4.txt"] , {'auto': 3, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 4})
    counter_test_positivi += tester_fun(Ex5, ["targhe5.txt"] , {'auto': 2, 'moto': 1, 'ciclomotore1': 1, 'ciclomotore2': 1, 'errata': 5})
    
    print('La funzione',Ex5.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
