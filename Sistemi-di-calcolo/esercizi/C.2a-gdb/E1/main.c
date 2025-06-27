// Compilare con:
// > gcc -g -o e main.c e.c
// dove il flag "-g" serve per aggiungere informazioni di debugging
// 
// 1) Eseguire per vedere che il risultato del programma non e' corretto
// 2) Avviare il debbuger GDB con:
//    > gdb ./e
// 3) Analizzare uso dei seguenti comandi GDB:
//    - go: far partire debugging con la tui
//    - continue (c): eseguire il resto del programma fino al prossimo breakpoint o termine
//    - step (s): eseguire un'istruzione
//    - next (n): eseguire atomicamente tutti gli effetti dell'attuale istruzione
//    - finish (f): terminare esecuzione attuale funzione (fermarsi dopo return)
//    - print (p): stampare valore variabile C
//    - x: examinare contenuto delle memoria ad un indirizzoù
//    - refresh: refres output
//    - break (b): settare un breakpoint
//    - info breakpoints: breakpoint configurati
//    - delete: eliminare breakpoint
//    - quit (q): uscire da GDB
// 4) Identificare errore logico del programma

#include <stdio.h>

void factorial(int n, int* res);

int main() {
    int n;
    printf("Inserisci un numero: ");
    int r = scanf("%d", &n);
    printf("\n");
    if (r == EOF) return -1;
    int res;
    factorial(n, &res);
    printf("Risultato: %d\n", res);
    return 0;
}