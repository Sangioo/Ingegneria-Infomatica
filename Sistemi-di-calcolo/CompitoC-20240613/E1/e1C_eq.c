#include "e1C.h"

int hextodec_sum(unsigned char *in, int *out) {
    unsigned char* b = in;
    int* bp = out;
    unsigned di = 0;
    int si = 0, res;

L:
    if (*b == 0)
        goto E;

    hextodec_helper(b, &res);

    if (res <= 0)
        goto FI;
    si += res;
FI:
    bp[di] = res;
    di++;
    b += 2;
    goto L;
E:
    return si;
}