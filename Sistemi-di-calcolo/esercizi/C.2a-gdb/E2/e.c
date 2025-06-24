// Compilare con:
// > gcc -g -o e main.c e.c
// dove il flag "-g" serve per aggiungere informazioni di debugging
// 
// 1) Eseguire per vedere che il programma va in crash
// 2) Avviare il debbuger GDB con:
//    > gdb ./e
// 3) Analizzare uso dei seguenti comandi GDB:
//    - go: far partire debugging con la tui
//    - continue (c): eseguire il resto del programma fino al prossimo breakpoint o termine
//    - backtrace: analizzare stacktrace al momento del crash
// 4) Identificare errore del programma

#include <stdio.h>

int main(){
   int x;
   printf("Inserisci un intero: ");
   scanf("%d", x);
   printf("\nIntero inserito: %d \n", x);
   return 0;
}