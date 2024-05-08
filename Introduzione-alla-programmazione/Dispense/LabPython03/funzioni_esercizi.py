def isIntero(s):
    if s == '':
        return False
    
    if s[0] == '+' or s[0] == '-':
        s = s[1:]
    
    if s.isdecimal():
        return True
    else:
        return False


def divisoreNonComune(n1, n2, d):
    if n1%d == 0 and n2%d != 0:
        return True
    else:
        return False


def livelloPalindromicita(s):
    counter = 0
    s = s.lower()
    for i in range(len(s)//2+1):
        if s[i] == s[-(i+1)]:
            counter += 1
        else:
            break
    return counter