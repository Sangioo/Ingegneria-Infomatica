

def Ex2(file):
    d={}
    f=open(file,'r',encoding='UTF-8')
    s=f.read().strip().split()
    for c in s[-1]:
        d[c]=0
    for p in s[0:-1]:
        if p!=s[-1]:
            for c in p:
                if c in d:
                    d[c]=d[c]+1
    return d

s='pipo'

s=='pippo'


###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex2, ['testo1.txt'],{'p': 0, 'a': 3, 'l': 1, 'o': 3, 'n': 0, 'e': 0})
    counter_test_positivi += tester_fun(Ex2, ['testo2.txt'],{'a': 6, 'b': 2, 'o': 2, 'm': 0, 'i': 1, 'n': 1, 'e': 6, 'v': 1, 'l': 3})
    counter_test_positivi += tester_fun(Ex2, ['testo3.txt'],{'a': 0})
    counter_test_positivi += tester_fun(Ex2, ['testo4.txt'],{'c': 0, 'a': 0, 's': 0})   
    counter_test_positivi += tester_fun(Ex2, ['testo5.txt'],{'s': 0, 't': 0, 'a': 10, 'b': 10, 'i': 2, 'l': 6, 'e': 3})
    


    # test correzione 

    counter_test_positivi += tester_fun(Ex2, ['testo6.txt'],{'v': 1, 'o': 4, 'l': 1})
    counter_test_positivi += tester_fun(Ex2, ['testo7.txt'],{'a': 6, 'b': 3, 'r': 3, 'e': 1, 'v': 0, 'i': 3})
    counter_test_positivi += tester_fun(Ex2, ['testo8.txt'],{'c': 0, 'a': 4, 'm': 0, 'b': 2, 'i': 4, 't': 2, 'e': 2})
    counter_test_positivi += tester_fun(Ex2, ['testo9.txt'],{'b': 0, 'r': 0, 'u': 1, 'c': 0, 'i': 0, 'o': 1})    
    counter_test_positivi += tester_fun(Ex2, ['testo10.txt'],{'r': 3, 'i': 2, 'v': 1, 'n': 2, 'c': 0, 't': 1, 'a': 5})
   
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
