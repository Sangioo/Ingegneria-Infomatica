## Domanda 1
L’operando `(%eax, %ecx, 5)` è valido?
- [x] A. Si
- [ ] B. No

## Domanda 2
Si consideri la variabile `int* p` e si assuma che venga tenuta nel registro `%eax`. A quale istruzione assembly corrisponde l’istruzione C `p++`?
- [ ] A. `incl %eax`
- [ ] B. `addl $2,%eax`
- [x] C. `addl $4,%eax`
- [ ] D. `incw %ax`

## Domanda 3
Quali delle seguenti operazioni IA32 permette di azzerare il registro `%eax`?
- [ ] A. `movl $0, %eax`
- [ ] B. `andl $0, %eax`
- [ ] C. `xorl %eax, %eax`
- [x] D. qualunque delle precedenti

## Domanda 4
Quali dei seguenti predicati C permette di verificare se la variabile `int x` contiene un valore pari?
- [ ] A. `x & 1 == 0`
- [ ] B. `x | 1 == 1`
- [ ] C. `x % 2 == 1`
- [x] D. Nessuna delle precedenti

## Domanda 5
Come tradurresti in IA32 l’assegnamento `v[5] = 7`, assumendo che `v` sia `int*` e sia tenuto nel registro `%eax`?
- [ ] A. `movl $7, 5(%eax)`
- [ ] B. `movl $7, 10(%eax)`
- [x] C. `movl $7, 20(%eax)`
- [ ] D. nessuna delle precedenti

## Domanda 6
Si consideri la riga di comando `gcc main.c prova.s -o prova` su una piattaforma a 64 bit. Dove `prova.s` è un codice IA32. Che esito probabile ti aspetteresti?
- [ ] A. Link error
- [x] B. Segmentation Fault
- [ ] C. Il programma, se corretto, funziona normalmente.
