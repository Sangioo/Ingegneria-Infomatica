#include "../e1A.h"

unsigned transform(unsigned * array, unsigned len, unsigned *out)
{
    int esi = 0;
    unsigned edi = 0;

L:
    if (esi >= len) goto E;

    unsigned eax = array[esi];

    if (edi <= eax) goto F;
    out[esi] = average(edi, esi + 1);
    goto T;

F:
    eax = array[esi];
    out[esi] = eax;
T:
    eax = array[esi];
    edi += eax;

    esi += 1;
    goto L;
E:
    return edi;
}