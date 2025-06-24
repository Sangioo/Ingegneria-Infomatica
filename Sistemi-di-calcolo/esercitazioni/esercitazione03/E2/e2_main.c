#include <stdio.h>

unsigned int fib(unsigned int n);

int score, trials;

void test(unsigned int x, unsigned int c) {
    trials++;
    int r = fib(x);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    test(1, 1);
    test(2, 1);
    test(3, 2);
    test(4, 3);
    test(5, 5);
    test(6, 8);
    test(7, 13);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
