// Compilare con:
// > gcc -g -o e main.c e.c
// dove il flag "-g" serve per aggiungere informazioni di debugging
// 
// 1) Eseguire per vedere che il programma viene eseguito senza andare in crash
// 2) Eseguire Valgrind sul binario:
//    > valgrind ./e
// 3) Analizzare output di Valgrind
// 4) Identificare errore del programma

#include <stdlib.h>

int main() {
	int* buf = calloc(10, sizeof(int));
	for (int i = 0; i <= 10; i++)
		buf[i] = i;
	return 0;
}
