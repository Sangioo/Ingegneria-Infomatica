## Domanda 1

Siano %eax=20 (decimale), %edx=0 (decimale) e %ecx=8 (decimale). Con riguardo alle due istruzioni “idivl %ecx” e “sarl $3, %eax”, quale delle seguenti affermazioni risulta vera:

- [ ] A. Le due istruzioni scrivono lo stesso valore in %eax, ma “idivl” è più efficiente di “sarl”
- [x] B. Le due istruzioni scrivono lo stesso valore in %eax, ma “sarl” è più efficiente di “idivl”
- [ ] C. Le due istruzioni scrivono valori diversi in %eax
- [ ] D. In questo caso la “idivl” non modifica il valore del registro %edx
- [ ] E. Nessuna delle precedenti

## Domanda 2

Assumendo %eax=0xFF000000, %ecx=1 (decimale) e %edx=10 (decimale), dopo aver eseguito l’istruzione “testl %eax, %eax” quale delle seguenti affermazioni risulta vera:

- [x] A. Se eseguiamo “cmovnzl %edx, %ecx” viene scritto il valore 10 nel registro %ecx
- [ ] B. Se eseguiamo “cmovzl %edx, %ecx” viene scritto il valore 0 nel registro %ecx
- [ ] C. L’istruzione “cmovnzw %dx, %cx” non modifica il valore del registro %ecx
- [ ] D. L’istruzione “cmovel %edx, %ecx” è equivalente all’istruzione “cmovnzl $10, %ecx”
- [ ] E. Nessuna delle precedenti

## Domanda 3

Assumendo %eax=10 (decimale), %ecx=7 (decimale) e %edx=2 (decimale), quale delle seguenti affermazioni risulta vera:

- [ ] A. Se eseguiamo “cmpl %ecx, %eax” e “cmovlel %edx, %eax” viene scritto il valore 2 nel registro %eax
- [ ] B. Se eseguiamo “cmpl %ecx, %eax” e “cmovbl %edx, %eax” viene scritto il valore 2 nel registro %eax
- [ ] C. Se eseguiamo “cmpb $0, %al” e “cmovel %edx, %eax” viene scritto il valore 2 nel registro %eax
- [x] D. Se eseguiamo “subl %ecx, %eax” e “cmovgl %edx, %eax” viene scritto il valore 2 nel registro %eax
- [ ] E. Nessuna delle precedenti

## Domanda 4

Quale delle seguenti è un’istruzione valida:

- [ ] A. cmovzb %al, %cl
- [ ] B. cmovzl $3, %eax
- [ ] C. cmovgew %ax, (%ecx)
- [x] D. cmpl %ecx, $10
- [ ] E. Nessuna delle precedenti
