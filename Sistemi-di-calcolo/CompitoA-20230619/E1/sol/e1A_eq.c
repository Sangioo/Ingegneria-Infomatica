#include "../e1A.h"

void rc4_encrypt(unsigned char *sbox, unsigned char *pt, unsigned char *ct)
{
    // n <-> edi, i <-> esi, j <-> bl, pt <-> ebp
    int n = 0;
    int i = 0; 
    unsigned char j = 0;
    unsigned char rnd; // allocato in stack

L:
    if (*pt == 0) goto E;

    i = i + 1;
    i = i & 255;

    unsigned char cl = sbox[i];
    j = j + cl;

    unsigned char* eax = &rnd;
    rc4_helper(sbox, i, j, eax);

    eax = ct;
    cl = *pt;
    cl = cl ^ rnd;
    ct[n] = cl;

    n++;
    pt++;

    goto L;
E:;
}
