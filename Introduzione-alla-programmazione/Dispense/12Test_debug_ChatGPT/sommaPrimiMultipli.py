def sommaPrimiNmultipli(a,n): #calcola e restituisce la somma dei primi n multipli di a
    if a==0 or n== 0:
        return 0
    somma=0
    for i in range(n):
        somma+=i*a
    return somma

for i in range(1,10):
    ris=sommaPrimiNmultipli(3, i)
    print(ris)