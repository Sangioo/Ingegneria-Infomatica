#include "../e1A.h"

char* cond_compute(char* array, unsigned* cond, int n, char* out)
{
    char* edi = out;
    unsigned* ebp = cond;
    int ebx = 0;
    char res;

L:
    if (ebx >= n) goto E;

    char* edx = array;
    char dl = array[ebx];
    edi[ebx] = dl;

    int ecx = cond[ebx];
    if (ecx == 0) goto T;

    compute(dl, &res);
    edi[ebx] = res;

T:
    ebx += 1;
    goto L;

E:
    char* eax = edi;
    return eax;
}