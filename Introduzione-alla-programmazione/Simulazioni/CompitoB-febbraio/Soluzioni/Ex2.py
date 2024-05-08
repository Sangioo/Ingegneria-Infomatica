def Ex2(file):
    import re
    conta = 0
    f=open(file,'r',encoding='UTF-8')
    pattern = r'\b\w*(\w)\b\W+\b\1\w*(\w)\b\W+\b\2\w*\b'
    for riga in f:
        m = re.search(pattern,riga)
        if m:   #senza vincolo
            # print(m)
            conta += 1
    return conta   
    
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione
    
    counter_test_positivi += tester_fun(Ex2, ['testob1.txt'],2)
    counter_test_positivi += tester_fun(Ex2, ['testob2.txt'],1)
    counter_test_positivi += tester_fun(Ex2, ['testob3.txt'],1)
    counter_test_positivi += tester_fun(Ex2, ['testob4.txt'],2)
    counter_test_positivi += tester_fun(Ex2, ['testob5.txt'],0)
  
    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex2, ['testob6.txt'],6) 
    counter_test_positivi += tester_fun(Ex2, ['testob7.txt'],5) 
    counter_test_positivi += tester_fun(Ex2, ['testob8.txt'],5) 
    counter_test_positivi += tester_fun(Ex2, ['testob9.txt'],5) 
    counter_test_positivi += tester_fun(Ex2, ['testob10.txt'],6)
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
