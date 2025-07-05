#include "../e1A.h"

unsigned int* div_vectors(unsigned int* a, unsigned int* b, int n) {
    if (a == NULL)
        goto E2;
    if (b == NULL)
        goto E2;
    if (n == 0)
        goto E2;
    int l = 4; // sizeof(int)
    l = l * n;
    int* out = malloc(l);
    int i = 0;
L:
    if (i >= n) goto E;
    int eax = a[i];
    int edx = 0;
    int ecx = b[i];
    eax = eax / ecx; // usare idiv
    out[i] = eax;
    i += 1;
    goto L;
E:
    int* eax2 = out;
    return eax2;
E2:
    eax2 = NULL;
    return eax2;
}
