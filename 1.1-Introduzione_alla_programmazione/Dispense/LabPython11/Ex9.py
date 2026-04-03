import pandas as pd

def Ex9(file1,file2):
    try:
        f1 = pd.read_excel(file1)
        f2 = pd.read_excel(file2)
    except:
        print('file non trovati')
        return
    
    nan1 = f1.isna()
    nan2 = f2.isna()
    ris = 0
    artists = []
    for i in range(f1.shape[0]):
        if nan1['Artist ID'][i]:
            continue
        else:
            artists.append(f1['Artist ID'][i])
    
    for i in f2['Artist ID']:
        if type(i)==str:
            artist = i.split(',')
            for j in artist:
                j = int(j.strip())
                if j in artists:
                    ris += 1

        if i in artists:
            ris += 1
    
    return ris

###############################################################################

if __name__ == '__main__':
    from tester import tester_fun
    import re

    counter_test_positivi = 0
    total_tests = 4

    counter_test_positivi += tester_fun(Ex9, ["artisti1.xlsx","opere1.xlsx"] , 4)
    counter_test_positivi += tester_fun(Ex9, ["artisti1.xlsx","opere2.xlsx"] , 4)
    counter_test_positivi += tester_fun(Ex9, ["artisti2.xlsx","opere1.xlsx"] , 3)
    counter_test_positivi += tester_fun(Ex9, ["artisti2.xlsx","opere2.xlsx"] , 3)
   
    print('La funzione',Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
