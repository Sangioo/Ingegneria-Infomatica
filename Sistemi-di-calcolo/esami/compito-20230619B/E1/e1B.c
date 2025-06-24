#include "e1B.h"

void rc4_encrypt_rev(unsigned char *sbox, unsigned char *pt, unsigned char *ct)
{
    unsigned int i = 0;
    unsigned char j = 0, rnd;

    unsigned char *pt_aux = pt + strlen(pt) - 1;

    while (pt_aux >= pt) {
        i = (i + 1) & 255;                              // & e' l'operatore and
        j = j + sbox[i];
        *ct = rc4_helper(sbox, i, j) ^ *pt_aux--;       // ^ e' l'operatore xor
        ct++;
    }
}
