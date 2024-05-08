import pandas


df=pandas.read_excel('esami.xlsx')


print(df)



stop()






























def excel2diz(nome_file):
    import pandas
    df=pandas.read_excel(nome_file)
    diz={}
    for nome in df.columns:                 
        diz[nome]=list(set(df[nome])) #valori della colonna nome
        diz[nome].sort()
    return diz

d=excel2diz('esami.xlsx')
d1=excel2diz('esami1.xlsx')  #campi vuoti
print(d)
print(d1)


def excel2diz3(nome_file):
    import pandas
    import math
    df=pandas.read_excel(nome_file)
    righeOK=[]
    righeNAN=[]
    for i in range(df.shape[0]):     #righe               
        for j in range(df.shape[1]):       #righe 
            if type((df.values[i][j]))==float and  math.isnan(df.values[i][j]):
                righeNAN.append((i,list(df.values[i])))
                break
        righeOK.append((i,list(df.values[i])))        
    return righeOK,righeNAN
a,b=excel2diz3('esami2.xlsx')  #file con campi non numerici vuoti: produce un errore nel sort
print(a)
print()
print(b)
