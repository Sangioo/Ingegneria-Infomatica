#include "e1A.h"

unsigned char* deleetify(unsigned char* v, unsigned len) {
    unsigned char* b = v;
    unsigned di = 0;
    unsigned char* si = malloc(len);

L:
    if (di >= len)
        goto E;

    if (b[di] <= 57)
        goto ELSE;
    si[di] = b[di];
    goto FI;
ELSE:
    si[di] = deleetify_helper(b[di]);
FI:
    
    di++;
    goto L;
E:
    return si;
}