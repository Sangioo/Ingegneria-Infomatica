def A_Ex9(fileName,squadra):
    fin = open(fileName, encoding='UTF-8')
    fin.readline()

    punti = 0
    for riga in fin:
        riga = riga.strip().split(',')

        if squadra not in riga:
            continue

        puntiSquadra1 = 0
        puntiSquadra2 = 0
        if int(riga[2]) == int(riga[3]):
            puntiSquadra1 += 1
            puntiSquadra2 += 1
        elif int(riga[2]) > int(riga[3]):
            puntiSquadra1 += 3
        elif int(riga[2]) < int(riga[3]):
            puntiSquadra2 += 3
        
        if riga[0] == squadra:
            punti += puntiSquadra1
        elif riga[1] == squadra:
            punti += puntiSquadra2
    
    fin.close()
    return punti

 
###############################################################################

"""TEST FUNZIONE, NON MODIFICARE"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex9, ["partite1.csv",'Chelsea'] , 3)
    counter_test_positivi += tester_fun(A_Ex9, ["partite1.csv",'Tottenham'] , 1)
    counter_test_positivi += tester_fun(A_Ex9, ["partite2.csv",'Arsenal'] , 4)
    counter_test_positivi += tester_fun(A_Ex9, ["partite2.csv",'Bayern'] , 0)
    counter_test_positivi += tester_fun(A_Ex9, ["partite3.csv",'Bayern'] , 4)

    print('La funzione',A_Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
