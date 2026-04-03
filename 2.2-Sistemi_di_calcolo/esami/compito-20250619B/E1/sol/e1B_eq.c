// Inserire il C equivalente qui (opzionale: non concorre alla valutazione)
#include "../e1B.h"

unsigned char check(mossa* head)
{
    unsigned char bl = 0; //count
    unsigned char bh = 0; //correct
    mossa * si = head;    
    
    L:
    if (si==0) 
        goto E;
        bl++;
        unsigned char al = is_valid_move(si);
        if (al==0)
            goto A;
            bh++;
        A:
        si = si->next;
        goto L;
    
    E:;
    if (bl != bh)
        goto B;
        al = 1;
        goto C;
    B:
        al = 0;
    C:

    return al;
}
