#include <stdio.h>

int f();

int score, trials;

void test(int c) {
    trials++;
    int r = f();
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    test(16);
    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}

