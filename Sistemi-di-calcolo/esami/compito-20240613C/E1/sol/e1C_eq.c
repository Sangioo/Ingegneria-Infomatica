#include "../e1C.h"

int hextodec_sum(unsigned char *in, int *out)
{
    int ebx = 0;
    unsigned int esi = 0;
    unsigned char* edi = in;
    int* ebp = out;
    int mem;

L:
    if (*edi == 0) goto E;
    int* ecx = &mem;
    hextodec_helper(edi, ecx);

    int eax = mem;
    if (eax <= 0) goto F;
    ebx += eax;

F:
    ebp[esi] = eax;
    esi += 1;
    edi += 2;
    goto L;

E:
    eax = ebx;
    return eax;
}