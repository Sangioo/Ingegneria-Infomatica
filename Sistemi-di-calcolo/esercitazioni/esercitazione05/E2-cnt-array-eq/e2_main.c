#include <stdio.h>

int counteq(short* v1, short* v2, int n);

int score, trials;

void test(short* v1, short* v2, int n, int c) {
    trials++;
    char r = counteq(v1, v2, n);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {
    short v1[] = { 10, 20, 40, 55, 65, 70, 80, 95, 0 };
    short v2[] = { 10, 25, 40, 50, 60, 75, 80, 90, 0 };
    int n = sizeof(v1)/sizeof(short);

    test(v1, v2, n, 4);
    test(v1, v2, 0, 0);
    test(v1+3, v2+3, n-4, 1);
    test(v1+1, v2+1, n-6, 1);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}


