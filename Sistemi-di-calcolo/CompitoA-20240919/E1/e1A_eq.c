#include "e1A.h"

int slice(char* str, int start, int end, char* res) {
    char* b = str;
    char* si = res;
    int di = 0;
    int bp = end;
    bp -= start;
    bp--;

L:
    if (*b == '\0')
        goto E;

    if (di != start)
        goto FI;
    slice_helper(b, bp, si);
FI:
    di++;
    b++;

    goto L;
E:
    if (di >= start)
        goto F;
    bp = 0;
F:
    int a = bp;
    return a;
}