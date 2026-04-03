def A_Ex6(s1, s2):  # somma due numeri in CP2
    if len(s1) != len(s2):
        return "ERRORE"

    riporto = 0
    ris = ""
    for i in range(-1, -len(s1) - 1, -1):
        ris += str((int(s1[i]) + int(s2[i])) % 2 + riporto)
        if (int(s1[i]) + int(s2[i])) > 1:
            riporto = 1
        else:
            riporto = 0

    if ris[-1] != s1[0] and ris[-1] != s2[0]:
        return "ERRORE"

    return ris[::-1]


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""
if __name__ == "__main__":
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex6, ["00", "01"], "01")
    counter_test_positivi += tester_fun(A_Ex6, ["001", "001"], "010")
    counter_test_positivi += tester_fun(A_Ex6, ["010", "010"], "ERRORE")
    counter_test_positivi += tester_fun(A_Ex6, ["00", "010"], "ERRORE")
    counter_test_positivi += tester_fun(A_Ex6, ["000", "10"], "ERRORE")

    print(
        "La funzione",
        A_Ex6.__name__,
        "ha superato",
        counter_test_positivi,
        "test su",
        total_tests,
    )
