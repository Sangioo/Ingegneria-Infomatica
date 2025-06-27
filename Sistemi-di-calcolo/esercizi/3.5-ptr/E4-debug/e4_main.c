#include <stdio.h>

void f(unsigned short n, unsigned short* spari, unsigned short* sdisp);

int main() {
    short spari;
    short sdisp;
    f(10, &spari, &sdisp);
    printf("spari=%hu - sdisp=%hu\n", spari, sdisp);
    return 0;
}
