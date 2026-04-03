#include "e1A.h"

void rc4_encrypt(unsigned char *sbox, unsigned char *pt, unsigned char *ct) 
{
    unsigned int n = 0, i = 0;
    unsigned char j = 0, rnd;

    while (*pt) {
        i = (i + 1) & 255;              // & e' l'operatore and
        j = j + sbox[i];
        rc4_helper(sbox, i, j, &rnd);
        ct[n++] = rnd ^ *pt++;          // ^ e' l'operatore xor
    }
}
