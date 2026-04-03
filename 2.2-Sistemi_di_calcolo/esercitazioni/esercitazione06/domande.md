## Domanda 1

Assumendo che il registro %ecx contenga il valore 0xF0F0F0F0, dopo aver eseguito l’istruzione “shll $4, %ecx” quale delle seguenti affermazioni risulta vera:

- [ ] A. Il bit più significativo di %ecx è 1
- [ ] B. Il bit meno significativo di %ecx è 1
- [x] C. %cl contiene il valore 0
- [ ] D. %ch contiene il valore 0
- [ ] E. Se si esegue l’istruzione “sarl $4, %ecx” si riporta il valore di %ecx a 0xF0F0F0F0

## Domanda 2

Assumendo che il registro %ecx contenga il valore 0x00FF00FF, quale delle seguenti affermazioni risulta vera:

- [ ] A. Se eseguiamo “sarl $3, %ecx” otteniamo in %ecx un numero più grande rispetto a prima
- [x] B. Se eseguiamo “sarl $8, %ecx” oppure “shrl $8, %ecx” otteniamo lo stesso valore in %ecx
- [ ] C. Se eseguiamo “sarl $31, %ecx” otteniamo in %ecx un numero diverso da 0
- [ ] D. Se eseguiamo “sarb $1, %cl” il valore contenuto in %ecx cambia
- [ ] E. Nessuna delle precedenti

## Domanda 3

Quale delle seguenti istruzioni NON calcola lo stesso risultato di “shll $1, %eax”:

- [ ] A. imul $2, %eax
- [ ] B. addl %eax, %eax
- [ ] C. leal (%eax, %eax), %eax
- [x] D. leal 2(%eax), %eax
- [ ] E. sall $1, %eax

## Domanda 4

Siano %eax=33 (decimale), %edx=0 (decimale) e %ecx=10 (decimale), quale delle seguenti affermazioni risulta vera:

- [ ] A. Per calcolare %eax diviso 10 posso eseguire “idivl %eax” oppure “sarl $10, %eax”
- [ ] B. “idivl $3” è un’istruzione valida e calcola “%edx:%eax” diviso 3
- [ ] C. Non posso usare “sarl” per calcolare %eax diviso 2, perché %eax contiene un valore che non è una potenza di 2
- [x] D. “idivl %ecx” scrive il valore 3 nel registro %eax e nel registro %edx
- [ ] E. Nessuna delle precedenti

## Domanda 5

Data la struct C “struct s { char x, short * y; int z;}”, quanti byte (sizeof) sono necessari per memorizzarla in stack?

- [ ] A. 7
- [ ] B. 8
- [ ] C. 10
- [x] D. 12
- [ ] E. 14
- [ ] F. 16

## Domanda 6

Data la struct C “struct s { char x, short y; char z;}”, quanti byte di padding sono presenti nella struct?

- [ ] A. 0
- [ ] B. 1
- [x] C. 2
- [ ] D. 3
- [ ] E. 4

## Domanda 7

Data la struct C “struct s { char x, int y; char * z; short q; char p; }”, qual è l’offset del campo p?

- [ ] A. 8
- [ ] B. 10
- [ ] C. 12
- [x] D. 14
- [ ] E. 16

## Domanda 8

Considerata la costante -72, quale tra le seguenti affermazioni risulta essere vera?

- [ ] A. La sua rappresentazione binaria (8 bit) è 0100 1000
- [ ] B. La sua rappresentazione binaria (16 bit) è 1111 1111 1011 0110
- [ ] C. La sua rappresentazione binaria (16 bit) è 0000 0000 1011 0110
- [ ] D. La sua rappresentazione binaria (16 bit) è 1111 1111 0100 1000
- [ ] E. Se gli viene sommato 1 la sua rappresentazione binaria (16 bit) è 1111 1111 1011 1000
- [x] F. Nessuna delle precedenti
