// Compilare con:
// > gcc -g -o e main.c e.c
// dove il flag "-g" serve per aggiungere informazioni di debugging
// 
// 1) Eseguire per vedere che il risultato del programma va in crash
// 2) Avviare il debbuger GDB con:
//    > valgrind ./e
// 3) Analizzare output di Valgrind
// 4) Identificare errore del programma

#include <stdlib.h>
#include <stdio.h>

void repeat(int n) {
	for(int i = 0; i < n; i++) {
		char* s = malloc(128);
		snprintf(s, 128, "Iteration: %d", i);
		puts(s);
		free(s);
	}
}

int main(){
	repeat(100);
	char* s = "hello";
	return 0;
}
