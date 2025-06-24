// Compilare con:
// > gcc -g -o e main.c e.c
// dove il flag "-g" serve per aggiungere informazioni di debugging
// 
// 1) Eseguire per vedere che il programma va in crash
// 2) Eseguire Valgrind sul binario:
//    > valgrind ./e
// 3) Analizzare output di Valgrind
// 4) Identificare errore del programma

#include <stdio.h>

int main(){
	int a;
	printf("%d\n", a);
	return 0;
}
