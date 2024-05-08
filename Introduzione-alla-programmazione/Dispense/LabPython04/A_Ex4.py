def A_Ex4(n1, n2):
    ris = 0
    for i in range(abs(n2)):
        ris += n1
    if n2 < 0:
        return -ris
    return ris


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == "__main__":
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex4, [5, 2], 10)
    counter_test_positivi += tester_fun(A_Ex4, [-3, 4], -12)
    counter_test_positivi += tester_fun(A_Ex4, [20, 5], 100)
    counter_test_positivi += tester_fun(A_Ex4, [-6, -50], 300)
    counter_test_positivi += tester_fun(A_Ex4, [2, 0], 0)

    print(
        "La funzione",
        A_Ex4.__name__,
        "ha superato",
        counter_test_positivi,
        "test su",
        total_tests,
    )
