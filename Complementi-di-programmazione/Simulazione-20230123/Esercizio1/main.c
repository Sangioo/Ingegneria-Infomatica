#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "aux.h"


// Funzioni di test
void test_all(int mat_size, int max_val, int check);

int main()
{
	srand(37899);

	int tests = 10;
	for (int i = 0; i < tests; i++){
		printf("TEST %d:\n",i+1);
		test_all(i/3 + 2, 9, i);
	}
}

// TODO: implementare testcases come nell'esame
void test_all(int mat_size, int max_val, int check) {
	
}