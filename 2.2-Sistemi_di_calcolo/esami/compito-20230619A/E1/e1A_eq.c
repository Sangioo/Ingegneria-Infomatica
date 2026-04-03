#include "e1A.h"

void rc4_encrypt(unsigned char *sbox, unsigned char *pt, unsigned char *ct) {
    unsigned int edi = 0, esi = 0;
    unsigned char bl = 0, rnd;
    unsigned char *ebp = pt;
    
L:
    if (*ebp == 0)
        goto E;
    
    unsigned int eax = edi;
    eax++;
    eax &= 255;
    edi = eax;

    bl += sbox[edi];

    rc4_helper(sbox, edi, bl, &rnd);

    ct[esi] = rnd;
    ct[esi] ^= *ebp;
    esi++;
    ebp++;
    
    goto L;
E:
}