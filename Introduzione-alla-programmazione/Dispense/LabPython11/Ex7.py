import pandas as pd

def Ex7(anno,file):
    try:
        f = pd.read_excel(file)
    except:
        print('file non trovato')
        return
    
    nans = f.notna()
    ris = 0
    for i in range(f.shape[0]):
        if not nans.values[i][-2] or f.values[i][-2]+50.0 >= anno:
            continue
        
        if nans.values[i][-1] and f.values[i][-1] <= anno:
            continue
        
        ris += 1
    
    return ris

###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex7, [2000,"artisti1.xlsx"] , 11)
    counter_test_positivi += tester_fun(Ex7, [1980,"artisti1.xlsx"] , 7)
    counter_test_positivi += tester_fun(Ex7, [2000,"artisti2.xlsx"] , 16)
    counter_test_positivi += tester_fun(Ex7, [1980,"artisti2.xlsx"] , 10)
    counter_test_positivi += tester_fun(Ex7, [1950,"artisti2.xlsx"] , 4)
   
    print('La funzione',Ex7.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
