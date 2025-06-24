#include "../e1A.h"

short* cond_compute(short* array, unsigned* cond, int n, short* out)
{
    short* edi = out;
    unsigned* ebp = cond;
    int ebx = 0;

L:
    if (ebx >= n) goto E;

    int ecx = cond[ebx];
    if (ecx != 0) goto F;

    short* edx = array;
    short dx = array[ebx];
    edi[ebx] = dx;
    goto T;

F:
    edx = array;
    dx = array[ebx];
    edi[ebx] = compute(dx);

T:
    ebx += 1;
    goto L;

E:
    short* eax = edi;
    return eax;
}