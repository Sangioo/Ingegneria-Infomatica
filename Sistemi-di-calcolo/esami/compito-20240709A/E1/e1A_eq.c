#include "e1A.h"

short* cond_compute(short* array, unsigned* cond, int n, short* out) {
    short* b = array;
    unsigned* si = cond;
    short* bp = out;
    int di = 0;

L:
    if (di >= n)
        goto E;

    if (si[di] != 0)
        goto ELSE;
    short c = b[di];
    bp[di] = c;
    goto FI;
ELSE:
    short a = compute(b[di]);
    bp[di] = a;
FI:
    di++;
    goto L;
E:
    return bp;
}