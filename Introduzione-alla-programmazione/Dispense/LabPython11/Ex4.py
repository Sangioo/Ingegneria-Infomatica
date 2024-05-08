def Ex4(m):
    sv = 0
    so = 0
    for i in range(m.shape[0]):
        for j in range(m.shape[1]):
            if m[i-1,j] > m[i,j] < m[i+1,j] and i!=0 and i!=m.shape[0]-1:
                sv += 1
            if m[i,j-1] > m[i,j] < m[i,j+1] and j!=0 and j!=m.shape[1]-1:
                so += 1
    
    return sv, so
    
###############################################################################
import numpy as np
if __name__ == '__main__':
    from tester import tester_fun   

    counter_test_positivi = 0
    total_tests = 3

    counter_test_positivi += tester_fun(Ex4, [np.array([[1,1,1],[1,0,0],[1,1,1]])], (2,0))
    counter_test_positivi += tester_fun(Ex4, [np.array([[3,1,3],[2,1,2],[2,1,2]])], (0,3))
    counter_test_positivi += tester_fun(Ex4, [np.array([[1,2,3],[1,2,3],[1,2,3]])], (0,0))


    print('La funzione',Ex4.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
