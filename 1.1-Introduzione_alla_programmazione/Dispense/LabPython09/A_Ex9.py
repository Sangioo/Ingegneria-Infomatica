def A_Ex9(nomeDiz,c,n):
    
    
    d=eval(open(nomeDiz,'r', encoding='utf8').read())     #non modificare questa istruzione
    
    # d è un dizionario {k:valore} dove k è l'intero corrispondente al numero di paragrafo dei Malavoglia e valore è una lista con due valori [ <testo del paragrafo>, <dizionario frequenza vocali del paragrafo> ]
    # esempio d[3]=['Giovanni Verga', {'a': 2, 'e': 1, 'i': 2, 'o': 1, 'u': 0}]
    # N.B. ci sono dei 'buchi' tra le chiavi del dizionario, corrispondenti a paragrafi vuoti. Per esempio la chiave 2 non esiste
    
    #non modificare il codice sopra che carica il dizionario
    ris = []
    for k in d:
        parola = d[k][0].strip().split()[0]
        counter = d[k][1].get(c, 0)
        if counter > n:
            ris.append(parola)
    return ris
    
    
###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == '__main__':
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 3

    counter_test_positivi += tester_fun(A_Ex9, ["dizionarioParagrafiMalavoglia.txt",'a',230] , ['Comare', 'Il', 'A', 'Con', 'Una', 'La', 'Intanto', 'Don'])
    counter_test_positivi += tester_fun(A_Ex9, ["dizionarioParagrafiMalavoglia.txt",'u',33] , ['Il', 'Il', 'I', 'Nel', 'Comare', 'Don', 'Il', 'Mastro', 'Campana', 'Il', 'Padron', 'Il', '—', '—', 'A', 'Mentre', 'La', 'Con', 'Quando', 'Una', 'Una', 'Anche', '’Ntoni', '’Ntoni', 'La', 'Ma', 'Comare', 'Intanto', 'Don', 'Alfio', 'Così'])
    counter_test_positivi += tester_fun(A_Ex9, ["dizionarioParagrafiMalavoglia.txt",'u',90] , [])

    print('La funzione',A_Ex9.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

