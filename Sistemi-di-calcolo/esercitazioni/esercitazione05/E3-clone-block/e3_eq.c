#include <stdlib.h>
#include <string.h>

void* clone(const void* src, int n) {
    const void* di = src;
    int si = n;

    void* a = malloc(si);
    int b = a;
    if (b != 0) goto E;
    a = 0;
    goto F;
E:
    memcpy(b, di, si);
    a = b;
F:
    return a;
}