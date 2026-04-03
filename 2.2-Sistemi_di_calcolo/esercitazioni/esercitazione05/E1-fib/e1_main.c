#include <stdio.h>

int fib(int n);

int score, trials;

void test(int n, int c) {
    trials++;
    char r = fib(n);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    test(2, 2);
    test(3, 3);
    test(4, 5);
    test(5, 8);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}

