#include <stdio.h>

void swap(short* x, short* y);

int main() {
    short a = 100;
    short b = 200;
    swap(&a, &b);
    printf("a=%hd - b=%hd\n", a, b);
    return 0;
}
