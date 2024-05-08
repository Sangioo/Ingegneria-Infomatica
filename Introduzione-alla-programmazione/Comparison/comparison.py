def myfunction(file, nome):
    f = open(file, encoding='UTF-8')
	
    ris = set()
    vittorie = {}
    for riga in f:
        riga = riga.strip().split(',')
		
        if riga[0] == nome and riga[2] == '2':
            vittorie[riga[1]] = vittorie.get(riga[1], 0) + 1
        elif riga[1] == nome and riga[2] == '1':
            vittorie[riga[0]] = vittorie.get(riga[0], 0) + 1
        else:
            vittorie[riga[0]] = vittorie.get(riga[0], 0)
            vittorie[riga[1]] = vittorie.get(riga[1], 0)
	
    massimo = max(list(vittorie.values()), default=0)
	
    for k in vittorie:
        if vittorie[k] == massimo and k != nome:
            ris.add(k)
	
    return ris

def proffunction(file,nome):
    f = open(file, "r")
    dati = []
    for riga in f:
        dati.append(riga.strip().split(","))
    f.close()

    giocatori = []
    for riga in dati:
        for giocatore in riga[:2]:
            if giocatore not in giocatori:
                giocatori.append(giocatore)

    massimo = 0
    insieme = set()
    for g in giocatori:
        if g != nome:
            conta = 0
            for riga in dati:
                if (nome in riga and g in riga[0] and riga[2] == '1')  or (nome in riga and g in riga[1] and riga[2] == '2'):
                    conta += 1
            if conta == massimo:
                insieme.add(g)
            elif conta > massimo:
                massimo = conta
                insieme = {g}

    return insieme

if __name__ == '__main__':
    import time
    import numpy as np

    prove = [('partite1.csv', 'Piero'),
            ('partite1.csv', 'Gianni'),
            ('partite1.csv', 'Gianni'),
            ('partite2.csv', 'Piero'),
            ('partite2.csv', 'Paolo'),
            ('partite2.csv', 'Anna'),
            ('partite3.csv', 'Paolo'),
            ('partite3.csv', 'Piero'),
            ('partite3.csv', 'Piero'),
            ('partite4.csv', 'Paolo'),
            ('partite4.csv', 'Paolo'),
            ('partite4.csv', 'Anna'),
            ('partite5.csv', 'Gianni'),
            ('partite5.csv', 'Paolo'),
            ('partite5.csv', 'Gianni'),
            ('partite6.csv', 'Anna'),
            ('partite6.csv', 'Gianni'),
            ('partite6.csv', 'Paolo'),
            ('partite7.csv', 'Piero'),
            ('partite7.csv', 'Anna'),
            ('partite7.csv', 'Gianni'),
            ('partite8.csv', 'Anna'),
            ('partite8.csv', 'Anna'),
            ('partite8.csv', 'Anna'),
            ('partite9.csv', 'Anna'),
            ('partite9.csv', 'Anna'),
            ('partite9.csv', 'Gianni'),
            ('partite10.csv', 'Anna'),
            ('partite10.csv', 'Paolo'),
            ('partite10.csv', 'Gianni')]

    myfunction_times = []
    print('times for myfunction():')
    for coppia in prove:
        start_time = time.time()
        ret = myfunction(coppia[0], coppia[1])

        delta_time = time.time() - start_time
        myfunction_times.append(delta_time)
        print('\tdelta time:', delta_time)

    myfunction_times = np.array(myfunction_times)
    print('\nmyfunction max:', myfunction_times.max())
    print('myfunction min:', myfunction_times.min())
    print('myfunction avg:', myfunction_times.mean())

    proffunction_times = []
    print('times for proffunction():')
    for coppia in prove:
        start_time = time.time()
        ret = proffunction(coppia[0], coppia[1])

        delta_time = time.time() - start_time
        proffunction_times.append(delta_time)
        print('\tdelta time:', delta_time)

    proffunction_times = np.array(proffunction_times)
    print('\nproffunction max:', proffunction_times.max())
    print('proffunction min:', proffunction_times.min())
    print('proffunction avg:', proffunction_times.mean())