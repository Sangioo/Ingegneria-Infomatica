def Ex7(file):
    fin = open(file, encoding='UTF-8')
    s = fin.read().strip()
    fin.close()
    print(s)
    
    ris = {'invalidi': 0, 'domestici': 0, 'altri': 0}
    
    redom = r'\b(192)\.(168)\.(0?0?\d|0?\d\d|1\d\d|2[0-4]\d|25[0-5])\.(0?0?\d|0?\d\d|1\d\d|2[0-4]\d|25[0-5])\b'
    domestici = re.findall(redom, s)
    ris['domestici'] = len(domestici)
    
    real = r'\b(0?0?\d|0?\d\d|1\d\d|2[0-4]\d|25[0-5])\.(0?0?\d|0?\d\d|1\d\d|2[0-4]\d|25[0-5])\.(0?0?\d|0?\d\d|1\d\d|2[0-4]\d|25[0-5])\.(0?0?\d|0?\d\d|1\d\d|2[0-4]\d|25[0-5])\b'
    altri = re.findall(real, s)
    altri = set(altri).difference(set(domestici))
    ris['altri'] = len(altri)
    
    ris['invalidi'] = len(s.split('\n')) - len(domestici) - len(altri)
    
    return ris
    
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex7, ["ip1.txt"] , {'invalidi': 0, 'domestici': 0, 'altri': 5})
    counter_test_positivi += tester_fun(Ex7, ["ip2.txt"] , {'invalidi': 2, 'domestici': 1, 'altri': 2})
    counter_test_positivi += tester_fun(Ex7, ["ip3.txt"] , {'invalidi': 1, 'domestici': 1, 'altri': 3})
    counter_test_positivi += tester_fun(Ex7, ["ip4.txt"] , {'invalidi': 1, 'domestici': 1, 'altri': 3})
    counter_test_positivi += tester_fun(Ex7, ["ip5.txt"] , {'invalidi': 3, 'domestici': 0, 'altri': 2})
    
    print('La funzione',Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
