#include <stdio.h>

int f(int x, int y);

int score, trials;

void test(int x, int y, int c) {
    trials++;
    int r = f(x,y);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    test(3,  4,  -7);
    test(4, -1,  15);
    test(7,  9, -32);
    test(11, 2, 117);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
