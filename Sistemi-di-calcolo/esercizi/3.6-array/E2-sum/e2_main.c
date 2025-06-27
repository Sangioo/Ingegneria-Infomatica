#include <stdio.h>

short sum(short* v, int n);

int main() {
    short v[] = { 1,2,3,4,5,6,7 };
    int n = sizeof(v)/sizeof(short);
    int res = sum(v, n);
    printf("res=%d\n", res);
    return 0;
}
