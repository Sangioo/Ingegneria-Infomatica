def A_Ex1(s1, s2):
    l = min(len(s1), len(s2))
    ris = ""
    for i in range(l):
        if s1[i] == s2[i]:
            ris += s1[i]
        else:
            return ris
    return ris


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == "__main__":
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex1, ["amaca", "amaranto"], "ama")
    counter_test_positivi += tester_fun(A_Ex1, ["asso", "assolato"], "asso")
    counter_test_positivi += tester_fun(A_Ex1, ["", "stringa"], "")
    counter_test_positivi += tester_fun(A_Ex1, ["stringa", ""], "")
    counter_test_positivi += tester_fun(A_Ex1, ["ciao mamma", "ciao "], "ciao ")

    print(
        "La funzione",
        A_Ex1.__name__,
        "ha superato",
        counter_test_positivi,
        "test su",
        total_tests,
    )
