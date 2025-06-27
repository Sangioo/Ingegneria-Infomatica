#include <stdio.h>

int f(int x, int y);

void get_div_rem(int *d, int *r, int x, int y){
    *d = x / y;
    *r = x % y;
}

int main() {
    char a = 21, b = 3;
    int res = f(a, b);
    printf("%d\n", res); // deve stampare 7
    return 0;
}
