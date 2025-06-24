#include <stdio.h>

int g(int x, int y) { return x + y; }
int f();

int main() {
    int res = f();
    printf("%d\n", res); // deve stampare 8
    return 0;
}