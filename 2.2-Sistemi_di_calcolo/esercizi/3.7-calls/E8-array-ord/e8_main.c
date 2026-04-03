#include <stdio.h>

int ordinati(int x, int y) {
    return x <= y;
}

unsigned f(int *v, unsigned n);

int main() {
    int v1[] = { 1, 2, 2, 4, 7 };
    int v2[] = { 1, 2, 1, 4, 7 };
    int res1 = f(v1, sizeof(v1)/sizeof(int));
    int res2 = f(v2, sizeof(v2)/sizeof(int));
    printf("%d [corretto: 1]\n", res1); // deve stampare 1
    printf("%d [corretto: 0]\n", res2); // deve stampare 0
    return 0;
}
