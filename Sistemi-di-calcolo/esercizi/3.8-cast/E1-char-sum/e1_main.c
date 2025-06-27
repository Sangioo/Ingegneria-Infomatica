#include <stdio.h>

int f(char *p, char *q);

int main() {
    char a = -10, b = 20;
    int res = f(&a, &b);
    printf("%d\n", res); // deve stampare 10
    return 0;
}
