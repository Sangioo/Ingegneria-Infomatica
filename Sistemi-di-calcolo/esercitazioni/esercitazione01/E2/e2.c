#include <stdio.h>
#include <stdlib.h>

unsigned int fib(unsigned int n) {
    if (n < 2) return n;
    else return fib(n - 1) + fib(n - 2);
}

unsigned int fib_iter(unsigned int n) {
    unsigned int i = 0, j = 1, k, t;
    for (k = 1; k <= n; ++k) {
        t = i + j;
        i = j;
        j = t;
    }
    return j;
}

int main() {

    unsigned int n = 10;
    unsigned int r1 = fib(n);
    unsigned int r2 = fib_iter(n);
    printf("[%u] ric: %u iter: %u\n", n, r1, r2);
    printf("Risultato: %d/%d\n", r1 == r2, 1);

    return 0;
}