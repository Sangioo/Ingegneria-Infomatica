#include "../e1A.h"

unsigned adler32(unsigned char *data, unsigned len) {
    unsigned char* esi = data;

    if (esi == NULL || len == 0)
        return 0;

    unsigned ebp = 1, edi = 0;
    
    unsigned k;
    get_addler_constant(&k);

    unsigned eax;
    int ebx = 0;
L:
    if (ebx >= len) goto E;
    eax = ebp + esi[ebx];
    unsigned edx = 0;
    unsigned ecx = k;
    ebp = eax % ecx;
    eax = edi + ebp;
    edx = 0;
    edi = eax % ecx;
    ++ebx;
    goto L;
E:
    eax = (edi << 16) | ebp;
    return eax;
}