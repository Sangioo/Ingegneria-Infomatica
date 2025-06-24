#include <stdio.h>
#include "e3.h"

int score, trials;

void test(int a, int b, int c) {
    trials++;
	unsigned int result;
	result = counting_threads(a,b,c);
    printf("Test %d: %d == %d\n", trials, result, a*b*c);
    score += (result==(a*b*c));
    return;
}

int main() {

	test(5,10,1);
	test(3,20,5);
	test(6,6,6);

    printf("Risultato: %d/%d\n", score, trials);
    return 0;
}
