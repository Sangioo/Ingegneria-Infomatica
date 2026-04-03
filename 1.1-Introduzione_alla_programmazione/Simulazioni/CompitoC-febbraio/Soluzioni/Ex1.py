def Ex1(l):
    massimo = 0
    for i in range(len(l)):
        if l[i] >=100:
            continue
        conta=1
        somma=l[i]
        for j in range(i+1,len(l)):
            somma+=l[j]
            if somma>=100:
                break
            else:
                conta +=1
        if conta>massimo:
            massimo=conta
    return massimo
    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, [[335,88,21,2,3,9,150]],4)
    counter_test_positivi += tester_fun(Ex1, [[335]],0)
    counter_test_positivi += tester_fun(Ex1, [[1,2,3,4,5,6,7]],7)
    counter_test_positivi += tester_fun(Ex1, [[]],0)
    counter_test_positivi += tester_fun(Ex1, [[335,188,221]],0)   

    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex1, [[1]],1)
    counter_test_positivi += tester_fun(Ex1, [[335,1,2]],2)
    counter_test_positivi += tester_fun(Ex1, [[5]],1)
    counter_test_positivi += tester_fun(Ex1, [[1,2,35]],3)
    counter_test_positivi += tester_fun(Ex1, [[335,188,5]],1)
   
    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
