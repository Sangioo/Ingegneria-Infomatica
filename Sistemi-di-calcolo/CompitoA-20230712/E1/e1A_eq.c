#include "e1A.h"

unsigned adler32(unsigned char *data, unsigned len) {
    unsigned char* ebx = data;
    unsigned eax = 0;

    if (ebx == NULL)
        goto END;
    if (len == 0)
        goto END;
    
    unsigned ebp, edx;
    get_adler_constant(&ebp);

    unsigned esi = 1, edi = 0;

    int ecx = 0;
L:
    if (ecx >= len)
        goto E;
    
    eax = esi;
    eax += ebx[ecx];
    edx = eax % ebp;
    esi = edx;

    eax = esi;
    eax += edi;
    edx = eax % ebp;
    edi = edx;
    
    ecx++;
    goto L;
E:
    eax = edi;
    eax = eax << 16;
    eax = eax | esi;
END:
    return eax;
}