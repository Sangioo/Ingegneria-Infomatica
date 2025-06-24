#include "e1A.h"

unsigned transform(unsigned * array, unsigned len, unsigned *out) {
    unsigned* b = array;
    unsigned* bp = out;
    int di = 0;
    unsigned si = 0;
    unsigned a;
L:
    if (di >= len)
        goto E;

    if (si <= b[di])
        goto ELSE;
    a = average(si, di + 1);
    bp[di] = a;
    goto FI;
ELSE:
    bp[di] = b[di];
FI:
    si += b[di];
    di++;
    goto L;
E:
    a = si;
    return a;
}