#include <stdio.h>

int find(int* v, int n, int x);

int score, trials;

void test(int* v, int n, int x, int c) {
    trials++;
    int r = find(v,n,x);
    printf("Test %d: %d [corretto: %d]\n", trials, r, c);
    score += r == c;
}

int main() {

    int v[] = { 2,6,8,4,23,6,12,43,2,5,4,87 };
    int n = sizeof(v)/sizeof(int);

    test(v, n, 13, 0);
    test(v, n, 5,  1);
    test(v, n, 7,  0);
    test(v, n, 43, 1);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
