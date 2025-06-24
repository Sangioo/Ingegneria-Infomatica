#include <stdio.h>

int h() { return 3; }
int g() { return 10; }

int f();

int main() {
    int res = f();
    printf("%d\n", res); // deve stampare 13
    return 0;
}