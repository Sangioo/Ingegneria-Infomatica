#include "e1B.h"

void rc4_encrypt_rev(unsigned char *sbox, unsigned char *pt, unsigned char *ct) {
    unsigned char *esi = pt;
    unsigned int eax = strlen(esi);
    esi += eax;
    esi--;
    unsigned char *ebp = ct;
    
    unsigned int edi = 0;
    unsigned char bl = 0, rnd;
L:
    if (esi < pt)
        goto E;
    
    unsigned int ecx = edi;
    ecx++;
    ecx &= 255;
    edi = ecx;

    bl += sbox[edi];
    
    unsigned char al = rc4_helper(sbox, edi, bl);
    al ^= *esi;
    *ebp = al;
    esi--;

    ebp++;

    goto L;
E:
}