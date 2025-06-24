#include "../e1.h"

void array_div(const int *a, const int *b, div_rem_t *res, int n){
    // parms: n<->ebp, a<->edi, b<->esi, res<->ebx , ecx<->min,eax <->max
    const int *edi = a;
    const int *esi = b;
    div_rem_t *ebx = res;
    int ebp=n;
    int ecx, eax;

L:  ebp--;
    if (ebp<0) goto E;

    ecx = esi[ebp]; // min
    if (ecx > edi[ebp]) ecx = edi[ebp];

    eax = edi[ebp]; // max
    if (eax <= esi[ebp]) eax = esi[ebp];

    // free for idiv
    ebx[ebp].quot = eax / ecx;
    ebx[ebp].rem  = eax % ecx;
    goto L;
E:;
}

