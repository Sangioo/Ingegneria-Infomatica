#include "e1A.h"

char* cond_compute(char* array, unsigned* cond, int n, char* out) {
    char* b = array;
    unsigned* bp = cond;
    char* si = out;
    int di = 0;
    char res;

L:
    if (di >= n)
        goto E;
    
    char c = b[di];
    si[di] = c;
    if (bp[di] == 0)
        goto FI;
    compute(si[di], &res);
    c = res;
    si[di] = c;
FI:
    di++;
    
    goto L;
E:
    char* a = si;
    return a;
}