def Ex3(m):
    d1 = 0
    d2 = 0
    for i in range(m.shape[0]):
        for j in range(m.shape[1]):
            if i == j and m[i,j] == 1:
                d1 += 1
            if i == (m.shape[0]-1)-j and m[i,j] == 1:
                d2 += 1
    
    if d1 > d2:
        return 'Principale'
    elif d2 > d1:
        return 'Secondaria'
    else:
        return 'Uguali'

   
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re
    import numpy as np

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex3, [np.array([[1,0],[1,1]])], 'Principale')
    counter_test_positivi += tester_fun(Ex3, [np.array([[0,1],[1,1]])], 'Secondaria')
    counter_test_positivi += tester_fun(Ex3, [np.array([[1,1],[1,1]])], 'Uguali')
    counter_test_positivi += tester_fun(Ex3, [np.array([[1,1,1],[1,1,1],[1,1,1]])], 'Uguali')
    counter_test_positivi += tester_fun(Ex3, [np.array([])], 'Uguali')
    print('La funzione',Ex3.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
