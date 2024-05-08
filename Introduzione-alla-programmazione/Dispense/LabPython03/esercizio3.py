from funzioni_esercizi import livelloPalindromicita
s = input('inserire una stringa: ')

s = s.replace(' ', '').replace("'", '').replace('.', '').replace(',', '')
lvl = livelloPalindromicita(s)

if lvl >= len(s)//2:
    print('La frase è palindroma')
elif lvl != 0:
    print('La frase non è palindroma. Il livello massimo di palindromicità è', lvl)
else:
    print('La frase non ha nessun livello di palindromicità')