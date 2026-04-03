def Ex1(l):
    massimo = 0
    for i in range(len(l)):
        for j in range(i+1,len(l)+1):
            minimo = min(l[i:j])
            if minimo > 0:
                lung = j-i
                if lung>massimo:
                    massimo=lung
    return massimo
    

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione

    counter_test_positivi += tester_fun(Ex1, [[3,2,-8,1,2,3,9,0]],4)
    counter_test_positivi += tester_fun(Ex1, [[335]],1)
    counter_test_positivi += tester_fun(Ex1, [[1,-2,3,4,5,-6,7]],3)
    counter_test_positivi += tester_fun(Ex1, [[0]],0)
    counter_test_positivi += tester_fun(Ex1, [[35,-1,2]],1)
   
    

    # test aggiuntivi
    
    counter_test_positivi += tester_fun(Ex1, [[1]],1)
    counter_test_positivi += tester_fun(Ex1, [[335,-1,2,3]],2)
    counter_test_positivi += tester_fun(Ex1, [[-5]],0)
    counter_test_positivi += tester_fun(Ex1, [[1,2,335]],3)
    counter_test_positivi += tester_fun(Ex1, [[335,188,-5]],2)
   



    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
