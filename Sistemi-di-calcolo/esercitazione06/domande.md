## Domanda 1

Assumendo che il registro %ecx contenga il valore 0xF0F0F0F0, dopo aver eseguito l’istruzione “shll $4, %ecx” quale delle seguenti affermazioni risulta vera:

- [ ] Il bit più significativo di %ecx è 1
- [ ] Il bit meno significativo di %ecx è 1
- [x] %cl contiene il valore 0
- [ ] %ch contiene il valore 0
- [ ] Se si esegue l’istruzione “sarl $4, %ecx” si riporta il valore di %ecx a 0xF0F0F0F0

## Domanda 2

Assumendo che il registro %ecx contenga il valore 0x00FF00FF, quale delle seguenti affermazioni risulta vera:

- [ ] Se eseguiamo “sarl $3, %ecx” otteniamo in %ecx un numero più grande rispetto a prima
- [x] Se eseguiamo “sarl $8, %ecx” oppure “shrl $8, %ecx” otteniamo lo stesso valore in %ecx
- [ ] Se eseguiamo “sarl $31, %ecx” otteniamo in %ecx un numero diverso da 0
- [ ] Se eseguiamo “sarb $1, %cl” il valore contenuto in %ecx cambia
- [ ] Nessuna delle precedenti

## Domanda 3

Quale delle seguenti istruzioni NON calcola lo stesso risultato di “shll $1, %eax”:

- [ ] imul $2, %eax
- [ ] addl %eax, %eax
- [ ] leal (%eax, %eax), %eax
- [x] leal 2(%eax), %eax
- [ ] sall $1, %eax

## Domanda 4

Siano %eax=33 (decimale), %edx=0 (decimale) e %ecx=10 (decimale), quale delle seguenti affermazioni risulta vera:

- [ ] Per calcolare %eax diviso 10 posso eseguire “idivl %eax” oppure “sarl $10, %eax”
- [ ] “idivl $3” è un’istruzione valida e calcola “%edx:%eax” diviso 3
- [ ] Non posso usare “sarl” per calcolare %eax diviso 2, perché %eax contiene un valore che non è una potenza di 2
- [x] “idivl %ecx” scrive il valore 3 nel registro %eax e nel registro %edx
- [ ] Nessuna delle precedenti

## Domanda 5

Data la struct C “struct s { char x, short * y; int z;}”, quanti byte (sizeof) sono necessari per memorizzarla in stack?

- [ ] 7
- [ ] 8
- [ ] 10
- [x] 12
- [ ] 14
- [ ] 16

## Domanda 6

Data la struct C “struct s { char x, short y; char z;}”, quanti byte di padding sono presenti nella struct?

- [ ] 0
- [ ] 1
- [x] 2
- [ ] 3
- [ ] 4

## Domanda 7

Data la struct C “struct s { char x, int y; char * z; short q; char p; }”, qual è l’offset del campo p?

- [ ] 8
- [ ] 10
- [ ] 12
- [x] 14
- [ ] 16

## Domanda 8

Considerata la costante -72, quale tra le seguenti affermazioni risulta essere vera?

- [ ] La sua rappresentazione binaria (8 bit) è 0100 1000
- [ ] La sua rappresentazione binaria (16 bit) è 1111 1111 1011 0110
- [ ] La sua rappresentazione binaria (16 bit) è 0000 0000 1011 0110
- [ ] La sua rappresentazione binaria (16 bit) è 1111 1111 0100 1000
- [ ] Se gli viene sommato 1 la sua rappresentazione binaria (16 bit) è 1111 1111 1011 1000
- [x] Nessuna delle precedenti
