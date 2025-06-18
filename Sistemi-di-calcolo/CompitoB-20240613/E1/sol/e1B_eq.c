#include "../e1B.h"

void deleetify(unsigned char* v, unsigned len, unsigned char* res)
{
    unsigned char* esi = v;
    unsigned char* edi = res;
    unsigned ebp = 0;
    unsigned char chr;          // questo va in stack

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
    deleetify_helper(cl, &chr);
    edi[ebp] = chr;
    
N:
    ebp += 1;
    goto L;

E:
    return;
}