#include "e1B.h"

void deleetify(unsigned char* v, unsigned len, unsigned char* res) {
    unsigned char* b = v;
    unsigned char* si = res;
    unsigned di = 0;
    unsigned char chr;

L:
    if (di >= len)
        goto E;
    
    if (b[di] <= 57)
        goto ELSE;
    si[di] = b[di];
    goto FI;
ELSE:
    deleetify_helper(b[di], &chr);
    si[di] = chr;
FI:

    di++;
    goto L;
E:
    return;
}