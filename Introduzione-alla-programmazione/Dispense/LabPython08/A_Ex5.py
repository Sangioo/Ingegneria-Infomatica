def A_Ex5(filename,oggetto):
    fin = open(filename, encoding='UTF-8')
    anni = fin.readline().strip().split(',')

    for riga in fin:
        if oggetto not in riga:
            continue
        
        riga = riga.strip().split(',')
        maxDiff = 0
        anno = anni[1]
        for i in range(2, len(riga)):
            if int(riga[i]) - int(riga[i-1]) > maxDiff:
                maxDiff = int(riga[i]) - int(riga[i-1])
                anno = anni[i]
            elif int(riga[i]) - int(riga[i-1]) == maxDiff and int(riga[i]) > int(riga[i-1]):
                anno = anni[i]
        break

    fin.close()
    return int(anno)




###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex5, ['Vendite1.csv','Giubbotto'] , 2012)
    counter_test_positivi += tester_fun(A_Ex5, ['Vendite1.csv','Zaino'] , 2010)
    counter_test_positivi += tester_fun(A_Ex5, ['Vendite2.csv','Maglione'] , 2012)
    counter_test_positivi += tester_fun(A_Ex5, ['Vendite2.csv','Zaino'] , 2013)
    counter_test_positivi += tester_fun(A_Ex5, ['Vendite3.csv','Giubbotto'] , 2013)

    print('La funzione',A_Ex5.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
