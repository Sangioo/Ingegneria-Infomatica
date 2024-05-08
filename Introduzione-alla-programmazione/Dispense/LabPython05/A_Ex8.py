def A_Ex8(n):
    if n <= 0: return 'ERRORE'
    ris = ''
    for i in range(n):
        for j in range(n):
            if i==0 or i==n-1 or j==0 or j==n-1:
                ris += '*'
            elif i==j or j==n-i-1:
                ris += '*'
            else:
                ris += ' '
        ris += '\n'
    
    return ris
            

       

###############################################################################

"""NON MODIFICARE IL SEGUENTE CODICE (codice di test della funzione)"""

if __name__ == '__main__':
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""
    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex8, [2],'**\n**\n')
    counter_test_positivi += tester_fun(A_Ex8, [5],'*****\n** **\n* * *\n** **\n*****\n')
    counter_test_positivi += tester_fun(A_Ex8, [6],'******\n**  **\n* ** *\n* ** *\n**  **\n******\n') 
    counter_test_positivi += tester_fun(A_Ex8, [1],'*\n')
    counter_test_positivi += tester_fun(A_Ex8, [-1],'ERRORE')

    print('La funzione',A_Ex8.__name__,'ha superato',counter_test_positivi,'test su',total_tests)

    
