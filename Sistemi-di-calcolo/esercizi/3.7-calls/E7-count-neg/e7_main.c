#include <stdio.h>

int is_negative(int x) {
    return x < 0; // restituisce 1 se x<0 e 0 altrimenti
}

unsigned f(int *v, unsigned n);

int main() {
    int v[] = { 1, -2, -4, 5, -7, 4, 5, 0 };
    int res = f(v, sizeof(v)/sizeof(int));
    printf("%u\n", res); // deve stampare 3
    return 0;
}
