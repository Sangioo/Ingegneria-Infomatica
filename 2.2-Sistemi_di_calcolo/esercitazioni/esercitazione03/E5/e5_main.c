#include <stdio.h>

int f(int a, int b);

int score, trials;

void test(int x, int y, int c) {
    trials++;
    int r = f(x, y);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    test(5, 0, 0);
    test(10, 30, 1);
    test(-10, -6, 0);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}