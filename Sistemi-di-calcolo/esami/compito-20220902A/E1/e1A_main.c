#include <stdio.h>
#include "e1A.h"

int compare(unsigned int* a, unsigned int* b, int n) {
    if (n <= 0) return a == b;
    if (a == NULL) return a == b;
    if (b == NULL) return 0;
    int i;
    for (i = 0; i < n; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}

void print(unsigned int* r, unsigned int n) {
    if (r == NULL) {
        printf("NULL");
        return;
    }
    printf("[");
    int i;
    for (i = 0; i < n; i++) printf(" %d", r[i]);
    printf(" ]");
}


int test(unsigned int* a, unsigned int* b, int n, unsigned int* expected) {
    unsigned int* res = div_vectors(a, b, n);
    printf("Risultato: ");
    print(res, n);
    printf(" (atteso: ");
    print(expected, n);
    int correct = compare(expected, res, n);
    printf(") => %s\n", correct ? "corretto!" : "non corretto!");
    return correct;
}

int main() {
    unsigned int a1[] = { 6 };
    unsigned int b1[] = { 3 };
    unsigned int c1[] = { 2 };
    unsigned int a2[] = { 9, 9 };
    unsigned int b2[] = { 3, 3 };
    unsigned int c2[] = { 3, 3 };
    unsigned int a3[] = { 8, 6, 16 };
    unsigned int b3[] = { 2, 3,  4 };
    unsigned int c3[] = { 4, 2,  4 };
    int score = 0;
    score += test(NULL, a1, sizeof(a1) / sizeof(unsigned int), NULL);
    score += test(a1, b1, 0, NULL);
    score += test(a1, b1, sizeof(a1) / sizeof(unsigned int), c1);
    score += test(a2, b2, sizeof(a2) / sizeof(unsigned int), c2);
    score += test(a3, b3, sizeof(a3) / sizeof(unsigned int), c3);
    printf("Punteggio: %d/%d\n", score, 5);
    return 0;
}