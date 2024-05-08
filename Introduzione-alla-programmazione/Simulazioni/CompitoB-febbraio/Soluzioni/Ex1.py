def Ex1(v,i1,i2):
    maxlen = 0
    for i in range(len(v)):
        for j in range(i+1,len(v)):
            if j+1-i > maxlen and v[i:j+1].count(i1) == v[i:j+1].count(i2) and v[i:j+1].count(i1)>0:
                maxlen = j+1-i
                #print(v[i:j+1])
    return maxlen

###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

    # test distribuzione
  
    counter_test_positivi += tester_fun(Ex1, [[9,5,7,33,9,5,5,5,8,5,33,33,6,15,8,5,6],33,5],9)
    counter_test_positivi += tester_fun(Ex1, [[9,5],9,5],2)
    counter_test_positivi += tester_fun(Ex1, [[7,4,11,33,9,5,14,2],9,5],8)
    counter_test_positivi += tester_fun(Ex1, [[7,4,11,9,9,5,14,2],9,5],4)
    counter_test_positivi += tester_fun(Ex1, [[],9,5],0)
 
   
    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex1, [[9,6],33,3],0)
    counter_test_positivi += tester_fun(Ex1, [[7,4,11,33,9,5,14,2],9,5] , 8)
    counter_test_positivi += tester_fun(Ex1, [[9,7,88,55,42,8,5],9,5],7)   
    counter_test_positivi += tester_fun(Ex1, [[7,4,11,33,7,5,14,2],33,7],7)
    counter_test_positivi += tester_fun(Ex1, [[7,4,11,7,9,9,5,14,8,2],7,8] , 9)


    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
