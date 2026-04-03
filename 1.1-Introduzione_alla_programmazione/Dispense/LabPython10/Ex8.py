def Ex8(file):
    fin = open(file, encoding='UTF-8')
    
    regex = r'[A-Z]{3} ?[A-Z]{3} ?(\d\d)([A-Z])(\d\d) ?[A-Z]\d\d\d[A-Z]'
    
    tabmesi = {'A': ['01', 31],
               'B': ['02', 28],
               'C': ['03', 31],
               'D': ['04', 30],
               'E': ['05', 31],
               'H': ['06', 30],
               'L': ['07', 31],
               'M': ['08', 31],
               'P': ['09', 30],
               'R': ['10', 31],
               'S': ['11', 30],
               'T': ['12', 31]}
    
    ris = []
    for riga in fin:
        cv = re.findall(regex, riga)
        if cv == []:
            ris.append('Codice errato')
            continue

        anno = cv[0][0]
        mese = cv[0][1]
        giorno = cv[0][2]

        if int(giorno)>40:
            giorno = '0' + str(int(giorno)-40)
        
        if int(anno)<=20:
            anno = '20'+anno
        else:
            anno = '19'+anno
        
        if mese not in 'ABCDEHLMPRST':
            ris.append('Mese errato')
        elif giorno != tabmesi[mese] and not 1<=int(giorno)<=tabmesi[mese][1]:
            ris.append('Giorno errato')
        else:
            data = giorno[-2:] + '/' + tabmesi[mese][0] + '/' + anno
            ris.append(data)
        
    return ris
    
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex8, ["codici1.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato'])
    counter_test_positivi += tester_fun(Ex8, ["codici2.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato', 'Giorno errato', 'Codice errato', 'Giorno errato'])
    counter_test_positivi += tester_fun(Ex8, ["codici3.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato', 'Giorno errato', 'Codice errato', 'Giorno errato', '01/11/1921'])
    counter_test_positivi += tester_fun(Ex8, ["codici4.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato', 'Giorno errato', 'Codice errato', 'Giorno errato', '01/11/1921', '01/11/1931'])
    counter_test_positivi += tester_fun(Ex8, ["codici5.txt"] , ['12/03/1971', 'Codice errato', '15/04/2011', 'Mese errato', 'Giorno errato', 'Giorno errato', 'Codice errato', 'Giorno errato', '01/11/1921', '01/11/1931', 'Codice errato', 'Giorno errato'])

    print('La funzione',Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
