def Ex2(file):
    f=open(file,'r',encoding='UTF-8')
    ris={}
    for r in f:
        riga=r.split()
        for elem in riga:
            elem=elem.split('(')
            città=elem[-1]
            persona=elem[0].split('.')
            if len(persona)<3:
                continue
            if elem[-1][-1]==')' and elem[-1][0:-1].isalpha(): #città ok
                città=città[:-1]
                if persona[2].isdecimal() and persona[1].isalpha(): #Cognome e telefono ok
                    nomi=persona[0].split(',')
                    nomiOk=True
                    for n in nomi:
                        if not n.isalpha():
                            nomiOk=False
                    if nomiOk:
                        if città not in ris:
                            ris[città]=[0,0,0]
                        if len(nomi)>2:
                            ris[città][2]+=1
                        elif len(nomi)>1:
                            ris[città][1]+=1
                        else:
                            ris[città][0]+=1
                        #print(ris)
    return ris   
            
###############################################################################

"""NON MODIFICARE IL CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 10

 
    counter_test_positivi += tester_fun(Ex2, ['testob1.txt'],{'Roma': [1, 1, 0], 'Milano': [1, 0, 0]})
    counter_test_positivi += tester_fun(Ex2, ['testob2.txt'],{'Roma': [2, 4, 0], 'Milano': [3, 0, 0], 'Napoli': [1, 0, 0]})
    counter_test_positivi += tester_fun(Ex2, ['testob3.txt'],{})
    counter_test_positivi += tester_fun(Ex2, ['testob4.txt'],{})
    counter_test_positivi += tester_fun(Ex2, ['testob5.txt'],{})


    # test aggiuntivi

    counter_test_positivi += tester_fun(Ex2, ['testob6.txt'],{'Roma': [0, 0, 1]})
    counter_test_positivi += tester_fun(Ex2, ['testob7.txt'],{'Roma': [1, 1, 1]})
    counter_test_positivi += tester_fun(Ex2, ['testob8.txt'],{'Roma': [1, 0, 0], 'Napoli': [0, 1, 0], 'Milano': [0, 0, 1]})
    counter_test_positivi += tester_fun(Ex2, ['testob9.txt'],{'Napoli': [1, 1, 1]})
    counter_test_positivi += tester_fun(Ex2, ['testob10.txt'],{})
    
    print('La funzione',Ex2.__name__,'ha superato',counter_test_positivi,'test su',total_tests)
