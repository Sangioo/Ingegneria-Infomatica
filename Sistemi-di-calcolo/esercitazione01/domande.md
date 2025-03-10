## Domanda 1 Quale dei seguenti frammenti di codice potrebbe essere scritto in linguaggio macchina?
  - [x] A. 55 23 C3 D3 00 00 00 C3
  - [ ] B. movl $2, %eax
  - [ ] C. while(i<y) i++;
  - [ ] D. Nessuno dei precedenti

## Domanda 2 Quanti bit servono per rappresentare il numero esadecimale 0xDEADBEEF?
  - [ ] A. 8
  - [ ] B. 16
  - [ ] C. 24
  - [x] D. 32

## Domanda 3 Il comando gcc hello.s -o hello attiva i seguenti stadi della toolchain di compilazione:

  - [x] A. assemblatore e linker
  - [ ] B. assemblatore
  - [ ] C. linker
  - [ ] D. preprocessore, compilatore e assemblatore

## Domanda 4 Il comando gcc hello.o -o hello attiva i seguenti stadi della toolchain di compilazione:

  - [ ] A. preprocessore
  - [ ] B. assemblatore e linker
  - [x] C. linker
  - [ ] D. preprocessore, compilatore e assemblatore

## Domanda 5 Fra i seguenti, qual è il tipo primitivo C con la dimensione (sizeof) minore che consente di rappresentare il numero 256?

  - [ ] A. char
  - [ ] B. unsigned char
  - [x] C. short
  - [ ] D. nessuno dei precedenti

## Domanda 6 Per quale operatore bit-a-bit OP si ha che 0x13 OP 0x21 == 0x32?

  - [ ] A. ~ (NOT)
  - [ ] B. & (AND)
  - [ ] C. | (OR)
  - [x] D. ^ (XOR)

## Domanda 7 Dati:
```c
char s[]="hello";
int a=sizeof(s), b=strlen(s), c=sizeof("hello");
```
quale delle seguenti affermazioni è vera? Assumere puntatori a 64 bit.

  - [x] A. a=6, b=5, c=6
  - [ ] B. a=6, b=5, c=5
  - [ ] C. a=5, b=5, c=5
  - [ ] D. a=6, b=5, c=8
