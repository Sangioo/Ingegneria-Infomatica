def A_Ex4(filename,anno):
    fin = open(filename, encoding='UTF-8')
    s = fin.readline().strip().split(',')
    indice = s.index(str(anno))

    ris = ('', 0)
    for riga in fin:
        riga = riga.strip().split(',')
        if int(riga[indice]) >= ris[1]:
            ris = (riga[0], int(riga[indice]))
    
    fin.close()
    return ris[0]

     
###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex4, ['Vendite1.csv',2012] , 'Giubbotto')
    counter_test_positivi += tester_fun(A_Ex4, ['Vendite2.csv',2012] , 'Maglione')
    counter_test_positivi += tester_fun(A_Ex4, ['Vendite2.csv',2013] , 'Zaino')
    counter_test_positivi += tester_fun(A_Ex4, ['Vendite3.csv',2011] , 'Giubbotto')
    counter_test_positivi += tester_fun(A_Ex4, ['Vendite3.csv',2010] , 'Cellulare')
    
    print('La funzione',A_Ex4.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
