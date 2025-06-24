#include <stdio.h>

int h(int x) { return x+3; }
int g(int x) { return x+1; }

int f(int x);

int main() {
    int res = f(10);
    printf("%d\n", res); // deve stampare 24
    return 0;
}