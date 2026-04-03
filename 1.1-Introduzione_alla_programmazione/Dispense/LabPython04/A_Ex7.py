def A_Ex7(
    ex, cp2
):  # riceve due numerali di lunghezza uguale e >0, EX CP2 e restituisce 'ex' se (ex)ex>(cp2)cp2
    if len(ex) != len(cp2):
        return "ERRORE"

    if cp2[0] == "0":
        cp2 = "1" + cp2[1:]
    else:
        cp2 = "0" + cp2[1:]

    if ex >= cp2:
        return "ex"
    else:
        return "cp2"


###############################################################################

"""NON MODIFICARE, codice di testing della funzione"""
if __name__ == "__main__":
    from tester import tester_fun

    counter_test_positivi = 0
    total_tests = 5

    counter_test_positivi += tester_fun(A_Ex7, ["000", "01"], "ERRORE")

    counter_test_positivi += tester_fun(A_Ex7, ["001", "001"], "cp2")

    counter_test_positivi += tester_fun(A_Ex7, ["010", "010"], "cp2")
    counter_test_positivi += tester_fun(A_Ex7, ["00", "010"], "ERRORE")
    counter_test_positivi += tester_fun(A_Ex7, ["001", "110"], "cp2")

    print(
        "La funzione",
        A_Ex7.__name__,
        "ha superato",
        counter_test_positivi,
        "test su",
        total_tests,
    )
