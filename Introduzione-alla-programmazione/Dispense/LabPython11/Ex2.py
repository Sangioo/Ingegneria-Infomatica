def Ex2(file):
    import pandas
    import numpy
    try:
        f = numpy.load(file)
    except FileNotFoundError:
        return ([],[])
    except ValueError:
        f = pandas.read_csv(file, header=None)
    
    nan = f.isna()
    ris1 = []
    for i in range(f.shape[0]):
        somma = 0
        for j in range(f.shape[1]):
            if nan.values[i][j]:
                continue
            somma += f.values[i][j]
        ris1.append(somma)
    
    ris2 = []
    for i in f.columns:
        ris2.append(f[i].sum())
        
    return ris1, ris2
   
###############################################################################

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(Ex2, ["file2_1.csv"] , ([108,17,122],[90,25,30,102]))
    counter_test_positivi += tester_fun(Ex2, ["file2_2.csv"] , ([],[]))
    counter_test_positivi += tester_fun(Ex2, ["file2_3.csv"] , ([10],[2,3,0,5]))
    counter_test_positivi += tester_fun(Ex2, ["file2_4.csv"] , ([104,10],[1,15,98]))
    counter_test_positivi += tester_fun(Ex2, ["file2_5.csv"] , ([105,10,3,2],[5,15,100]))
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
