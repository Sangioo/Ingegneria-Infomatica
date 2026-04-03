def tok(a, b, c):
    if a <= 0 or b <= 0 or c <= 0 or (a + b <= c) or (a + c <= b) or (b + c <= a):
        return "errore"
    elif a == b == c:
        return "equilatero"
    elif a == b or a == c or b == c:
        return "isoscele"
    else:
        return "scaleno"

def triangolo(a, b, c):
    if a <= 0 or b <= 0 or c <= 0 or (a + b < c) or (a + c < b) or (b + c <a):
        return "errore"
    elif a == b == c:
        return "equilatero"
    elif a == b or a == c or b == c:
        return "isoscele"
    else:
        return "scaleno"
