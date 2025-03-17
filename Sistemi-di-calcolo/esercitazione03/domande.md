## Domanda 1) Si vuole tradurre l’istruzione C if (a <= c) goto L, dove a è una variable unsigned int memorizzata nel registro eax e c è una variable unsigned int memorizzata nel registro ecx, occorre usare:

    A. “cmpl %eax, %ecx” e “jle L”
    B. “cmpl %ecx, %eax” e “jle L”
    C. “cmpl %eax, %ecx” e “jbe L”
    D. “cmpl %ecx, %eax” e “jbe L”

## Domanda 2) Si consideri il seguente frammento di codice:
```asm
1. xorl %eax, %eax
2. movw $1337, %ax
3. movl $2, %ecx
4. imulw %cx, %ax
5. andl $11, %eax
6. ???
7. ret
```
Quale delle seguenti istruzioni può essere inserita a linea 6 per far ritornare alla funzione il valore 20?

    A. orl $10, %eax
    B. xorl $15, %eax
    C. notl %eax
    D. Nessuna delle precedenti

## Domanda 3) Si assuma di operare in una architettura IA32 sul seguente frammento di memoria (indirizzo: valore):
```
0x1000: 0xA1
0x1001: 0xB2
0x1002: 0xC3
0x1003: 0xD4
```
Eseguendo le seguenti istruzioni:
```asm
movw $0xF5E6, 0x1002
movl 0x1000, %eax
```
(NOTA: l’istruzione mov permette di leggere o scrivere direttamente su un indirizzo di memoria fornito come valore costante sotto forma di operando S o D nella forma esadecimale 0x????) Cosa conterrà il registro %eax?

    A. 0xF5E6A1B2
    B. 0xF5E6B2A1
    C. 0xA1B2F5E6
    D. 0xE6F5B2A1

## Domanda 4) Si consideri il seguente frammento di programma:
```c
int x = 1;
printf(“%d\n”, *(char*)&x);
```
In quali casi il programma stampa 0?

    A. In nessun caso
    B. Solo se la piattaforma è big-endian
    C. Solo se la piattaforma è little-endian
    D. Solo se la piattaforma è a 32 bit
