#include <stdio.h>

int f(int x);

int score, trials;

void test(int x, int c) {
    trials++;
    int r = f(x);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    test(3, -2);
    test(4, 5);
    test(7, 50);
    test(17, 460);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
