#include "../e1B.h"

void rc4_encrypt_rev(unsigned char *sbox, unsigned char *pt, unsigned char *ct)
{
    // i <-> edi, j <-> bl, ct <-> esi, pt_aux <-> ebp
    unsigned int i = 0;
    unsigned char j = 0;

    int eax = strlen(pt);
    unsigned char *pt_aux = pt;
    pt_aux += eax;
    pt_aux--;

L:
    if (pt_aux < pt) goto E;

    i = i + 1;
    i = i & 255;
    
    j = j + sbox[i];
    unsigned char al = rc4_helper(sbox, i, j);
    unsigned char ah = *pt_aux;
    *ct = al;
    *ct = *ct ^ ah;
    ct++;
    pt_aux--;
    goto L;

E:;
}