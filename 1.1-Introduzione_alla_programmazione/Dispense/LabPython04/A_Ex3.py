def A_Ex3(n):
    for i in range(2, n // 2):
        if n % i == 0:
            return False
    return True


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == "__main__":
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex3, [7], True)
    counter_test_positivi += tester_fun(A_Ex3, [4096], False)
    counter_test_positivi += tester_fun(A_Ex3, [137], True)
    counter_test_positivi += tester_fun(A_Ex3, [140], False)
    counter_test_positivi += tester_fun(A_Ex3, [977], True)

    print(
        "La funzione",
        A_Ex3.__name__,
        "ha superato",
        counter_test_positivi,
        "test su",
        total_tests,
    )
