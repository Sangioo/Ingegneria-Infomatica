#include <stdio.h>

short get(short* v, unsigned n, unsigned i);

int main() {
    short res, v[] = { 0, 10, 20, 30, 40, 50, 60, 70 };
    int n = sizeof(v)/sizeof(short);
    printf("res=%hd\n", get(v, n, 0));
    printf("res=%hd\n", get(v, n, 5));
    printf("res=%hd\n", get(v, n, 8));
    return 0;
}
