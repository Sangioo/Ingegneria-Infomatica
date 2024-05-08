def isPari(n):
    if n % 2 == 0:
        return True
    else:
        return False

def isPrimo(n):
    if n==1 or n==2:
        return True
    maxdivisore = int(1+n**0.5)
    for i in range(2,maxdivisore):
        if n % i == 0:
            return False
    return True
