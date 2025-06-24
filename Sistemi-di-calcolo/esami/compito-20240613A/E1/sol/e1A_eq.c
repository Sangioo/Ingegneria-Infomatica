#include "../e1A.h"

unsigned char* deleetify(unsigned char* v, unsigned len)
{
    unsigned eax = len;         // len * 1
    unsigned char* edi = malloc(eax);
    unsigned char* esi = v;

    unsigned ebp = 0;

L:
    if (ebp >= len) goto E;

    unsigned char cl = esi[ebp];
    if (cl <= 57) goto C;

    edi[ebp] = cl;
    goto N;
C:
    // promozione a intero dell'argomento
    unsigned ecx = (unsigned)cl;
    // spostare ecx in stack per il passaggio dell'argomento
    unsigned char al = deleetify_helper(cl);
    edi[ebp] = al;
    
N:
    ebp += 1;
    goto L;

E:
    unsigned char* _eax = edi;
    return _eax;
}