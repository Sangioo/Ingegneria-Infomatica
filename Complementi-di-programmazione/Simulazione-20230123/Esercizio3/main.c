
#include <stdio.h>
#include <stdlib.h>
#include "aux.h"


// Funzione di test
void test(int seed, int itest);


const int S33D = 1323538;

int main() {

	int TOTAL_TEST = 10;
	for(int i = 0; i <= TOTAL_TEST; i++){
		printf("> Test %d\n", i);
		test(S33D + i, i);	
		printf("\n"); 
		fflush(stdout);
	}
}

// TODO: implementare test
void test(int seed, int itest) {}