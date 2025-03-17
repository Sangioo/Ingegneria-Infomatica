#include <stdio.h>

int min(int x, int y, int z);

int score, trials;

void test(int x, int y, int z) {
    trials++;
    int r = min(x, y, z);
    int c = x < y ? (x < z ? x : z) : (y < z ? y : z);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    test(1, 2, 3);
    test(1, 1, 2);
    test(3, 2, 1);
    test(3, 1, 2);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
