// Inserire il C equivalente qui (opzionale: non concorre alla valutazione)
#include "../e1A.h"

unsigned char fight(pokemon* p1, pokemon* p2)
{
    
    short si = p1->pf; //pf1
    short di = p2->pf; //pf2
    char al;

    unsigned char bl = 1;
    L:
    if (bl>10)
        goto E;
        di = update(bl,p1,di);
        si = update(bl,p2,si);
        al = winner(si,di);
        if (al>=0)
            goto E;
        al = 0;

        bl++;
        goto L ;   


    E:;
    return al;
}
