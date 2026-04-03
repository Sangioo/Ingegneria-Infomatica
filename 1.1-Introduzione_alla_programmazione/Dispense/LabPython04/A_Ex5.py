def A_Ex5(s):
    max = 0
    index = 0
    for c in s:
        if s.count(c) >= max and s.rfind(c) > index:
            max = s.count(c)
            index = s.rfind(c)

    return s[index]


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""

if __name__ == "__main__":
    from tester import tester_fun

    """SE NON VOLETE ESEGUIRE UN TEST COMMENTATE LA RIGA RELATIVA CON #"""

    counter_test_positivi = 0
    total_tests = 4

    counter_test_positivi += tester_fun(A_Ex5, ["pippo"], "p")
    counter_test_positivi += tester_fun(A_Ex5, ["clarabella"], "a")
    counter_test_positivi += tester_fun(A_Ex5, ["mamma"], "m")
    counter_test_positivi += tester_fun(A_Ex5, ["cannolo"], "o")

    print(
        "La funzione",
        A_Ex5.__name__,
        "ha superato",
        counter_test_positivi,
        "test su",
        total_tests,
    )
