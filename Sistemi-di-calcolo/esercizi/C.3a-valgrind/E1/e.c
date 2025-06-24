// Compilare con:
// > gcc -g -o e main.c e.c
// dove il flag "-g" serve per aggiungere informazioni di debugging
// 
// 1) Eseguire per il programma va in crash
// 2) Eseguire Valgrind sul binario:
//    > valgrind ./e
// 3) Analizzare output di Valgrind
// 4) Identificare errore del programma

#include <stdio.h>

int main(){
   int x;
   printf("Inserisci un intero: ");
   scanf("%d", x);
   printf("\nIntero inserito: %d \n", x);
   return 0;
}