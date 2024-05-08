def Ex1(n,l):
    ris = 0
    
    for i in l:
        try:
            ris += n//i
        except:
            continue
    return ris
    
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex1, [5,[5,1,0,2]] , 8)
    counter_test_positivi += tester_fun(Ex1, [10,[0]] , 0)
    counter_test_positivi += tester_fun(Ex1, [-1,[4,2]] , -2)
    counter_test_positivi += tester_fun(Ex1, [100,[0,2,4]], 75)
    counter_test_positivi += tester_fun(Ex1, [1000,[]] , 0)
    
    print('La funzione',Ex1.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
